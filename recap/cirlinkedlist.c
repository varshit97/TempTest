#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

node *insert(node *head,int val)
{
    if(head==NULL)
    {
        head=(node *)malloc(sizeof(node));
        head->value=val;
        head->next=NULL;
    }
    else
    {
        head->next=insert(head->next,val);   
    }
    return head;
}

int main()
{
    int n,i,x,t;
    node *head=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        head=insert(head,x);
    }
    return 0;
}
