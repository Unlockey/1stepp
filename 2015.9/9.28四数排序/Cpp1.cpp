#include<stdio.h>
int main()
{
	int mid,i,n,m,t;
	int a[4];
	printf("������4�����֣��ÿո����:\n");
	for(i=1;i<5;i++)
		scanf("%d",&a[i]);
	
	i=1;
	while(i<5)
	{
		n=i;
		m=i+1;
		while(m<5)               //ȡa[n]Ϊ���
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
	printf("�Ӵ�С��������:\n");
	for(i=1;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
