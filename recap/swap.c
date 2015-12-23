#include<stdio.h>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("a=%d and b=%d before\n",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("a=%d and b=%d after\n",a,b);
    return 0;
}
