#include<stdio.h>
int main()
{
	int x,y;
	for(x=1,y=1;y!=10;)
	{
		printf("%d��%d=%d ",x,y,x*y);
		if(x==2&&y==3||x==2&&y==4)printf(" ");//����λ��
		if(x==y)
		{
			printf("\n");
			y++;
			x=1;
		}
		else x++;
	}
	return 0;
}
		
