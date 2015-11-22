#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	int i=0;
	while(a>0)
	{
		a=a/10;
		i++;
	}
	printf("这是一个%d位数 \n",i);
	return 0;
}