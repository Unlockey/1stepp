#include<stdio.h>
int main()
{
	float k,sum;
	for(sum=0,k=1;k<101;k++)sum+=k;
	for(k=1;k<51;k++)sum+=(k*k);
	for(k=1;k<11;k++)sum+=(1.0/k);

	printf("%f\n",sum);

	return 0;
}


