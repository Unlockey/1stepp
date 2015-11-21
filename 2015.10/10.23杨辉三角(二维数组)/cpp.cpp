#include<stdio.h>

int main()
{
	int i,j;
	int a[11][12]={0};
	a[1][1]=1;
	for(i=1;i<11;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(i!=1&&j!=1)
			{
				a[i][j]=a[i-1][j]+a[i-1][j-1];
				printf("%3d",a[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
