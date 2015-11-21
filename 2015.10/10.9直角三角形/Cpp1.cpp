#include<stdio.h>
int main()
{
	int i,n;
	for(i=1,n=1;n!=9;)
	{
		printf("*");
		if(i==n)
		{
			printf("\n");
			n++;
			i=1;
		}
		else i++;
	}
	return 0;
}

