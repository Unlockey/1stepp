#include<stdio.h>
int main()
{
	int h,i,j,k,j2;//jΪ�ϰ벿����j2Ϊ�°벿��hΪͼ�θ߶�
	h=5;
	k=h/2+1;
	for(j=1;j<=k;j++)
	{
		for(i=1;i<=k-j;i++)
			printf(" ");
		for(i=1;i<=2*j-1;i++)
		{
			printf("*");
			if(i==2*j-1)printf("\n");
		}
	}

	for(j2=1;j2<=k-1;j2++)
	{
		for(i=1;i<=j2;i++)
			printf(" ");
		for(i=1;i<=2*(k-j2)-1;i++)
		{
			printf("*");
			if(i==2*(k-j2)-1)printf("\n");
		}
	}
	return 0;
}

