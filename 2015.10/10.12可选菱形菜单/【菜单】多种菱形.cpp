//(����)�˵�������ĸʱ��ѭ����ʾ����
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

int main()
{
	int h,i,j,k,j2,s,menu;//jΪһ��������hΪͼ�θ߶�,menuΪ�˵�ѡ��,i�����У�s���Ʋ˵�ѭ��
	char c;
	while(1)
	{
	//�˵����֡�
		s=1;
		while(s==1)
		{
		system("cls");
		printf("�X===================================�[\n");
		printf("�U                                   �U\n");
		printf("�U      1.*������                    �U\n");
		printf("�U      2.�����ĸ����               �U\n");
		printf("�U      3.���ֶ�������ĸ����       �U\n");
		printf("�U      4.��ĸ��������               �U\n");//4.����60���Ըպÿ���һ��Ц��
		printf("�U      5.�˳�                       �U\n");
		printf("�U                                   �U\n");
	    printf("�^===================================�a\n");
		printf("��ѡ��:");
		scanf("%d",&menu);
		switch(menu)
		{
		case 1://�Զ���߶�*��
			{
				printf("������һ������:");
				scanf("%d",&h);
				k=h/2+1;
				s=0;
				break;
			}
		case 2://��ĸ���
				{
				getchar();
				printf("������һ����ĸ:");
				scanf("%c",&c);
				if(c>='a'&&c<='z')c-=32;
				k=c-64;
				s=0;
				break;
			}
		case 3://�Զ��߶���ĸ���
			{
				getchar();
				printf("������һ������:");
				scanf("%d",&h);
				k=h/2+1;
				s=0;
				break;
			}
		case 4://��ȦȦ
			{
				printf("������һ������:");
				scanf("%d",&h);
				k=h/2+1;
				s=0;
				break;
			}
		case 5:
			{
				s=0;
				break;
			}
		default:{printf("�������(�s�����)�s��ߩ���\n");Sleep(1000);printf("\n�С��Х�(��_ ���)����������");Sleep(1000);}		//����Menu���˵���֧
		}
	}
	//���岿�֡�
		if(menu!=5)
		{
			int n=2;
			for(j=1;j<=k;j++)
			{
				for(i=1;i<=k-j;i++)
					printf(" ");
				for(i=1;i<=2*j-1;i++)
				{
					if(menu==4)
					{
						if(i<=j)printf("%c",64+i);
						else {printf("%c",64+i-n);n+=2;}
					}
					else if(menu==1)printf("*");
						 else printf("%c",64+j);
					if(i==2*j-1){printf("\n");n=2;}
				}
			}
			for(j=1;j<=k-1;j++)
			{
				for(i=1;i<=j;i++)
					printf(" ");
				for(i=1;i<=2*(k-j)-1;i++)
				{
					if(menu==4)
					{
						if(i<=(k-j))printf("%c",64+i);
						else {printf("%c",64+i-n);n+=2;}
					}
					else if(menu==1)printf("*");
						 else printf("%c",64+k-j);
					if(i==2*(k-j)-1)printf("\n");
				}
				n=2;
			}
		}
		if(menu==5)break;
		getch();
		Sleep(1000);
	}
		return 0;
}
