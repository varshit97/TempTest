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

void preorder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    printf("%d ",root->value);
    preorder(root->left);
    preorder(root->right);
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

int multi=1;

void bfs(node *root)
{
    int var=0,flag=0;
    node *temp;
    printf("Pushed root %d\n",root->value);
    push(root);
    while(1)
    {
        if(bfsarrlen()==0)
        {
            break;
        }
        var=0;
        while(bfsarrlen()!=0)
        {
            printf("length of queue is %d\n",bfsarrlen());
            temp=pop();
            printf("Popping %d\n",temp->value);
            if(isleaf(temp)==1)
            {
                var+=temp->value;
                flag=1;
            }
            if(temp->left!=NULL)
            {
                printf("Pushed a left value %d\n",temp->left->value);
                push(temp->left);
            }
            if(temp->right!=NULL)
            {
                printf("Pushed a right value %d\n",temp->right->value);
                push(temp->right);
            }
        }
        if(flag==1)
        {
            multi*=var;
        }
    }
    return ;
}

int lheight=0,rheight=0;

void dfs(node *root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return ;
    }
    if(root->left!=NULL)
    {
        lheight+=1;
        dfs(root->left);
    }
    if(root->right!=NULL)
    {
        rheight+=1;
        dfs(root->right);
    }
}

int maxdepth()
{
    return lheight>=rheight?lheight+1:rheight+1;
}

int main()
{
    int n,i,x;
    node *root=NULL;
    node *a,*b;
    a=NULL;
    b=NULL;
    if(a==b)
    {
        printf("Yes\n");
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    printf("Inorder\n");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    dfs(root);
    printf("depth =%d\n",maxdepth());
 //   bfs(root);
 //   printf("Mul is %d\n",multi);
    return 0;
}
