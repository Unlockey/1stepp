#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int y=2,s,menu;


void gotoxy(int x,int y);
void MOVE();  //��W S��������ƹ�������ƶ����ո��س�ȷ��
void CLR(int);//��ɫ�任��1��2��3����
void SPRD(int clr,int i0,int i,int j0,int j);/*����������Ϳɫ
˳��Ϊ��ɫ-������ͷ-β-������ͷ-β*/

int main()
{
	/*Amax ������ޣ�grt ��������ɿ��أ�m n������ m��nС��mid ������λ

	  max �洢���ֵ��maxi�洢λ�ã�find�������֣���׺_sΪ��Ӧ����,*/
	int A[50],i,Amax=10,grt=1,m,n,mid,max,maxi,find,find_s=0,sort_s=0,i_in;
	system("mode con cols=100 lines=38");
	srand(time(0));
	while(1)
	{
//��ʼ�������============================================
		s=1;
		while(s==1)
		{
		system("cls");
		gotoxy(50,0);printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
		gotoxy(50,1);printf("�U      ��������                      �U");
		gotoxy(50,2);printf("�U      1.�������ֵ����λ����        �U");
		gotoxy(50,3);printf("�U      2.��С��������                �U");
		gotoxy(50,4);printf("�U      3.��������                    �U");
		gotoxy(50,5);printf("�U      4.���ַ���������(������)      �U");
		gotoxy(50,6);printf("�U      5.�˳�                        �U");
		gotoxy(50,7);printf("�U                                    �U");
	    gotoxy(50,8);printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
		gotoxy(56,y);
		printf("%c",16);
		for(i=0;i<Amax;i++)              
		{
			if(grt==1) {Sleep(100);A[i]=rand()%30+1;}
			CLR(3);
			gotoxy(2+4*i,36);
			printf("%d ",A[i]);
			SPRD(2,2+4*i,3+4*i,35-A[i],35);         //������ӻ�����
		}
		grt=0;
		CLR(3);
//����ʼ����������=====================================
		while(s==1)MOVE();
		grt=0;CLR(3);

		switch(menu)
		{
		case 0:{grt=1;break;}
		case 1://�������ֵ����λ����
			{
				for(i=1,max=A[0];i<Amax;i++)
					{if(max<A[i]){max=A[i];maxi=i;}}
				mid=A[0];A[0]=A[maxi];A[maxi]=mid;
				sort_s=0;//��ʾ��ǰΪ����
				break;
			}
		case 2://��С��������
			{
				for(i=0;i<Amax;i++)
				{
					for(n=i,m=i+1;m<Amax;m++)
					{   
						if(A[n]>A[m])
						{
					/*		SPRD(1,2+4*n,3+4*n,35-A[n],35);
							SPRD(1,2+4*m,3+4*m,35-A[m],35);
							Sleep(300);						//������������Ϳ��*/
							SPRD(3,2+4*n,3+4*n,35-A[n],35);
							SPRD(3,2+4*m,3+4*m,35-A[m],35);
							mid=A[n];A[n]=A[m];A[m]=mid;//����������ֵ
							gotoxy(2+4*n,36);printf("%d ",A[n]);
							gotoxy(2+4*m,36);printf("%d ",A[m]);
					/*		SPRD(1,2+4*n,3+4*n,35-A[n],35);         //���´�ӡ
							SPRD(1,2+4*m,3+4*m,35-A[m],35);			//����λ��
					Sleep(200);	*/	
							SPRD(2,2+4*n,3+4*n,35-A[n],35);		//Ϳ��
							SPRD(2,2+4*m,3+4*m,35-A[m],35);
							Sleep(500);
						}
					}
				}
				
				CLR(3);
				sort_s=1;//��ʾ��ǰ������
				break;
			}
		case 3://��������
			{
				gotoxy(53,9);printf("������Ҫ���ҵ����֣�");scanf("%d",&find);
				find_s=0;
				for(i=0;i<Amax;i++)
					if(A[i]==find){maxi=i;find_s=1;}
				break;
			}
		case 4://���ַ���������
			{
				if(sort_s==0){gotoxy(53,9);printf("����Ŀǰ��������״̬����������");menu=-1;break;}
				gotoxy(53,9);printf("������Ҫ���ҵ����֣�");scanf("%d",&find);
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
		default ://�˴�
			{
				s=0;
				break;
			}
		}//switch�ֺŽ���
//���������֡�==============================================================================
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
			printf("��Ҫ�ҵ�������%d...",find);  Sleep(2000);gotoxy(53,11);
			if(find_s==1){printf("�ڵ�%dλ��",maxi+1);SPRD(1,2+4*maxi,3+4*maxi,35-A[maxi],35);break;}
			else printf("�Ҳ�����˵���� �r(�s_�t)�q");break;}
			while(menu=5);//������������ʱbreak�������
		}
		if(menu!=5&&menu!=0)getch();
		SPRD(3,50,100,9,15);
		}//�ڲ�ѭ�����Ž���
		if(menu==5)break;
	}//���ѭ�����Ž���
	gotoxy(60,37);
		return 0;

}
//================����������=============================================================
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
//�ƶ�===============================
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
//��ɫ===============================
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
//ͿĨ==============================================
void SPRD(int clr,int i0,int i,int j0,int j)
{
	CLR(clr);
	int x,y;
	for(y=j0;y<j;y++)
		for(x=i0;x<i;x++)
		{gotoxy(x,y);
		printf(" ");}
}