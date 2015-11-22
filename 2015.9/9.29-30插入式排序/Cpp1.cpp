//函数功能 从小到大排序
//使用插入式排序算法
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
int main()
{
	srand(time(NULL));
	int A[10]={0},B[11];
	int x,y,i,b;//x为A下标，y为B下标，i用于记录数位,b用于存储当前插入数字,【s用于开关循环】已改用break
//显示部分
	printf("随机抽取10个数字:");
	for(i=0;i<10;i++)
	{
		Sleep(200);
		A[i]=rand()%100+1;
		printf("%d ",A[i]);		
	}
	Sleep(500);
	printf("\n\n");
//插入排序算法
	x=0;
	y=0;
	i=0;
	B[0]=A[0];
	while(i<10)
	{
		y=i;
		b=A[x];
		while(1)
		{
			if(B[y]>b)                //待插入数据较小时将组中数据后移
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
	printf("从小到大排序为:");
	for(i=0;i<10;i++)
	{
		Sleep(500);
		printf("%d ",B[i]);	
	}
	printf("\n");
	getch();
	return 0;
}



