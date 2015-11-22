#include<stdio.h>
int main()
{
	int b,i;
	char a[20];
// ‰»Î
	printf("Please enter your password:");
	a[20]=0;
	i=1;
	while(i<22)
	{
	a[i]=getchar()+4;
	if(a[i]==14)break;
	i++;
	}

// ‰≥ˆ
	printf("Your code is ");
	b=1;
	while(b<i)
	{
		printf("%c",a[b]);
		b++;
	}
	printf("\n");
	return 0;
}
	
