#include"stdio.h"

char a[30];

void CODE();

int main()
{
	printf("������һ���ַ�:\n");
	gets (a);
	printf("\n������ַ���Ϊ:\n");
	CODE();
	return 0;
}

void CODE()
{
	int i,j;
	for(i=0;1;i++)
	{
		if(a[i]=='\0')break;

		if(a[i]<='w'&&a[i]>='a') a[i]+=3;
		else if(a[i]>'w'&&a[i]<='z') a[i]-=23;

		if(a[i]<='D'&&a[i]>='Z') a[i]-=3;
		else if(a[i]>='A'&&a[i]<'D')a[i]+=23;
	}
	puts(a);
}

