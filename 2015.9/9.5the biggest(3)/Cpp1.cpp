#include"stdio.h"
int main()
{
	int a,b,c,d;
	int max(int x,int y,int z);
    printf("a=");
	scanf("%d",&a);//����a
	printf("b=");       
	scanf("%d",&b);//����b
	printf("c=");
	scanf("%d",&c);//����c
    d=max(a,b,c);
	printf("max=%d\n",d);
	return 0;
}
int max(int x,int y,int z)
{
	if(x>y)y=x;
	if(z>y)y=z;
	return(y);
}
