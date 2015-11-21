#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int y=2,s,menu;


void gotoxy(int x,int y);
void MOVE();  //用W S或方向键控制光标上下移动，空格或回车确定
void CLR(int);//颜色变换，1红2灰3正常
void SPRD(int clr,int i0,int i,int j0,int j);/*给矩形区域涂色
顺序为颜色-横坐标头-尾-纵坐标头-尾*/

int main()
{
	/*Amax 输出上限，grt 随机数生成开关，m n计数器 m大n小，mid 交换数位

	  max 存储最大值，maxi存储位置，find检索数字，后缀_s为相应开关,*/
	int A[50],i,Amax=10,grt=1,m,n,mid,max,maxi,find,find_s=0,sort_s=0,i_in;
	system("mode con cols=100 lines=38");
	srand(time(0));
	while(1)
	{
//初始界面输出============================================
		s=1;
		while(s==1)
		{
		system("cls");
		gotoxy(50,0);printf("╔══════════════════╗");
		gotoxy(50,1);printf("║      重新生成                      ║");
		gotoxy(50,2);printf("║      1.交换最大值和首位数字        ║");
		gotoxy(50,3);printf("║      2.从小到大排序                ║");
		gotoxy(50,4);printf("║      3.查找数字                    ║");
		gotoxy(50,5);printf("║      4.二分法查找数字(需排序)      ║");
		gotoxy(50,6);printf("║      5.退出                        ║");
		gotoxy(50,7);printf("║                                    ║");
	    gotoxy(50,8);printf("╚══════════════════╝");
		gotoxy(56,y);
		printf("%c",16);
		for(i=0;i<Amax;i++)              
		{
			if(grt==1) {Sleep(100);A[i]=rand()%30+1;}
			CLR(3);
			gotoxy(2+4*i,36);
			printf("%d ",A[i]);
			SPRD(2,2+4*i,3+4*i,35-A[i],35);         //输出可视化数列
		}
		grt=0;
		CLR(3);
//↑初始界面输出完毕=====================================
		while(s==1)MOVE();
		grt=0;CLR(3);

		switch(menu)
		{
		case 0:{grt=1;break;}
		case 1://交换最大值和首位数字
			{
				for(i=1,max=A[0];i<Amax;i++)
					{if(max<A[i]){max=A[i];maxi=i;}}
				mid=A[0];A[0]=A[maxi];A[maxi]=mid;
				sort_s=0;//表示当前为乱序
				break;
			}
		case 2://从小到大排序
			{
				for(i=0;i<Amax;i++)
				{
					for(n=i,m=i+1;m<Amax;m++)
					{   
						if(A[n]>A[m])
						{
					/*		SPRD(1,2+4*n,3+4*n,35-A[n],35);
							SPRD(1,2+4*m,3+4*m,35-A[m],35);
							Sleep(300);						//将待交换数据涂红*/
							SPRD(3,2+4*n,3+4*n,35-A[n],35);
							SPRD(3,2+4*m,3+4*m,35-A[m],35);
							mid=A[n];A[n]=A[m];A[m]=mid;//交换两数的值
							gotoxy(2+4*n,36);printf("%d ",A[n]);
							gotoxy(2+4*m,36);printf("%d ",A[m]);
					/*		SPRD(1,2+4*n,3+4*n,35-A[n],35);         //重新打印
							SPRD(1,2+4*m,3+4*m,35-A[m],35);			//两数位置
					Sleep(200);	*/	
							SPRD(2,2+4*n,3+4*n,35-A[n],35);		//涂白
							SPRD(2,2+4*m,3+4*m,35-A[m],35);
							Sleep(500);
						}
					}
				}
				
				CLR(3);
				sort_s=1;//表示当前已排序
				break;
			}
		case 3://查找数字
			{
				gotoxy(53,9);printf("请输入要查找的数字：");scanf("%d",&find);
				find_s=0;
				for(i=0;i<Amax;i++)
					if(A[i]==find){maxi=i;find_s=1;}
				break;
			}
		case 4://二分法查找数字
			{
				if(sort_s==0){gotoxy(53,9);printf("数列目前处于乱序状态，请先排序。");menu=-1;break;}
				gotoxy(53,9);printf("请输入要查找的数字：");scanf("%d",&find);
				find_s=0;
				for(n=0,m=Amax-1;n<=m;)
				{
					mid=(m+n)/2;
					if (find<A[mid])m=mid-1;
					else if(find>A[mid])n=mid+1;
				    	 else {find_s=1;maxi=mid;break;}
				}
				break;
			}
		default ://退粗
			{
				s=0;
				break;
			}
		}//switch分号结束
//结果输出部分↓==============================================================================
		if(menu==1)
			{
				SPRD(3,0,50,0,37);
				for(i=0;i<Amax;i++)
				{
					CLR(3);
					gotoxy(2+4*i,36);
					printf("%d ",A[i]);
					SPRD(2,2+4*i,3+4*i,35-A[i],35);
				}
				CLR(3);
			}
		if(menu==3||menu==4)
		{
			do{
			Sleep(1000);
			gotoxy(53,10);
			printf("你要找的数字是%d...",find);  Sleep(2000);gotoxy(53,11);
			if(find_s==1){printf("在第%d位！",maxi+1);SPRD(1,2+4*maxi,3+4*maxi,35-A[maxi],35);break;}
			else printf("找不到的说…… ╮(╯_╰)╭");break;}
			while(menu=5);//用于数列乱序时break跳过输出
		}
		if(menu!=5&&menu!=0)getch();
		SPRD(3,50,100,9,15);
		}//内层循环括号结束
		if(menu==5)break;
	}//外层循环括号结束
	gotoxy(60,37);
		return 0;

}
//================主函数结束=============================================================
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
//移动===============================
void MOVE()
{
	char c;
	
	c=getch();
	switch(c)
	{		
	case 'w':
	case 72:
		{if(y>1){gotoxy(56,y);printf(" ");y--;gotoxy(56,y);printf("%c",16);}break;}
	case 's':
	case 80:
		{if(y<6){gotoxy(56,y);printf(" ");y++;gotoxy(56,y);printf("%c",16);}break;}
	case 13:
	case 32:{menu=y-1;s=0;break;}
	}
}
//变色===============================
void CLR(int x)
	{
    HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	switch(x)
	{
case 1 : 
	    SetConsoleTextAttribute(hOut,
	    BACKGROUND_RED |
		FOREGROUND_RED |
		FOREGROUND_BLUE |
		FOREGROUND_GREEN );break;
case 2 : SetConsoleTextAttribute(hOut,
		BACKGROUND_RED |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN );break;
case 3 : SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_BLUE |
		FOREGROUND_GREEN );break;
	}
}
//涂抹==============================================
void SPRD(int clr,int i0,int i,int j0,int j)
{
	CLR(clr);
	int x,y;
	for(y=j0;y<j;y++)
		for(x=i0;x<i;x++)
		{gotoxy(x,y);
		printf(" ");}
}