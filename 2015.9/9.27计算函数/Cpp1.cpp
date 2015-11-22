#include<stdio.h>
#include<math.h>
int main()
{
	int x,y;
//显示并输入
	printf("  | x^2+2x-6  x<0\n");
	printf("y={ x^2-5x+6  0≤x<10，x≠2\n");
	printf("  | x^2-x-15  x≥10，x=2\n");
	printf("Please enter your X :");
	scanf("%d",&x);
//计算
	if(x>10||x==10||x==2) y=pow(x,2)-x-15;
	else if(x<0) y=pow(x,2)+2*x-6;
	     else y=pow(x,2)-5*x+6;
//输出
	printf("x=%d\ny=%d\n",x,y);
	return 0;
}
