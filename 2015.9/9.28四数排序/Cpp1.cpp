#include<stdio.h>
int main()
{
	int mid,i,n,m,t;
	int a[4];
	printf("请输入4个数字，用空格隔开:\n");
	for(i=1;i<5;i++)
		scanf("%d",&a[i]);
	
	i=1;
	while(i<5)
	{
		n=i;
		m=i+1;
		while(m<5)               //取a[n]为最大
		{
			if(a[n]<a[m])
			{
				mid=a[n];
				a[n]=a[m];
				a[m]=mid;
				m=m+1;
			}
			else m=m+1;
		}
		i++;
	}
	printf("从大到小排序如下:\n");
	for(i=1;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
