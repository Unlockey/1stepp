#include<stdio.h>
#include"conio.h"
#include"stdlib.h"
#include<windows.h>
#include<time.h>

//���꼰���ر���
short x=50,y,menu=2,Move_s=0;
//�洢����
int hero=0,mon_1,mon_2,save,name,mons;

//��������
//===========================================================================================
void gotoxy(int x,int y);
void CLR(int);									//��ɫ�任��1��2��3����
void SPRD(int clr,int i0,int i,int j0,int j);	/*����������Ϳɫ
												   ˳��Ϊ��ɫ-������ͷ-β-������ͷ-β*/
void TXT(int x0,int x,int y0,int y);			//�������ο�
//============================================================================================
//roll����ú���

void Roll_menu();//roll��˵�
void MOVE_roll();  //����ĸ��������ƹ���ƶ����ո��س�ȷ��
void Roll();//roll���㷨
void Roll_print();//��ӡroll����
void Hero_name();
//==============================================================================================
//ս�����ú���
void Battle_menu();//��ӡս������
void MOVE_battle();//ս��ѡ�����
void Battle_print_option();//��ӡս��ѡ��
void Battle_print_Hero();//��ӡ��������
void Battle_print_txt();//��ӡս����Ϣ
void MOVE_Battle();//������
void Battle_print_Mons(int);//��ӡ����ͼ��

//��������==========================================================================================
//��ת���
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
//��ɫ
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
//ͿĨ
void SPRD(int clr,int i0,int i,int j0,int j)
{
	CLR(clr);
	int x,y;
	for(y=j0;y<=j;y++)
		for(x=i0;x<=i;x++)
		{gotoxy(x,y);printf(" ");}
	CLR(3);
}
//��ӡ�ı���
void TXT(int x0,int x,int y0,int y)
{
	int i,j;
	gotoxy(x0,y0);printf("�X");
	for(i=x0;i<=x;i+=2)printf("�T");
	printf("�[");
	for(j=y0+1;j<=y;j++){gotoxy(i+2,j);printf("�U");}
	gotoxy(i+2,j);printf("�a");
	for(;i>=x0;i-=2){gotoxy(i,j);printf("�T");}
	gotoxy(i+2,j);printf("�^");
	for(j=j-1;j>y0;j--){gotoxy(i+2,j);printf("�U");}
}

//roll�����=====================================================================================
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
//roll��˵�����
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
//roll���㷨
void Roll()
{
	menu=2;
	save=80+rand()%40;
	hero=save*10000;                   //����ΪHP 3λ AT 2λ DF 2λ
	save=rand()%40+30;
	hero=hero+save*100+(80-save);
	Roll_print();					//��ӡ���
}


//��ӡroll����
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
//�����ȡӢ����
void Hero_name()
{
	switch(name=rand()%6+1)
	{
	case 1:printf("����");break;
	case 2:printf("������");break;
	case 3:printf("������");break;
	case 4:printf("����");break;
	case 5:printf("��³���");break;
	case 6:printf("ƥ����");
	}
}
//ս������===========================================================================================
void Battle_menu()
{
	TXT(5,15,1,7);
	TXT(5,15,22,29);
	TXT(22,80,22,29);
	Battle_print_option();			//��ӡս��ѡ��
	Battle_print_Hero();			//��ӡ��������
	Battle_print_Mons(1);			//��ӡ����ͼ��
	MOVE_Battle();					//����ս�����
}
//===================================================================================================
//��ӡս��ѡ��
void Battle_print_option()
{
	gotoxy(10,24);printf("��   ��");
	gotoxy(10,25);printf("��   ��");//׼��дһ���ֺ��� �������ﲻͬ��ʾ�ı���ͬ
	gotoxy(10,26);printf("��   ��"); 
	gotoxy(10,27);printf("��   ��");
	gotoxy(10,28);printf("��   ��");
}
//��ӡ��������========================
void Battle_print_Hero()
{
	SPRD(3,10,14,2,6);
	gotoxy(9,3);
	switch(name)	//��ӡ����
	{
	case 1:printf("����");break;
	case 2:printf("������");break;
	case 3:printf("������");break;
	case 4:printf("����");break;
	case 5:printf("��³���");break;
	case 6:printf("ƥ����");
	}
	gotoxy(9,4);printf("HP: %d",hero/10000);
	gotoxy(9,5);printf("AT: %d",hero%10000/100);
	gotoxy(9,6);printf("DF: %d",hero%100);
	gotoxy(60,29);
}
//��ӡ����ͼ��
void Battle_print_Mons(int mon)
{
	int x=45,y=9;//���ƴ�ӡλ��
	switch(mon)
	{
	case 1:
		SPRD(4,x,x+10,y+3,y+5);
		SPRD(4,x+1,x+9,y+2,y+6);
		SPRD(3,x+4,x+6,y+1,y+8);
		SPRD(4,x+3,x+7,y+1,y+7);//ͷ
		SPRD(4,x+4,x+6,y+8,y+11);
		SPRD(4,x+7,x+10,y+11,y+11);
		SPRD(4,x+8,x+14,y+10,y+10);
		SPRD(4,x+12,x+16,y+9,y+9);break;
	}
}
//���ƹ��
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
//������
int main()
{
	srand(time(0));
	system("mode con cols=90 lines=33");
	Roll_menu();			//roll�����
	system("cls");
	Battle_menu();				//ս������

	return 0;
}
