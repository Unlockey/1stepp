//�������� ��С��������
//ʹ�ò���ʽ�����㷨
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void gotoxy(int,int);
void CLR(int);//��ɫ�任��1��2��3����
void SPRD(int clr,int i0,int i,int j0,int j);//Ĩ��ͼ��ɫ
int main()
{
	system("mode con cols=100 lines=32");
	srand(time(NULL));
	int A[10]={0},B[11];
	int x,y,i,b;//xΪA�±꣬yΪB�±꣬i���ڼ�¼��λ,b���ڴ洢��ǰ��������,
//��ʾ����
	printf("�����ȡ10������:");
	for(i=0;i<10;i++)
	{
		Sleep(100);
		A[i]=rand()%50;
		CLR(3);
		gotoxy(4*i,29);
		printf("%d ",A[i]);
		SPRD(2,4*i,4*i+1,28-A[i]/2,28);
	}
	CLR(3);
	Sleep(500);
	printf("\n\n");
//���������㷨
	x=1;
	y=0;
	i=0;
	B[0]=A[0];
	while(i<10)
	{
		y=i;
		b=A[x];
		while(1)
		{
			if(B[y]>b)                //���������ݽ�Сʱ���������ݺ���
			{
				B[y+1]=B[y];
				if(y!=0)y--;
				else 
				{
					B[0]=b;
					x++;
					break;
				}
			}
			else 
			{
				B[y+1]=b;
				x++;
				break;
			}
		}
		i++;
	}
	printf("\n��С��������Ϊ:");
	for(i=0;i<10;i++)
	{
		Sleep(200);
		CLR(3);
		gotoxy(40+4*i,29);
		printf("%d ",B[i]);
		SPRD(1,40+4*i,40+4*i+1,28-B[i]/2,28);
	}
	printf("\n");
	getch();
	return 0;
}

//gotoxy
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
		printf(" ");}
}