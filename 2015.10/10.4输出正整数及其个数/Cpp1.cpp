#include<stdio.h>
#include<windows.h>
int main()
{
	int i,a;
	int x[20]={0};
	i=0;
	a=0;
	printf("�����������������ÿո��������-1��β��\n");
	while(a!=-1)
	{
		scanf("%d",&a);
		if(a>0)
		{
			x[i]=a;
			i++;
		}
	}
	printf("�������� %i ����������",i);
	Sleep(1000);
	if(i==1)printf("\n���� ");
	else printf("\n�ֱ�Ϊ:");
	
	for(a=0;a!=i;a++)
	{
		if(i!=1)Sleep(500);
		printf("%d ",x[a]);
	}
	Sleep(500);
	printf("\n");
	return 0;
}
