//时间问题总分统计功能暂时删去
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<math.h>

char txt[4][6][10]={/*一级菜单 txt[0][][]*/{{"学生情况"},{"课程情况"},{"退出"}},
/*二级菜单-学生 txt[1][][]*/{{"甲"},{"乙"},{"丙"},{"后退"}},
/*二级菜单-成绩 txt[2][][]*/{{"素描"},{"编程"},{"高数"},{"线代"},{"总分"},{"后退"}},
/*三级菜单	    txt[3][][]*/{{"查看"},{"编辑"},{"平均分"},{"方差"},{"后退"}}};

bool shut,level_s,stu_s[3][4]={0},sum_s;//stu_s为该位置是否存在数据的开关，横向为学生纵向为科目 sum_s为分数总和开关
int x,y,x_,y_,i,j,X=0,Y=0,level=1,maxi[3],maxi_sco[5]={0};//XY为基准坐标,y_为学生/科目编号坐标，level为当前菜单级数
float stu[3][4]={0};
float sum[3]={0},sum_sco[5]={0},max[5]={0},max_stu[3]={0},ave[5],ave_stu[3];//_stu后缀为以学生为基准的数据操作,


//基本函数-----------------------------------------------
void gotoxy(int x,int y);
void CLR(int x);
void SPRD(int clr,int i0,int i,int j0,int j);
//界面函数-----------------------------------------------
void Arrow(int x,int y);//打印光标
void Menu(int m);//打印菜单
void MOVE();//光标控制
void SELE();//光标选择
int Lev();//限制光标位置
//算法函数----------------------------------------------
void STU();//输入-输出学生数据
void SCO();//输入-输出成绩数据
float FC(bool);//计算方差
/*void Sum_sco();*/


//可怜的主函数
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



//基础函数-----------------------------------------------------------------------------------------
//光标跳转===========================================================
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

//变色==============================================================
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
//涂抹=======================================================
void SPRD(int clr,int i0,int i,int j0,int j)
{
	CLR(clr);
	int x,y;
	for(y=j0;y<=j;y++)
		for(x=i0;x<i;x++)
		{gotoxy(x,y);printf(" ");}
}

//界面函数---------------------------------------------------------------------------------------
//打印光标==================================================
void Arrow(int x,int y)
{
	gotoxy(x,y);printf("%c",16);
}
//光标移动===================================================
void MOVE()
{
	char c;
	c=getch();
	switch(c)
	{
	case 72://上
		{if(y>2){gotoxy(X+x,Y+y);printf(" ");y--;Arrow(X+x,Y+y);}break;}
	case 80://下
		{if(y<Lev( )){gotoxy(X+x,Y+y);printf(" ");y++;Arrow(X+x,Y+y);}break;}
	case 13://确定
	case 32:
		SELE();
	}
}
//按下空格、回车选择==============================================
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
//确定光标边界====================================================
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
//打印文本框======================================================
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
//打印菜单=======================================================
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
//算法函数----------------------------------------------------------------------------------------------------------
//操作学生数据============================================================================
void STU()
{
	TXT(X+17,X+60,Y,Y+10);
	
	switch(y)
	{
	case 2://查看
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
		printf("最高分:%s %.1f分",txt[2][maxi[y_-2]],stu[y_-2][maxi[y_-2]]);
		break;
	case 3://编辑
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
	case 4://求平均
		for(i=0;i<=3;i++)if(stu_s[y_-2][i]==0)break;
		if(i==4){gotoxy(X+20,Y+8);printf("该学生平均成绩为:%.1f",ave_stu[y_-2]);}
		else {gotoxy(X+20,Y+8);printf("该学生尚无成绩");}
		break;
	case 5://求方差
		for(i=0;i<=3;i++)if(stu_s[y_-2][i]==0)break;
		if(i==4){gotoxy(X+20,Y+9);printf("该学生成绩的方差为%.1f",FC(0));}
		else {gotoxy(X+20,Y+8);printf("该学生尚无成绩");}
		break;
	}

	gotoxy(X+x+2,Y+y);puts(txt[3][y-2]);
}
//操作课程数据================================================================================
void SCO()
{
	TXT(X+17,X+60,Y,Y+10);
	for(i=0;i<3;i++){if(max[y_-2]<stu[i][y_-2]){max[y_-2]=stu[i][y_-2];maxi_sco[y_-2]=i;}}
	switch(y)
	{
	case 2://查看
		SPRD(2,X+20,X+60,Y+1,Y+9);
		for(i=0;i<3;i++)
		{
			gotoxy(X+20,Y+2+i);
			printf("%s:",txt[1][i]);
			printf("%.0f",stu[i][y_-2]);
		}
		gotoxy(X+20,Y+2+i);
		printf("最高分:%s %.1f分",txt[1][maxi_sco[y_-2]],stu[maxi_sco[y_-2]][y_-2]);
		break;
	case 3://编辑
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
		printf("最高分:%s %.1f分",txt[1][maxi_sco[y_-2]],stu[y_-2][maxi_sco[y_-2]]);
		for(i=0;i<3;i++)stu_s[i][y_-2]=1;
		break;
	case 4://求平均
		gotoxy(X+20,Y+7);printf("该科目平均成绩为:%.1f",ave[y_-2]);
		break;
	case 5://求方差
		gotoxy(X+20,Y+8);printf("该科目成绩的方差为%.1f",FC(1));
		break;
	}

	gotoxy(X+x+2,Y+y);puts(txt[3][y-2]);
}
//求方差====================================================================================
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
/*时间问题总分统计功能暂时删除
void Sum_sco()
{
	TXT(X+17,X+60,Y,Y+10);
	Menu(31);
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			if(stu_s[i][j]==0)
			{
				gotoxy(X+20,Y+3);
				printf("成绩数据不足");
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
		case 2://查看
			SPRD(2,X+20,X+60,Y+1,Y+9);
			for(i=0;i<3;i++)
			{
				gotoxy(X+20,Y+2+i);
				printf("%s:",txt[1][i]);
				printf("%.0f",stu[i][y_-2]);
			}
			gotoxy(X+20,Y+2+i);
			printf("最高分:%s %.1f分",txt[1][maxi_sco[4]],stu[maxi_sco[4]][4]);
			break;
		case 3://编辑
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
			printf("最高分:%s %.1f分",txt[1][maxi_sco[4]],stu[y_-2][maxi_sco[4]]);
			for(i=0;i<3;i++)stu_s[i][y_-2]=1;
			break;
		case 4://求平均
			{gotoxy(X+20,Y+7);printf("总平均成绩为:%.1f",ave[4]);}
			break;
		case 5://求方差
			for(i=0;i<3;i++)if(stu_s[i][y_-2]==0)break;
			if(i==3){gotoxy(X+20,Y+8);printf("该科目成绩的方差为%.1f",FC(1));}
			else {gotoxy(X+20,Y+7);printf("该科目成绩数据不足");}
			break;
		}

		gotoxy(X+x+2,Y+y);puts(txt[3][y-2]);
	}
}
*/