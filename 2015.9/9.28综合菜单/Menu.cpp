#include<stdio.h>
#include<windows.h>
int main()
{
	int i,x,y,a,b,c,d,s;
	//�˵�����
	printf("��ѡ������Ҫ�Ĺ���:\n");
	printf("1=====>�õ�λ��\n");
	printf("2=====>�ֱ����ÿλ����\n");
	printf("3=====>�����������\n");
	printf("4=====>�ж��Ƿ�Ϊ������\n");
	printf("5=====>�˳�\n");
	scanf("%d",&s);
	getchar();
	if(s<5&&s>0)
	{
		printf("�������������:");
		scanf("%d",&a);
	}
	//��ʼִ��
	b=0;
	x=a;                //1�����ж�����λ��
	d=a;                //4�����ж��Ƿ����
	c=a;                //3�������ÿλ����

	//1.�ж�����λ��i
	i=0;
	while(x>0)
	{
		x=x/10;
		i++;
	}
	if(s==1)
	{
		Sleep(500);
		printf("����һ��%dλ��\n",i);
	}
	//3.�õ���������b
	while(a>0)
	{
		c=a%10;
		b=b*10+c;
		a=a/10;
	}
	if(s==3)printf("����Ϊ%d\n",b);

	//4.�ж��Ƿ����
	if(s==4)
	{
		if(b==d)printf("�����ǻ�����\n");
	    else printf("�������ǻ�����\n");
	}

	//2.�ֱ������λ�ϵ�����;
	if(s==2)
	{
		printf("����λ�����ֱַ�Ϊ:\n");
		while(b>0)
		{
			Sleep(500);
			y=b%10;
			printf("%d ",y);
			b=b/10;
		}
	}
	Sleep(500);
	printf("\n");
	return 0;
}


