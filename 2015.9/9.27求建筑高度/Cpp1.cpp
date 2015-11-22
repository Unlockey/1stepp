#include"stdio.h"
#include"math.h"
int main()
{
	int x,y,a;
	printf("请输入坐标：x=");
	scanf("%d",&x);
	printf("            y=");
	scanf("%d",&y);

	x=sqrt(x*x);
	y=sqrt(y*y);

	a=pow(x-2,2)+pow(y-2,2);
	if(a<1||a==1) printf("\n此处建筑高度为10m。\n");
	else printf("\n此处建筑高度为0m。\n");
	
	return 0;
}