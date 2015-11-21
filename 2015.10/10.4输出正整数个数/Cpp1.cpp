//以-1结尾 输出正整数个数
#include<stdio.h>
int main()
{
	int a,b;
	b=0;
	while(1)
	{
		scanf("%d",&a);
		if(a>0)
			b++;
		if(a==-1)
		{break;}
	}
	printf("%d\n",b);
	return 0;
}
