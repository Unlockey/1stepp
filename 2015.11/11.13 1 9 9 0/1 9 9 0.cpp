#include<stdio.h>

char spc[7]={' '};

void space(int,char *p);

int main()
{
	int x;
	char *p;
	printf("������һ����λ����:");
	scanf("%d",&x);
	space(x,p);
	for(p=spc+7;p>=spc;p--)
		printf("%c",*p);
	printf("\n");
	return 0;
}

void space(int x,char *p)
{

	for(p=spc;p<=(spc+7);p+=2)
	{
		*p=x%10+48;
		x=x/10;
	}	
}