#include"stdio.h"

int main()
{	
	int i,j;
	char a[30],b[30];
	printf("������һ���ַ�:\n");
	gets(a);
	printf("��������һ���ַ�:\n");
	gets(b);
	for(i=0;1;)
		if(a[i]!='\0')i++;
		else break;

	for(j=0;j<5;j++)
	{
		a[i]=b[j];
		if(b[j]!='\0'){i++;}
		else break;
	}
	printf("���Ӻ��ַ���Ϊ:");
	puts(a);
	return 0;
}