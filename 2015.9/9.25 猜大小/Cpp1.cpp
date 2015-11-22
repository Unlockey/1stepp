//每次随机得到的数字都为42
//经过修改加入随机数种子，可以实现正常功能
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	int a,b,i,x=1,y=100;
	a=i=0;
	b=rand() % 100 +1;
	printf("猜一个1-100内的数字:");
	while(a!=b)
	{
		scanf("%d",&a);
		i++;
		if(a==b)printf("\n你猜对了！谜底就是%d.\n你用了%d次去猜中它\n",a,i);
		else if(a>b) 
		{    
			y=a;
			printf("\n%d?大了，再猜一次\n\n",a);
			printf("猜一个%d-%d内的数字:",x,y);
		}
			 else 
			 {
				 x=a;
				 printf("\n%d?小了，再猜一次\n\n",a);
				 printf("猜一个%d-%d内的数字:",x,y);
			 }
	}
	return 0;
}
