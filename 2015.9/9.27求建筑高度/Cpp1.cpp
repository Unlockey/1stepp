#include"stdio.h"
#include"math.h"
int main()
{
	int x,y,a;
	printf("���������꣺x=");
	scanf("%d",&x);
	printf("            y=");
	scanf("%d",&y);

	x=sqrt(x*x);
	y=sqrt(y*y);

	a=pow(x-2,2)+pow(y-2,2);
	if(a<1||a==1) printf("\n�˴������߶�Ϊ10m��\n");
	else printf("\n�˴������߶�Ϊ0m��\n");
	
	return 0;
}