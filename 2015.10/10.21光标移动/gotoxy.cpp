#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
int scor=0,p=0,s=0,x2=-1,y2=-1,x,y;

void gotoxy(int,int);
void MOVE();//����ƶ�
void BAIT();//�ն�
void SCOR(int);//�Ʒ�

void CLR(int);//��ɫ�任��1��2��3����
void MAP();//��ͼ�߽�
void BODR(int x0,int y0);//�߽��ж�
void SPRD(int clr,int i0,int i,int j0,int j);/*ͿĨ��ͼ��ɫ
˳��Ϊ��ɫ-������ͷ-β-������ͷ-β*/

//����������=================================================
int main()
{
	srand(time(0));
	int x0,y0;
	char c;
	SPRD(2,0,33,0,15);
	SPRD(2,40,48,1,15);
    MAP();
	SCOR(scor);
	x=1;y=1;
	while(1)
	{
		gotoxy(x,y);
		x0=x;y0=y;
		printf("%d",scor%10);//����ַ�
		if(y==y2&&x==x2){p=0;s=0;scor++;SCOR(scor);}
		BAIT();
		MOVE();
		BODR(x0,y0);
	}
	return 0;
}
//���Ƶ�ͼ=================================================
void MAP()
{
	int x1,y1;
	CLR(1);
	gotoxy(0,0);
	for(x1=0,y1=0;x1<33;x1++)
	{
		gotoxy(x1,y1);
		printf(" ");
	}
	printf(" ");
	for(y1=1;y1<15;y1++)
	{
		gotoxy(x1,y1);
		printf(" ");
	}
	for(;x1>0;x1-=1)
	{
		gotoxy(x1,y1);
		printf(" ");
	}
	for(;y1>0;y1--)
	{	
		gotoxy(x1,y1);
		printf(" ");
	}
	CLR(2);
}
//�Ʒ�
void SCOR(int n)
{
	
	gotoxy(40,1);
	printf("Score:%d",n);
}
//��������ն�
void BAIT()
{
	while(s==0)
	{
		x2=rand()%30+2;
		y2=rand()%14+1;
		if(y2!=y||x2!=x) {s=1;break;}
	}
	if(p==0)
	{
	gotoxy(x2,y2);
	printf("%c",3);  //�ն��ַ�
	p=1;
	s=1;
	}
}
//����������
void MOVE()
{
	char c;
	c=getch();
	switch(c)
	{
	case 72:
	case 'w':
		{gotoxy(x,y);printf(" ");y--;break;}
	case 80:
	case 's':
		{gotoxy(x,y);printf(" ");y++;break;}
	case 75:
	case 'a':
		{gotoxy(x,y);printf(" ");x--;break;}
	case 77:
	case 'd':
		{gotoxy(x,y);printf(" ");x++;break;}
	}
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
	}
}
//ͿĨ
void SPRD(int clr,int i0,int i,int j0,int j)
{
	CLR(clr);
	int x,y;
	for(y=j0;y<j;y++)
		for(x=i0;x<i;x++)
		{gotoxy(x,y);
		printf(" ");Sleep(5);}
}
//�߽纯��
void BODR(int x0,int y0)//x0 y0Ϊ����ֵ
{
	if(x>32||x<1)x=x0;
	if(y>14||y<1)y=y0;
}
//gotoxy
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
