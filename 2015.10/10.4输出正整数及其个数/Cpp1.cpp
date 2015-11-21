#include<stdio.h>
#include<windows.h>
int main()
{
	int i,a;
	int x[20]={0};
	i=0;
	a=0;
	printf("请输入若干整数，用空格隔开，以-1结尾。\n");
	while(a!=-1)
	{
		scanf("%d",&a);
		if(a>0)
		{
			x[i]=a;
			i++;
		}
	}
	printf("你输入了 %i 个正整数。",i);
	Sleep(1000);
	if(i==1)printf("\n它是 ");
	else printf("\n分别为:");
	
	for(a=0;a!=i;a++)
	{
		if(i!=1)Sleep(500);
		printf("%d ",x[a]);
	}
	Sleep(500);
	printf("\n");
	return 0;
}
