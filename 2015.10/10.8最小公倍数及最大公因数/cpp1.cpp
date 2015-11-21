#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int x,y,i,j,k,l;
	 //菜单显示
	while(1)
	{
		system("cls");
		printf("====这====是====菜====单======\n");
		printf("|                            |\n");
		printf("|    1.求最小公倍数          |\n");
		printf("|    2.求最大公因数          |\n");
		printf("|    3.都要=°ω°=          |\n");
		printf("|    4.退出                  |\n");
		printf("|                            |\n");
		printf("==============================\n");
		printf("\n请选择:");
		scanf("%d",&l);
		if(l>0&&l<5)break;
		else
		{
			printf("哎哟，输入错误。(╯°□°)╯︵┻━┻\n");
			printf("\n┬—┬ノ(°_ °ノ)请再输入一次\n");
			Sleep(1500);
		}
	}

	if(l!=4)
	{//输入
		printf("请输入两个数字:\n");
		printf("X=");
		scanf("%d",&x);
		printf("Y=");
		scanf("%d",&y);
	//计算
		if(y>x)
		{
			i=x;
			x=y;
			y=i;
		}
	
		i=x*y;
		while(y!=0)
		{
			j=x%y;
			x=y;
			y=j;
		}
		k=i/x;
		switch(l)
		{
		case 1:printf("\n最小公倍数为 %d\n",k);break;
		case 2:printf("\n最大公因数为 %d\n",x);break;
		case 3:printf("\n最小公倍数为 %d",k);printf("\n最大公因数为 %d\n",x);break;
		}
		getch();
	}
		return 0;
	}
	





