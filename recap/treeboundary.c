#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
}node;

node *insert(node *root,int val)
{
    if(root==NULL)
    {
        root=(node *)malloc(sizeof(node));
        root->value=val;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        if(val<root->value)
        {
            root->left=insert(root->left,val);
        }
        else if(val>root->value)
        {
            root->right=insert(root->right,val);
        }
    }
    return root;
}

void inorder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left);
    printf("%d ",root->value);
    inorder(root->right);
}

int front=0,back=0;
node *bfsarr[100];

void push(node *root)
{
    bfsarr[back]=root;
    back++;
    return ;
}

node *pop()
{
    int x=front;
    front++;
    return bfsarr[x];
}

int bfsarrlen()
{
    return back-front;
}

int leaf[10];

int isleaf(node *root)
{
    if(root->right==NULL && root->left==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int boundarypoints[100],vis[100]={0},var=0;

void bfs(node *root)
{
    node *temp;
    push(root);
    while(bfsarrlen()!=0)
    {
        temp=pop();
        if(isleaf(temp)==1 && vis[temp->value]==0)
        {
            boundarypoints[var]=temp->value;
            var++;
        }
        if(temp->left!=NULL)
        {
            push(temp->left);
        }
        if(temp->right!=NULL)
        {
            push(temp->right);
        }
    }
    return ;
}

void boundary(node *root)
{
    node *temp=root,*temp1=root;
    boundarypoints[var]=root->value;
    vis[root->value]=1;
    var++;
    temp=temp->left;
    while(temp->left!=NULL)
    {
        boundarypoints[var]=temp->value;
        vis[temp->value]=1;
        var++;
        temp=temp->left;
    }
    bfs(root);
    temp1=temp1->right;
    while(temp1->right!=NULL)
    {
        boundarypoints[var]=temp1->value;
        vis[temp1->value]=1;
        var++;
        temp1=temp1->right;
    }
    return ;
}

int main()
{
    int n,i,x,mul=1;
    node *root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    for(i=0;i<100;i++)
    {
        boundarypoints[i]=0;
    }
    boundary(root);
    printf("The boundary points are :\n");
    for(i=0;boundarypoints[i]!=0;i++)
    {
        printf("%d ",boundarypoints[i]);
    }
    printf("\n");
    return 0;
}
