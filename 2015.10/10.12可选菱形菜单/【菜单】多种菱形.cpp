//(求助)菜单输入字母时会循环提示错误
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

int main()
{
	int h,i,j,k,j2,s,menu;//j为一半行数，h为图形高度,menu为菜单选项,i控制列，s控制菜单循环
	char c;
	while(1)
	{
	//菜单部分↓
		s=1;
		while(s==1)
		{
		system("cls");
		printf("╔===================================╗\n");
		printf("║                                   ║\n");
		printf("║      1.*号菱形                    ║\n");
		printf("║      2.层叠字母菱形               ║\n");
		printf("║      3.数字定义层叠字母菱形       ║\n");
		printf("║      4.字母环绕菱形               ║\n");//4.输入60可以刚好看到一个笑脸
		printf("║      5.退出                       ║\n");
		printf("║                                   ║\n");
	    printf("╚===================================╝\n");
		printf("请选择:");
		scanf("%d",&menu);
		switch(menu)
		{
		case 1://自定义高度*号
			{
				printf("请输入一个数字:");
				scanf("%d",&h);
				k=h/2+1;
				s=0;
				break;
			}
		case 2://字母层叠
				{
				getchar();
				printf("请输入一个字母:");
				scanf("%c",&c);
				if(c>='a'&&c<='z')c-=32;
				k=c-64;
				s=0;
				break;
			}
		case 3://自定高度字母层叠
			{
				getchar();
				printf("请输入一个数字:");
				scanf("%d",&h);
				k=h/2+1;
				s=0;
				break;
			}
		case 4://绕圈圈
			{
				printf("请输入一个数字:");
				scanf("%d",&h);
				k=h/2+1;
				s=0;
				break;
			}
		case 5:
			{
				s=0;
				break;
			}
		default:{printf("输入错误(╯°□°)╯︵┻━┻\n");Sleep(1000);printf("\n┬—┬ノ(°_ °ノ)请重新输入");Sleep(1000);}		//函数Menu作菜单分支
		}
	}
	//主体部分↓
		if(menu!=5)
		{
			int n=2;
			for(j=1;j<=k;j++)
			{
				for(i=1;i<=k-j;i++)
					printf(" ");
				for(i=1;i<=2*j-1;i++)
				{
					if(menu==4)
					{
						if(i<=j)printf("%c",64+i);
						else {printf("%c",64+i-n);n+=2;}
					}
					else if(menu==1)printf("*");
						 else printf("%c",64+j);
					if(i==2*j-1){printf("\n");n=2;}
				}
			}
			for(j=1;j<=k-1;j++)
			{
				for(i=1;i<=j;i++)
					printf(" ");
				for(i=1;i<=2*(k-j)-1;i++)
				{
					if(menu==4)
					{
						if(i<=(k-j))printf("%c",64+i);
						else {printf("%c",64+i-n);n+=2;}
					}
					else if(menu==1)printf("*");
						 else printf("%c",64+k-j);
					if(i==2*(k-j)-1)printf("\n");
				}
				n=2;
			}
		}
		if(menu==5)break;
		getch();
		Sleep(1000);
	}
		return 0;
}
