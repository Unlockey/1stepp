//ÿ������õ������ֶ�Ϊ42
//�����޸ļ�����������ӣ�����ʵ����������
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	int a,b,i,x=1,y=100;
	a=i=0;
	b=rand() % 100 +1;
	printf("��һ��1-100�ڵ�����:");
	while(a!=b)
	{
		scanf("%d",&a);
		i++;
		if(a==b)printf("\n��¶��ˣ��յ׾���%d.\n������%d��ȥ������\n",a,i);
		else if(a>b) 
		{    
			y=a;
			printf("\n%d?���ˣ��ٲ�һ��\n\n",a);
			printf("��һ��%d-%d�ڵ�����:",x,y);
		}
			 else 
			 {
				 x=a;
				 printf("\n%d?С�ˣ��ٲ�һ��\n\n",a);
				 printf("��һ��%d-%d�ڵ�����:",x,y);
			 }
	}
	return 0;
}
