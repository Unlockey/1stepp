#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<math.h>

bool erro=0,chos_in=0,chos_out=0,shut=0;
int x0=15,ipt,opt,in,out,*p_in,*p_out;
int x,y=7,i;
int O[30]={-1};
char txt[4][9]={{"ʮ����"},{"������"},{"�˽���"},{"ʮ������"}};

//��������------------------------------------------------------------------------

void gotoxy(int x,int y);
void MOVE();  //��W S��������ƹ�������ƶ����ո��س�ȷ��
void Arrow();//��ӡ���
void CLR(int);//��ɫ�任��1��2��3����
void TXT(int x0,int x,int y0,int y);//��ӡ�ı���
void no_TXT(int x0,int x,int y0,int y);//�����ı���
void Menu(int);//��ӡ�˵�
void SPRD(int clr,int i0,int i,int j0,int j);/*����������Ϳɫ
˳��Ϊ��ɫ-������ͷ-β-������ͷ-β*/

//�㷨����------------------------------------------------------------------------

void CODE();
void Trans(int,int);//m����תn����
void turn(int *p);//���˵�ѡ����ת��Ϊ��Ӧ����

//---------------------------------------------------------------------------------

//��ת��굽ָ������==================================================
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
//�ƶ�===============================================================
void MOVE()
{
	char c;
	c=getch();
	switch(c)
	{		
	case 72://��
		{if(y>7){gotoxy(x0,y);printf(" ");y--;Arrow();}break;}
	case 80://��
		{if(y<11){gotoxy(x0,y);printf(" ");y++;Arrow();}break;}
	case 77://��
		{
		if(x0==15)
			{
			gotoxy(x0,y);printf(" ");
			x0=45;Arrow();
			no_TXT(10,30,5,12);TXT(40,60,5,12);
			gotoxy(0,0);
			}
		break;
		}
	case 75://��
		{
		if(x0==45)
			{
			gotoxy(x0,y);printf(" ");
			x0=15;Arrow();
			no_TXT(40,60,5,12);TXT(10,30,5,12);
			gotoxy(0,0);
			}
		break;
		}
	case 13:
	case 32:
		{
			if(y==11)shut=1;
			if(x0==15&&y!=11)
			{
				Menu(2);
				CLR(2);
				gotoxy(x0+2,y);puts(txt[y-7]);
				CLR(3);
				chos_in=1;in=y-7;
			}
			else if(y!=11)
			{
				Menu(3);
				CLR(2);
				gotoxy(x0+2,y);puts(txt[y-7]);
				CLR(3);
				chos_out=1;out=y-7;
			}
			break;
		}
	}
}
//��ӡ���==================================================
void Arrow()
{
	gotoxy(x0,y);printf("%c",16);
}
//��ɫ========================================================
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
//��ӡ�ı���======================================================
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
//�����ı���=====================================================
void no_TXT(int x0,int x,int y0,int y)
{
	int i,j;
	gotoxy(x0,y0);
	for(i=x0;i<=x+4;i++)printf(" ");
	for(j=y0+1;j<=y;j++){gotoxy(i,j);printf(" ");}
	for(;i>=x0;i--){gotoxy(i,j);printf(" ");}
	for(j=j-1;j>y0;j--){gotoxy(i+2,j);printf(" ");}
}
//��ӡ�˵�======================================================
void Menu(int m)
{
	int i=17,j=7;
	switch(m)
	{
	case 1:
	case 2://��ӡ���ѡ��
		gotoxy(i,j);puts(txt[0]);
		gotoxy(i,j+1);printf("������");
		gotoxy(i,j+2);printf("�˽���");
		gotoxy(i,j+3);printf("ʮ������");
		gotoxy(i,j+4);printf("�˳�");
		if(m!=1)break;
	case 3://��ӡ�Ҳ�ѡ��
		gotoxy(i+30,j);puts(txt[0]);
		gotoxy(i+30,j+1);printf("������");
		gotoxy(i+30,j+2);printf("�˽���");
		gotoxy(i+30,j+3);printf("ʮ������");
		gotoxy(i+30,j+4);printf("�˳�");
		break;
	case 4://��ӡ����
		TXT(10,30,5,12);
		TXT(10,60,2,3);
		TXT(10,60,14,18);
		gotoxy(20,3);printf("����");gotoxy(50,3);printf("���");
		break;
	case 5://��ӡ�������
		gotoxy(30,4);printf("����������");
		gotoxy(60,20);printf("123321");
		TXT(25,40,5,6);
		gotoxy(27,6);


	}
}
//ͿĨ=======================================================
void SPRD(int clr,int i0,int i,int j0,int j)
{
	CLR(clr);
	int x,y;
	for(y=j0;y<j;y++)
		for(x=i0;x<i;x++)
		{gotoxy(x,y);printf(" ");}
}


//��������-----------------------------------------------------------------------------------------------
//�㷨����



//ת���˵���Ϊ��Ӧ������==========================================
void turn(int *p)
{
	switch(*p)
	{
		case 0:*p=10;break;
		case 1:*p=2;break;
		case 2:*p=8;break;
		case 3:*p=16;
	}
}

//ת����������===================================================
void Trans(int in,int out)
{
	char a[30];	
	int  b[30],m,n;
	ipt=opt=0;
	gotoxy(13,15);printf("������Ҫת��������:");gets(a);
	//תΪʮ����
	for(i=0;a[i]!='\0';i++);
	m=n=i-1;

	for(i=0;i<=m;i++)
	{
		if(a[i]>='0'&&a[i]<='9')ipt=ipt+(a[i]-48)*(int)pow(in,n);
		else if(a[i]>='a'&&a[i]<='f'){a[i]-=32;ipt+=(a[i]-55)*(int)pow(in,n);}
			 else ipt+=(a[i]-55)*(int)pow(in,n);
		
		n--;
	}
	//תΪ��ѡ����
	for(i=0;ipt>0;i++)
	{b[i]=ipt%out;ipt=ipt/out;}
	gotoxy(13,16); printf("��%d����ת��Ϊ%d����",in,out);
	Sleep(1000);
	gotoxy(13,18); printf("���Ϊ:");
	for(i--;i>=0;i--)
	{
		if(b[i]>9)printf("%c",b[i]+55);
		else printf("%d",b[i]);
	}

}
//��������========================================================
void CODE()
{
	bool pas=0;
	int i,j=3;
	char pass[7]={"123321"},code[6];
	while(!shut&&!pas)
	{
		system("cls");
		Menu(5);
		for(i=0;i<=5;)
		{
			code[i]=getch();
			if(code[i]!=8&&code[i]!=77&&code[i]!=80&&code[i]!=72&&code[i]!=75)//��ֹ�����
			{printf("*");i++;}
			else if(i!=0){printf("%c %c",8,8);i--;}//�����˸��ɾ��
		}
		//��������Ƿ���ȷ
		for(i=5;i>=0;i--)
		{
			if(pass[i]!=code[i])
			{
				j--;
				gotoxy(25,8);
				if(j!=0)printf("��������㻹��%d�λ���",j);
				else printf("��������˳�����");
				getch();
				break;
			}
			else if(i==0)
			{
				pas=1;Sleep(500);
				gotoxy(25,8);printf("������ȷ");Sleep(1000);
				gotoxy(25,9);printf("���ڼ��ؽ��桭��");Sleep(1000);
				system("cls");
			}
		}
		if(j==0)shut=1;
	}
}


//������==============================================================================================
int main()
{
	p_in=&in;
	p_out=&out;
	system("mode con cols=80 lines=22");
	CODE();//��������
	if(!shut)
	{
		Menu(4);//��ӡ����
		Menu(1);//��ӡѡ��
		Arrow();//��ӡ���
		gotoxy(0,0);
	}
	while(!shut)
	{
		while(!shut)
		{
			shut=0;
			MOVE();
			if(chos_in==1&&chos_out==1)
			{
				//ת�����Ʋ����
				turn(p_in);turn(p_out);
				Trans(in,out);
				getch();
				//���ÿ��ؼ�����ȴ���һ�β���
				chos_in=chos_out=0;
				SPRD(3,13,50,15,19);
				Menu(1);
				break;
			}
		}
	}
	gotoxy(50,20);
	return 0;
}
//�������==========================================================================================