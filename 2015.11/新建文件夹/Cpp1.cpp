#include<stdio.h>
#include"conio.h"
#include"stdlib.h"
#include<windows.h>
#include<time.h>

//坐标及开关变量
short x=50,y,menu=2,Move_s=0;
//存储变量
int hero=0,mon_1,mon_2,save,name,mons;

//基础函数
//===========================================================================================
void gotoxy(int x,int y);
void CLR(int);									//颜色变换，1红2灰3正常
void SPRD(int clr,int i0,int i,int j0,int j);	/*给矩形区域涂色
												   顺序为颜色-横坐标头-尾-纵坐标头-尾*/
void TXT(int x0,int x,int y0,int y);			//画出矩形框
//============================================================================================
//roll点调用函数

void Roll_menu();//roll点菜单
void MOVE_roll();  //用字母或方向键控制光标移动，空格或回车确定
void Roll();//roll点算法
void Roll_print();//打印roll点结果
void Hero_name();
//==============================================================================================
//战斗调用函数
void Battle_menu();//打印战斗界面
void MOVE_battle();//战斗选项控制
void Battle_print_option();//打印战斗选项
void Battle_print_Hero();//打印勇者数据
void Battle_print_txt();//打印战斗信息
void MOVE_Battle();//光标控制
void Battle_print_Mons(int);//打印怪物图形

//基础函数==========================================================================================
//跳转光标
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
//变色
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
	case 4 : SetConsoleTextAttribute(hOut,
			BACKGROUND_GREEN );break;
	}
}
//涂抹
void SPRD(int clr,int i0,int i,int j0,int j)
{
	CLR(clr);
	int x,y;
	for(y=j0;y<=j;y++)
		for(x=i0;x<=i;x++)
		{gotoxy(x,y);printf(" ");}
	CLR(3);
}
//打印文本框
void TXT(int x0,int x,int y0,int y)
{
	int i,j;
	gotoxy(x0,y0);printf("╔");
	for(i=x0;i<=x;i+=2)printf("═");
	printf("╗");
	for(j=y0+1;j<=y;j++){gotoxy(i+2,j);printf("║");}
	gotoxy(i+2,j);printf("╝");
	for(;i>=x0;i-=2){gotoxy(i,j);printf("═");}
	gotoxy(i+2,j);printf("╚");
	for(j=j-1;j>y0;j--){gotoxy(i+2,j);printf("║");}
}

//roll点界面=====================================================================================
void Roll_menu()
{
	TXT(20,70,10,19);
	gotoxy(x,18);printf("%c",16);
	gotoxy(52,18);printf("Reroll");
	gotoxy(62,18);printf("Start!");
	Roll();
	while(1)
	{
		MOVE_roll();
		if(menu==0)break;
		else if(menu==1)Roll();
	}
}
//roll点菜单控制
void MOVE_roll()
{
	char c;
	
	c=getch();
	switch(c)
	{		
	case 'a':
	case 75:
		{x=50;gotoxy(60,18);printf(" ");gotoxy(50,18);printf("%c",16);gotoxy(0,0);break;}
	case 'd':
	case 77:
		{x=60;gotoxy(50,18);printf(" ");gotoxy(60,18);printf("%c",16);gotoxy(0,0);break;}
	case 13:
	case 32:{if(x==60)menu=0;
			 else menu=1;
			 break;}
	}
}
//roll点算法
void Roll()
{
	menu=2;
	save=80+rand()%40;
	hero=save*10000;                   //数据为HP 3位 AT 2位 DF 2位
	save=rand()%40+30;
	hero=hero+save*100+(80-save);
	Roll_print();					//打印结果
}


//打印roll点结果
void Roll_print()
{
	SPRD(3,22,35,11,16);
	gotoxy(28,13);Hero_name();
	gotoxy(28,14);printf("HP: %d",hero/10000);
	gotoxy(32,15);printf("ATK: %d",hero%10000/100);
	gotoxy(36,16);printf("DEF: %d",hero%100);
	gotoxy(0,0);
	Sleep(500);
}
//随机读取英雄名
void Hero_name()
{
	switch(name=rand()%6+1)
	{
	case 1:printf("莱安");break;
	case 2:printf("克里夫多");break;
	case 3:printf("安莉娜");break;
	case 4:printf("勇者");break;
	case 5:printf("杜鲁尼克");break;
	case 6:printf("匹萨罗");
	}
}
//战斗界面===========================================================================================
void Battle_menu()
{
	TXT(5,15,1,7);
	TXT(5,15,22,29);
	TXT(22,80,22,29);
	Battle_print_option();			//打印战斗选项
	Battle_print_Hero();			//打印勇者数据
	Battle_print_Mons(1);			//打印怪物图像
	MOVE_Battle();					//控制战斗光标
}
//===================================================================================================
//打印战斗选项
void Battle_print_option()
{
	gotoxy(10,24);printf("攻   击");
	gotoxy(10,25);printf("咒   文");//准备写一个字函数 根据人物不同显示文本不同
	gotoxy(10,26);printf("防   御"); 
	gotoxy(10,27);printf("道   具");
	gotoxy(10,28);printf("逃   跑");
}
//打印勇者数据========================
void Battle_print_Hero()
{
	SPRD(3,10,14,2,6);
	gotoxy(9,3);
	switch(name)	//打印名称
	{
	case 1:printf("莱安");break;
	case 2:printf("克里夫多");break;
	case 3:printf("安莉娜");break;
	case 4:printf("勇者");break;
	case 5:printf("杜鲁尼克");break;
	case 6:printf("匹萨罗");
	}
	gotoxy(9,4);printf("HP: %d",hero/10000);
	gotoxy(9,5);printf("AT: %d",hero%10000/100);
	gotoxy(9,6);printf("DF: %d",hero%100);
	gotoxy(60,29);
}
//打印怪物图像
void Battle_print_Mons(int mon)
{
	int x=45,y=9;//控制打印位置
	switch(mon)
	{
	case 1:
		SPRD(4,x,x+10,y+3,y+5);
		SPRD(4,x+1,x+9,y+2,y+6);
		SPRD(3,x+4,x+6,y+1,y+8);
		SPRD(4,x+3,x+7,y+1,y+7);//头
		SPRD(4,x+4,x+6,y+8,y+11);
		SPRD(4,x+7,x+10,y+11,y+11);
		SPRD(4,x+8,x+14,y+10,y+10);
		SPRD(4,x+12,x+16,y+9,y+9);break;
	}
}
//控制光标
void MOVE_Battle()
{
	char c;
	x=8;
	y=24;
	gotoxy(x,y);printf("%c",16);
	while(Move_s==0)
	{
		c=getch();
		switch(c)
		{		
		case 'w':
		case 72:
			{if(y>24){gotoxy(x,y);printf(" ");y--;gotoxy(x,y);printf("%c",16);gotoxy(0,0);}break;}
		case 's':
		case 80:
			{if(y<28){gotoxy(x,y);printf(" ");y++;gotoxy(x,y);printf("%c",16);gotoxy(0,0);}break;}
		case 13:
		case 32:Move_s=1;break;
		}
	}
}
//主函数
int main()
{
	srand(time(0));
	system("mode con cols=90 lines=33");
	Roll_menu();			//roll点界面
	system("cls");
	Battle_menu();				//战斗界面

	return 0;
}
