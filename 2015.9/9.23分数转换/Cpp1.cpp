//����ת�������Ͷ�Ӧ�ȼ���֧���໥ת��
#include<stdio.h>
int main()
{
	int i,s;
	char g;
	printf("��ѡ�������ͣ�\n1==>�ȼ�-�ɼ�\n2==>�ɼ�-�ȼ�\n");
	scanf("%d",&i);
	getchar();              //�������ջس�
	if (i==1)
	{
	printf("Your grade:");
	scanf("%c",&g);
	printf("Your score:");

	switch(g)
	{
	case'A':
	case'a':printf("80~100\n");break;
	case'B':
	case'b':printf("70~79\n");break;
	case'C':
	case'c':printf("60~69\n");break;
	case'D':
	case'd':printf("<60\n");break;
	default:printf("Please enter grade A-D.\n");
	}
	}
	else {printf("Your score:");
	     scanf ("%d",&s);
		 printf("Your grade:");
		 s=s/10;
		 switch(s)
		 {
		 case 10:
		 case 9:printf("A\n");break;
		 case 8:
		 case 7:printf("B\n");break;
		 case 6:printf("C\n");break;
		 default:printf("D\n");
		 }
	}
	return 0;
}
