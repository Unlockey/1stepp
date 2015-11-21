#include<stdio.h>
#include<windows.h>
int main()
{
	int i,k;
	for(i=1,k=1;k<201;k++)
	{
		if(k%10==6&&k%3==0)
		{
			Sleep(500);
			printf("%d ",k);
			if(i%5==0)printf("\n");
			i++;
		}
	}
	printf("\n");
	return 0;
}
				

