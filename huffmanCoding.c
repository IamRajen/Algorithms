//
//  huffmanCoding.c
//  
//
//  Created by Rajendra mishra on 09/10/18.
//

#include "huffmanCoding.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int length,ascii,count=0,j=0,temp;
    printf("enter the length of the string to be encoded: ");
    scanf("%d",&length);
    char string[length];
    scanf("%s",string);
    int* frequency=(int*) malloc(128*sizeof(int));
    for(int i=0;i<length;i++)
    {
        ascii=string[i];
        if(*(frequency+ascii)==0)
        {
            count++;
        }
        *(frequency+ascii)+=1;
        
    }
    int characters[count][2];
    for(int i=0;i<128;i++)
    {
        if(*(frequency+i)!=0)
        {
            characters[j][0]=i;
            characters[j][1]=*(frequency+i);
            printf("%d %d\n",characters[j][0],characters[j][1]);
            j++;
        }
    }
    
    //arranging character table in sorted form...
    for(int i=0;i<count-1;i++)
    {
        for(int j=i+1;j<count;j++)
        {
            if(characters[i][1]>characters[j][1])
            {
                temp=characters[i][1];
                characters[i][1]=characters[j][1];
                characters[j][1]=temp;
                temp=characters[i][0];
                characters[i][0]=characters[j][0];
                characters[j][0]=temp;
            }
        }
    }
    
    int treeArray[count*3][2],p=0,formedLeaf[count];j=0;
    for(int i=0;i<count;i++)
    {
        //printf("%d\n",j);
        if(i==0)
        {
            treeArray[j][1]=p;
            formedLeaf[p++]=j;
            treeArray[j++][0]= characters[i][1]+characters[i+1][1];
            treeArray[j++][0]= characters[i][1];
            treeArray[j++][0]= characters[i+1][1];i++;
            
        }
        else
        {
            int flag=0;
            for(int k=j-3;k>=0;k-=3)
            {
                if(treeArray[k][0]>characters[i][1] && treeArray[k][0]>characters[i+1][1])
                {
                    treeArray[j][1]=p-1;
                    formedLeaf[p++]=j;
                    //printf("\n%d %d\n",treeArray[k],i);
                    treeArray[j++][0]= characters[i][1]+characters[i+1][1];
                    treeArray[j++][0]= characters[i][1];
                    treeArray[j++][0]= characters[i+1][1];i++;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("%d\n",treeArray[j-3][1]);
                formedLeaf[treeArray[j-3][1]]=-1;
                formedLeaf[p++]=j;
                treeArray[j][0]=treeArray[j-3][0]+characters[i][1];
                treeArray[j+1][0]= treeArray[j-3][0];
                treeArray[j+2][0]= characters[i][1];
                j+=3;
                
            }
        }
    }
    
    
    for(int i=0;i<p-1;i++)
    {
        if(formedLeaf[i]!=-1)
        {
            if(treeArray[formedLeaf[i]][0]>treeArray[formedLeaf[i+1]][0])
            {
                temp=formedLeaf[i];
                formedLeaf[i]=formedLeaf[i+1];
                formedLeaf[i+1]=temp;
            }
        }
        printf("%d ",formedLeaf[i+1]);
    }
    
    for(int i=0;i<count;i++)
    {
        if(formedLeaf[i]!=-1)
        {
            formedLeaf[p++]=
        }
    }
}
