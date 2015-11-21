#include"stdio.h"
#include"stdlib.h"
#include"time.h"


void swap(int,int);

int main()
{
	srand(time(0));
	int max=0,i,j,m,n;
	int a[5][5];
	
	//输出数组并找到最大放在左上角
	for(i=0;i<5;i++)
	{
		 for(j=0;j<5;j++)
		 {
			 a[i][j]=rand()%100;
			 printf("%3d",a[i][j]);
			 if(max<a[i][j]){max=a[i][j];m=i;n=j;}
		 }
		 printf("\n");
	}
	max=a[m][n];a[m][n]=a[0][0];a[0][0]=max;
	//找到第二大，放在右上角
	for(i=0,max=0;i<5;i++)
	{
		 for(j=0;j<5;j++)
		 {
			 if(max<a[i][j]&&(i+j)!=0){max=a[i][j];m=i;n=j;}
		 }
	}
	max=a[m][n];a[m][n]=a[0][4];a[0][4]=max;
	//找到第三大放左下角
	for(i=0,max=0;i<5;i++)
	{
		 for(j=0;j<5;j++)
		 {
			if(i==0&&j==4)continue;
			if(max<a[i][j]&&(i+j)!=0){max=a[i][j];m=i;n=j;}
		 }
	}
	max=a[m][n];a[m][n]=a[4][0];a[4][0]=max;
	//找到第四大放右下角
	for(i=0,max=0;i<5;i++)
	{
		 for(j=0;j<5;j++)
		 {
			if(i==0&&j==4||i==4&&j==0)continue;
			if(max<a[i][j]&&(i+j)!=0){max=a[i][j];m=i;n=j;}
		 }
	}
	max=a[m][n];a[m][n]=a[4][4];a[4][4]=max;
	//输出
	printf("处理后矩阵为:");
	printf("\n\n");
	for(i=0;i<5;i++)
	{
		 for(j=0;j<5;j++)
		 {
			 printf("%3d",a[i][j]);
		 }
		 printf("\n");
	}
	return 0;
}