#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int main()
{

//��Ƭ��ʼ~
	int a,b,i,j,x,y,k;//K���ڼƴ�
	int g[4],r[4];
	srand(time(NULL));
	k=1;
	while(k==1)
	{   
		system("cls");
		y=1;
		i=j=a=0;
//ȡ���ظ������
		while(i<4)
		{
			r[i]=rand()%10+1;
			j=0;
			while(j<4)
			{
				if(i==j)j++;
				else if(r[i]==r[j]||r[i]==10){i--;break;}//���ظ�����������ȡ
					 else j++;
			}
			i++;
		}
//������
		while(a!=4)
		{
			a=b=0;
			i=1;
			printf("          ��%d�� ",y);
			scanf("%d",&x);
			y++;
//�жϲ����
			while(i<5)
			{
				j=0;
				while(j<5)
				{
					
					if(x/(int)pow(10,4-i)==r[j])
					{
						if(i==j+1)
						{
							a++;
						}
						else
						{
							b++;
						}
					}
					j++;
				}
				x=x-(int)(x/pow(10,4-i))*pow(10,4-i);
				i++;
			}
			printf("              %dA%dB\n",a,b); 
		}
	
		printf("hahahahaha00\n");
		getch();
		printf("          Again?\n          1==>Again\n          2==>Finish\n          ");
		scanf("%d",&k);
		getchar();
	}
	return 0;
}

