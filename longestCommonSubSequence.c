//
//  longestCommonSubSequence.c
//  
//
//  Created by Rajendra mishra on 08/10/18.
//

#include "longestCommonSubSequence.h"
#include<stdio.h>

int main()
{
    int n,m;
    printf("enter the length of the strings: ");
    scanf("%d%d",&n,&m);
    int arr[n+1][m+1];
    char string1[n],string2[m];
    printf("enter the strings: \n");
    scanf("%s%s",string1,string2);
    for(int i=0;i<=n;i++)
    {
        arr[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        arr[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(string1[i-1]==string2[j-1])
            {
                arr[i][j]=1+arr[i-1][j-1];
            }
            else{
                arr[i][j]=(arr[i-1][j]>=arr[i][j-1]?arr[i-1][j]:arr[i][j-1]);
            }
        }
    }
    
    for(int i=0;i<=n;i++)
    {
        printf("\n");
        for(int j=0;j<=m;j++)
        {
            printf("%d ",arr[i][j]);
        }
    }
    int i=n,j=m,number;
    while(1)
    {
        number=arr[i][j];
        if(number==arr[i-1][j])
        {
            i--;
        }
        else if(number==arr[i][j-1])
        {
            j--;
        }
        else{
            printf("%c ",string1[i-1]);
            i--;j--;
        }
        if(arr[i][j]==0)
            break;
    }
    return 0;
    
}
