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
	printf("����һ��%dλ�� \n",i);
	return 0;
}