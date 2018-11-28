//
//  knapsackProblemUsingSetFormat.c
//  
//
//  Created by Rajendra mishra on 06/10/18.
//

#include "knapsackProblemUsingSetFormat.h"
#include<stdio.h>
#include<stdlib.h>
struct node {
    int profit,weight;
    struct node *next;
    struct node *prev;
};

//create the temporary and 2*length() size node...
struct node* createNode()
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->next=NULL;
    link->prev=NULL;
    link->profit=0;
    link->weight=0;
    return link;
}

struct node *head = NULL;
struct node *current = NULL;
struct node *position=NULL;
int capacity;

//inserting the data in the main linked list...
void insert(int weight,int profit)
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->weight=weight;
    link->profit=profit;
    link->next=NULL;
    link->prev=NULL;
    if(head==NULL)
    {
        head=link;
    }
    else
    {
        struct node *ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=link;
        link->prev=ptr;
    }
}

//printing the profit and weight of the main linked list....
void print()
{
    current=head;
    printf("Products details you entered:\n");
    while(current!=NULL)
    {
        printf("%d %d\n",current->profit,current->weight);
        
        current=current->next;
    }
    printf("\n");
}

//finding the length of the main linked list...
int length()
{
    current=head;
    int count=0;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}
int length1(struct node* current)
{
    int count=0;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}

//adding the value in the list....
struct node* addValues(struct node* current,struct node* mainNode)
{
    //position=head;
    struct node *addr=mainNode;
    mainNode->profit=current->profit+position->profit;
    mainNode->weight=current->weight+position->weight;
    while(current->next!=NULL)
    {
        current=current->next;
        if(current->weight+position->weight<=capacity)
        {
            mainNode->next=createNode();
            mainNode->next->profit=current->profit+position->profit;
            mainNode->next->weight=current->weight+position->weight;
            mainNode->next->prev=mainNode;
            mainNode=mainNode->next;
        }
    }
    position=position->next;
    return addr;
}

//appending the list....
struct node* appendValues(struct node *currentPrevList,struct node *currentNextList,struct node *currentNode)
{
    struct node *addr=currentNode;
    currentNode->profit+=currentPrevList->profit;
    currentNode->weight+=currentPrevList->weight;
    while(currentPrevList->next!=NULL)
    {
        currentPrevList=currentPrevList->next;
        current=createNode();
        current->profit=currentPrevList->profit;
        current->weight=currentPrevList->weight;
        current->prev=currentNode;
        currentNode->next=current;
        currentNode=currentNode->next;
    }
    do{
        currentNode->next=createNode();
        currentNode->next->profit=currentNextList->profit;
        currentNode->next->weight=currentNextList->weight;
        currentNode->next->prev=currentNode;
        currentNode=currentNode->next;
        currentNextList=currentNextList->next;
    }while(currentNextList!=NULL);
    return addr;
}

//sorting the formed sets...
struct node* sort(struct node* current)
{
    struct node* addr=current;
    int n,temp,i,j;
    n=length1(current);
    //printf("%d\n",n);
    for(i=0;i<n-1;i++)
    {
        current=addr;
        for(j=n-1;j>i;j--)
        {
            if(current->profit>current->next->profit)
            {
                temp=current->profit;
                current->profit=current->next->profit;
                current->next->profit=temp;
                temp=current->weight;
                current->weight=current->next->weight;
                current->next->weight=temp;
                
            }
            current=current->next;
        }
    }
    return addr;
}

//making sets...
struct node* makeSet(struct node* current)
{
    struct node* addr=current;
    int flag=0;
    while(current->next->next!=NULL)
    {
        flag=0;
        if(current->profit==current->next->profit && current->weight==current->next->weight)
        {
            current->next=current->next->next;
            flag=1;
        }
        if(flag==0)
        {
            current=current->next;
        }
    }
    if(current->profit==current->next->profit && current->weight==current->next->weight && current->next->next==NULL)
    {
        current->next=NULL;
    }
    return addr;
}

//printing the all linked list...
void printAll(struct node* heads[])
{
    printf("\n");
    for(int i=0;i<length()*2+1;i++)
    {
        printf("values of %dth set:\n",i);
        current=heads[i];
        do{
            printf("%d %d\t",current->profit,current->weight);
            current=current->next;
        }while(current!=NULL);
        printf("\n");
    }
}

//deleting unwanted set...
struct node* deleteUnWantedsets(struct node* current)
{
    struct node* addr=current;
    struct node* current1=NULL;
    int flag=0;
    while(current->next->next!=NULL)
    {
        flag=0;
        if(current->profit<=current->next->profit && current->weight>current->next->weight)
        {
            flag=1;
            current1=current->prev;
            current->prev->next=current->next;
            current=current1;
        }
        if(flag==0)
        {
            current=current->next;
        }
    }
    if(current->profit>=current->next->profit && current->weight<current->next->weight && current->next->next==NULL)
    {
        current->prev->next=NULL;
    }
    return addr;
}

//putting the values or forming the set ...
void putValues(struct node* heads[])
{
    position=head;
    for(int i=1;i<length()*2+1;i++)
    {
        if(i%2!=0)
        {
            heads[i]=addValues(heads[i-1],heads[i]);
        }
        else if(i%2==0){
            heads[i]=appendValues(heads[i-2],heads[i-1],heads[i]);
            heads[i]=sort(heads[i]);
            heads[i]=makeSet(heads[i]);
            heads[i]=deleteUnWantedsets(heads[i]);
        }
    }
    printAll(heads);
    printf("\n");
}

//final result...
void result(struct node* heads[] , int n)
{
    printf("products which will give you maximum profit will be:\n");
    struct node* current=heads[n-1];
    int flag=0;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    int maxProfit=current->profit,maxWeight=current->weight;
    for(int i=n-3;i>=0;i-=2)
    {
        current=heads[i];
        flag=0;
        while(current!=NULL)
        {
            if(current->profit==maxProfit && current->weight==maxWeight)
            {
                flag=1;
                break;
            }
            current=current->next;
        }
        if(flag==0)
        {
            printf("product %d \n",(i+2)/2);
            current=head;
            for(int j=0;j<i/2;j++)
            {
                current=current->next;
            }
            maxProfit-=current->profit;
            maxWeight-=current->weight;
        }
    }
}

//main function()....
int main()
{
    int profit,weight;
    printf("enter the profit and weight respectively of each product:- \n\nenter -1 -1 to exit\n\n");
    while(1)
    {
        scanf("%d%d",&profit,&weight);
        if(profit!=-1 && weight!=-1)
        {
            insert(weight,profit);
        }
        else{
            break;
        }
    }
    printf("enter the maximum capacity:- ");
    scanf("%d",&capacity);
    printf("\n");
    print();
    int n=length()*2+1;
    struct node *heads[n];
    for(int i=0;i<n;i++)
    {
        heads[i]=createNode();
        //printf("%d %d\t",heads[i]->weight,heads[i]->profit);
    }
    putValues(heads);
    result(heads,n);
    return 0;
}
