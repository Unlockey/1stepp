#include<stdio.h>
#include<windows.h>
int main()
{
	int i,x,y,a,b,c,d,s;
	//菜单界面
	printf("请选择你需要的功能:\n");
	printf("1=====>得到位数\n");
	printf("2=====>分别输出每位数字\n");
	printf("3=====>输出逆序数字\n");
	printf("4=====>判断是否为回文数\n");
	printf("5=====>退出\n");
	scanf("%d",&s);
	getchar();
	if(s<5&&s>0)
	{
		printf("请输入你的数字:");
		scanf("%d",&a);
	}
	//开始执行
	b=0;
	x=a;                //1用于判断数字位数
	d=a;                //4用于判断是否回文
	c=a;                //3用于输出每位数字

	//1.判断数字位数i
	i=0;
	while(x>0)
	{
		x=x/10;
		i++;
	}
	if(s==1)
	{
		Sleep(500);
		printf("这是一个%d位数\n",i);
	}
	//3.得到反序数字b
	while(a>0)
	{
		c=a%10;
		b=b*10+c;
		a=a/10;
	}
	if(s==3)printf("逆序为%d\n",b);

	//4.判断是否回文
	if(s==4)
	{
		if(b==d)printf("该数是回文数\n");
	    else printf("该数不是回文数\n");
	}

	//2.分别输出数位上的数字;
	if(s==2)
	{
		printf("各数位上数字分别为:\n");
		while(b>0)
		{
			Sleep(500);
			y=b%10;
			printf("%d ",y);
			b=b/10;
		}
	}
	Sleep(500);
	printf("\n");
	return 0;
}


