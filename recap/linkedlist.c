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

node *reverse(node *head)
{
    node *temp,*prev=NULL,*next;
    temp=head;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
    return head;
}
 
void deleteNode(node *nodes)
{
    node *temp;
    temp=nodes->next;
    nodes->value=temp->value;
    nodes->next=temp->next;
    free(temp);
    return ;
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
    printf("Printing normally\n");
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n");
    deleteNode(head->next->next);
    printf("After deleting\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n");
/*    printf("Printing in reverse\n");
    node *head1,*temp1;
    head1=reverse(head);
    temp1=head1;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->value);
        temp1=temp1->next;
    }
    printf("\n");*/
    return 0;
}
