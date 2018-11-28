#include<stdio.h>
int max(int a,int b)
{
    return (a>=b?a:b);
}
int main()
{
    int n,temp,maxProfit=0,row,remainingProfit;
    printf("Number of product:- ");
    scanf("%d",&n);
    int profit[n],weight[n],capacity;
    printf("Profits of n products: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&profit[i]);
    }
    printf("Weight of n products: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&weight[i]);
    }
    printf("Max capacity : ");
    scanf("%d",&capacity);
    int resultMatrics[n+1][capacity+1];
    // sorting the required arrays according to the profit...
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(profit[i]>profit[j])
            {
                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;
            }
        }
    }
    //putting values in the table....
    for(int i=0;i<=capacity;i++)
    {
        resultMatrics[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        resultMatrics[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=capacity;j++)
        {
            if(j<weight[i-1])
            {
                resultMatrics[i][j]=resultMatrics[i-1][j];
            }
            else if(j==weight[i-1])
            {
                resultMatrics[i][j]=profit[i-1];
            }
            else
                resultMatrics[i][j]=max(resultMatrics[i-1][j],(resultMatrics[i-1][j-weight[i-1]]+profit[i-1]));
            if(maxProfit<resultMatrics[i][j])
            {
                maxProfit=resultMatrics[i][j];
                row=i;
            }
        }
    }
   
    //selection of product to get the maximum profit.....
    remainingProfit=maxProfit-profit[row-1];
    printf("\nWeight of the Product to be selected to get the maximum profit are: \n%d ",weight[row-1]);
    int flag=0,selectedRow;
    while(remainingProfit>0)
    {
        for(int i=row-1;i>0;i--)
        {
            for(int j=1;j<=capacity;j++)
            {
                if(resultMatrics[i][j]==remainingProfit)
                {
                    selectedRow=i;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                flag=0;
                continue;
            }
            else{
                printf("%d ",weight[selectedRow-1]);
                remainingProfit-=profit[selectedRow-1];
            }
            if(remainingProfit==0)
            {
                break;
            }
        }
    }
    printf("\n\n");
}
