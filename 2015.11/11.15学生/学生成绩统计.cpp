//ʱ�������ܷ�ͳ�ƹ�����ʱɾȥ
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<math.h>

char txt[4][6][10]={/*һ���˵� txt[0][][]*/{{"ѧ�����"},{"�γ����"},{"�˳�"}},
/*�����˵�-ѧ�� txt[1][][]*/{{"��"},{"��"},{"��"},{"����"}},
/*�����˵�-�ɼ� txt[2][][]*/{{"����"},{"���"},{"����"},{"�ߴ�"},{"�ܷ�"},{"����"}},
/*�����˵�	    txt[3][][]*/{{"�鿴"},{"�༭"},{"ƽ����"},{"����"},{"����"}}};

bool shut,level_s,stu_s[3][4]={0},sum_s;//stu_sΪ��λ���Ƿ�������ݵĿ��أ�����Ϊѧ������Ϊ��Ŀ sum_sΪ�����ܺͿ���
int x,y,x_,y_,i,j,X=0,Y=0,level=1,maxi[3],maxi_sco[5]={0};//XYΪ��׼����,y_Ϊѧ��/��Ŀ������꣬levelΪ��ǰ�˵�����
float stu[3][4]={0};
float sum[3]={0},sum_sco[5]={0},max[5]={0},max_stu[3]={0},ave[5],ave_stu[3];//_stu��׺Ϊ��ѧ��Ϊ��׼�����ݲ���,


//��������-----------------------------------------------
void gotoxy(int x,int y);
void CLR(int x);
void SPRD(int clr,int i0,int i,int j0,int j);
//���溯��-----------------------------------------------
void Arrow(int x,int y);//��ӡ���
void Menu(int m);//��ӡ�˵�
void MOVE();//������
void SELE();//���ѡ��
int Lev();//���ƹ��λ��
//�㷨����----------------------------------------------
void STU();//����-���ѧ������
void SCO();//����-����ɼ�����
float FC(bool);//���㷽��
/*void Sum_sco();*/


//������������
int main()
{
	system("mode con cols=100 lines=20");
	x=X+3;y=Y+2;
	Arrow(X+3,Y+2);
	Menu(1);
	while(!shut)
	{
		while(!shut)MOVE();
	}
	gotoxy(50,18);
	return 0;
}



//��������-----------------------------------------------------------------------------------------
//�����ת===========================================================
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

//��ɫ==============================================================
void CLR(int x)
{
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	switch(x)
	{
	case 1:SetConsoleTextAttribute(h,
			   BACKGROUND_RED|
			   BACKGROUND_BLUE|
			   BACKGROUND_GREEN);break; 
	case 2:SetConsoleTextAttribute(h,
			   FOREGROUND_RED|
			   FOREGROUND_BLUE|
			   FOREGROUND_GREEN);
	}
}
//ͿĨ=======================================================
void SPRD(int clr,int i0,int i,int j0,int j)
{
	CLR(clr);
	int x,y;
	for(y=j0;y<=j;y++)
		for(x=i0;x<i;x++)
		{gotoxy(x,y);printf(" ");}
}

//���溯��---------------------------------------------------------------------------------------
//��ӡ���==================================================
void Arrow(int x,int y)
{
	gotoxy(x,y);printf("%c",16);
}
//����ƶ�===================================================
void MOVE()
{
	char c;
	c=getch();
	switch(c)
	{
	case 72://��
		{if(y>2){gotoxy(X+x,Y+y);printf(" ");y--;Arrow(X+x,Y+y);}break;}
	case 80://��
		{if(y<Lev( )){gotoxy(X+x,Y+y);printf(" ");y++;Arrow(X+x,Y+y);}break;}
	case 13://ȷ��
	case 32:
		SELE();
	}
}
//���¿ո񡢻س�ѡ��==============================================
void SELE()
{
	switch(level)
	{
		case 1:
			if(y==4)shut=1;
			else
			{
				Menu(1);
				CLR(1);
				gotoxy(x+2,y);puts(txt[level-1][y-Y-2]);
				CLR(2);
				level++;
				X=15;Y=y;
				x=5;y=2;
				Menu(18+Y);
				Arrow(X+x,Y+y);
			}
			break;
		case 2:
			y_=y;
			if(level_s==0&&y==5){level--;SPRD(2,X+4,X+16,Y,Y+10);X=0;Y=0;x=3;y=2;Arrow(X+x,Y+y);Menu(1);break;}
			if(level_s==1&&y==7){level--;SPRD(2,X+4,X+18,Y,Y+10);X=0;Y=0;x=3;y=3;Arrow(X+x,Y+y);Menu(1);break;}
			if(level_s==1&&y_==6){break;}
			CLR(1);
			gotoxy(X+x+2,Y+y);puts(txt[level-1+level_s][y-2]);
			CLR(2);
			level++;
			Y+=y-2;y_=y;gotoxy(30,15);
			x=5;y=2;
			X=31;Menu(3);				
			Arrow(X+x,Y+2);
			break;
		case 3:
			if(y==6){level--;SPRD(2,X+4,X+65,Y,Y+12);X=15;Y=2+level_s;x=5;y=y_;Arrow(X+x,Y+y);Menu(20+level_s);break;}
			CLR(1);
			gotoxy(X+x+2,Y+y);puts(txt[level][y-2]);
			CLR(2);
			if(level_s==0)STU();
			else SCO();
	}
}
//ȷ�����߽�====================================================
int Lev( )
{
	switch(level)
	{
	case 1:
	case 2:
		if(level_s)return 7;
		else return	5;
	case 3:return 6;
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
//��ӡ�˵�=======================================================
void Menu(int m)
{
	switch(m)
	{
	case 1:
		TXT(X,X+12,Y,Y+5);
		for(i=0;i<=2;i++)
		{
			gotoxy(X+5,Y+i+2);
			puts(txt[level-1][i]);
		}break;
	case 20:
		level_s=0;
		TXT(X+3,X+12,Y,Y+7);
		for(i=0;i<=4;i++)
		{
			gotoxy(X+7,Y+i+2);
			puts(txt[level-1][i]);
		}break;
	case 21:
		level_s=1;
		TXT(X+3,X+14,Y,Y+8);
		for(i=0;i<=5;i++)
		{
			gotoxy(X+7,Y+i+2);
			puts(txt[level][i]);
		}break;
	case 3:
		TXT(X+3,X+12,Y,Y+7);
		for(i=0;i<=4;i++)
		{
			gotoxy(X+7,Y+i+2);
			puts(txt[level][i]);
		}break;
	case 31:
		TXT(X+3,X+12,Y,Y+7);
		gotoxy(X+7,Y+2);puts(txt[3][0]);
		gotoxy(X+7,Y+3);puts(txt[3][2]);
		gotoxy(X+7,Y+4);puts(txt[3][3]);
		gotoxy(X+7,Y+5);puts(txt[3][4]);
	}
}
//�㷨����----------------------------------------------------------------------------------------------------------
//����ѧ������============================================================================
void STU()
{
	TXT(X+17,X+60,Y,Y+10);
	
	switch(y)
	{
	case 2://�鿴
		SPRD(2,X+20,X+60,Y+1,Y+9);
		for(i=0;i<=3;i++)
		{
			gotoxy(X+20,Y+2+i);
			printf("%s:",txt[2][i]);
			printf("%.0f",stu[y_-2][i]);
		}
		gotoxy(X+20,Y+6);
		printf("%s:",txt[2][i]);printf("%.1f",sum[y_-2]);
		gotoxy(X+20,Y+7);
		printf("��߷�:%s %.1f��",txt[2][maxi[y_-2]],stu[y_-2][maxi[y_-2]]);
		break;
	case 3://�༭
		SPRD(2,X+20,X+60,Y+1,Y+9);
		sum[y_-2]=0;
		for(i=0;i<=4;i++)
		{
			gotoxy(X+20,Y+2+i);printf("%s:",txt[2][i]);
		}
		for(i=0;i<=3;i++)
		{
			gotoxy(X+26,Y+2+i);
			scanf("%f",&stu[y_-2][i]);
			sum[y_-2]+=stu[y_-2][i];
			if(max_stu[y_-2]<stu[y_-2][i]){max_stu[y_-2]=stu[y_-2][i];maxi[y_-2]=i;}
		}
		ave_stu[y_-2]=sum[y_-2]/4;
		gotoxy(X+26,Y+6);printf("%.1f",sum[y_-2]);
		for(i=0;i<4;i++)stu_s[y_-2][i]=1;
		break;
	case 4://��ƽ��
		for(i=0;i<=3;i++)if(stu_s[y_-2][i]==0)break;
		if(i==4){gotoxy(X+20,Y+8);printf("��ѧ��ƽ���ɼ�Ϊ:%.1f",ave_stu[y_-2]);}
		else {gotoxy(X+20,Y+8);printf("��ѧ�����޳ɼ�");}
		break;
	case 5://�󷽲�
		for(i=0;i<=3;i++)if(stu_s[y_-2][i]==0)break;
		if(i==4){gotoxy(X+20,Y+9);printf("��ѧ���ɼ��ķ���Ϊ%.1f",FC(0));}
		else {gotoxy(X+20,Y+8);printf("��ѧ�����޳ɼ�");}
		break;
	}

	gotoxy(X+x+2,Y+y);puts(txt[3][y-2]);
}
//�����γ�����================================================================================
void SCO()
{
	TXT(X+17,X+60,Y,Y+10);
	for(i=0;i<3;i++){if(max[y_-2]<stu[i][y_-2]){max[y_-2]=stu[i][y_-2];maxi_sco[y_-2]=i;}}
	switch(y)
	{
	case 2://�鿴
		SPRD(2,X+20,X+60,Y+1,Y+9);
		for(i=0;i<3;i++)
		{
			gotoxy(X+20,Y+2+i);
			printf("%s:",txt[1][i]);
			printf("%.0f",stu[i][y_-2]);
		}
		gotoxy(X+20,Y+2+i);
		printf("��߷�:%s %.1f��",txt[1][maxi_sco[y_-2]],stu[maxi_sco[y_-2]][y_-2]);
		break;
	case 3://�༭
		SPRD(2,X+20,X+60,Y+1,Y+9);
		sum[y_-2]=0;
		for(i=0;i<3;i++)
		{
			gotoxy(X+20,Y+2+i);printf("%s:",txt[1][i]);
		}
		for(i=0;i<3;i++)
		{
			gotoxy(X+26,Y+2+i);
			scanf("%f",&stu[i][y_-2]);
			sum_sco[y_-2]+=stu[i][y_-2];
			if(max[y_-2]<stu[i][y_-2]){max[y_-2]=stu[i][y_-2];maxi_sco[y_-2]=i;}
		}
		ave[y_-2]=sum_sco[y_-2]/4;
		printf("��߷�:%s %.1f��",txt[1][maxi_sco[y_-2]],stu[y_-2][maxi_sco[y_-2]]);
		for(i=0;i<3;i++)stu_s[i][y_-2]=1;
		break;
	case 4://��ƽ��
		gotoxy(X+20,Y+7);printf("�ÿ�Ŀƽ���ɼ�Ϊ:%.1f",ave[y_-2]);
		break;
	case 5://�󷽲�
		gotoxy(X+20,Y+8);printf("�ÿ�Ŀ�ɼ��ķ���Ϊ%.1f",FC(1));
		break;
	}

	gotoxy(X+x+2,Y+y);puts(txt[3][y-2]);
}
//�󷽲�====================================================================================
float FC(bool a)
{
	float stc=0,fc=0;
	if(a==0)
	{
		for(i=0;i<4;i++)
			stc+=pow(stu[y_-2][i],2);
		stc=stc/4.0;
		for(i=0;i<4;i++)
			fc+=pow(stu[y_-2][i]/4,2);
		fc=stc-fc;
	}
	else
	{
		for(i=0;i<3;i++)
			stc+=pow(stu[y_-2][i],2);
		stc=stc/i;
		for(i=0;i<4;i++)
			fc+=pow(stu[y_-2][i]/4,2);
		fc=stc-fc;
	}
	return fc;
}
/*ʱ�������ܷ�ͳ�ƹ�����ʱɾ��
void Sum_sco()
{
	TXT(X+17,X+60,Y,Y+10);
	Menu(31);
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			if(stu_s[i][j]==0)
			{
				gotoxy(X+20,Y+3);
				printf("�ɼ����ݲ���");
				getch();
				SPRD(2,X+4,X+65,Y,Y+12);
				X=15;Y=2+level_s;
				x=5;y=y_;
				Arrow(X+x,Y+y);Menu(20+level_s);
				sum_s=0;
				break;
			}
	if(sum_s)
	{
		for(i=0;i<3;i++)
			if(max[4]<sum[i])max[4]=sum[i];
		switch(y)
		{
		case 2://�鿴
			SPRD(2,X+20,X+60,Y+1,Y+9);
			for(i=0;i<3;i++)
			{
				gotoxy(X+20,Y+2+i);
				printf("%s:",txt[1][i]);
				printf("%.0f",stu[i][y_-2]);
			}
			gotoxy(X+20,Y+2+i);
			printf("��߷�:%s %.1f��",txt[1][maxi_sco[4]],stu[maxi_sco[4]][4]);
			break;
		case 3://�༭
			SPRD(2,X+20,X+60,Y+1,Y+9);
			sum[y_-2]=0;
			for(i=0;i<3;i++)
			{
				gotoxy(X+20,Y+2+i);printf("%s:",txt[1][i]);
			}
			for(i=0;i<3;i++)
			{
				gotoxy(X+26,Y+2+i);
				scanf("%f",&stu[i][y_-2]);
				sum_sco[y_-2]+=stu[i][y_-2];
				if(max[y_-2]<stu[i][4]){max[4]=stu[i][4];maxi_sco[4]=i;}
			}
			ave[y_-2]=sum_sco[y_-2]/4;
			printf("��߷�:%s %.1f��",txt[1][maxi_sco[4]],stu[y_-2][maxi_sco[4]]);
			for(i=0;i<3;i++)stu_s[i][y_-2]=1;
			break;
		case 4://��ƽ��
			{gotoxy(X+20,Y+7);printf("��ƽ���ɼ�Ϊ:%.1f",ave[4]);}
			break;
		case 5://�󷽲�
			for(i=0;i<3;i++)if(stu_s[i][y_-2]==0)break;
			if(i==3){gotoxy(X+20,Y+8);printf("�ÿ�Ŀ�ɼ��ķ���Ϊ%.1f",FC(1));}
			else {gotoxy(X+20,Y+7);printf("�ÿ�Ŀ�ɼ����ݲ���");}
			break;
		}

		gotoxy(X+x+2,Y+y);puts(txt[3][y-2]);
	}
}
*/