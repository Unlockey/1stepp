#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int x,y,i,j,k,l;
	 //�˵���ʾ
	while(1)
	{
		system("cls");
		printf("====��====��====��====��======\n");
		printf("|                            |\n");
		printf("|    1.����С������          |\n");
		printf("|    2.���������          |\n");
		printf("|    3.��Ҫ=��ء�=          |\n");
		printf("|    4.�˳�                  |\n");
		printf("|                            |\n");
		printf("==============================\n");
		printf("\n��ѡ��:");
		scanf("%d",&l);
		if(l>0&&l<5)break;
		else
		{
			printf("��Ӵ���������(�s�����)�s��ߩ���\n");
			printf("\n�С��Х�(��_ ���)��������һ��\n");
			Sleep(1500);
		}
	}

	if(l!=4)
	{//����
		printf("��������������:\n");
		printf("X=");
		scanf("%d",&x);
		printf("Y=");
		scanf("%d",&y);
	//����
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
		case 1:printf("\n��С������Ϊ %d\n",k);break;
		case 2:printf("\n�������Ϊ %d\n",x);break;
		case 3:printf("\n��С������Ϊ %d",k);printf("\n�������Ϊ %d\n",x);break;
		}
		getch();
	}
		return 0;
	}
	





