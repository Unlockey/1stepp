//�������� ��С��������
//ʹ�ò���ʽ�����㷨
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
int main()
{
	srand(time(NULL));
	int A[10]={0},B[11];
	int x,y,i,b;//xΪA�±꣬yΪB�±꣬i���ڼ�¼��λ,b���ڴ洢��ǰ��������,��s���ڿ���ѭ�����Ѹ���break
//��ʾ����
	printf("�����ȡ10������:");
	for(i=0;i<10;i++)
	{
		Sleep(200);
		A[i]=rand()%100+1;
		printf("%d ",A[i]);		
	}
	Sleep(500);
	printf("\n\n");
//���������㷨
	x=0;
	y=0;
	i=0;
	B[0]=A[0];
	while(i<10)
	{
		y=i;
		b=A[x];
		while(1)
		{
			if(B[y]>b)                //���������ݽ�Сʱ���������ݺ���
			{
				B[y+1]=B[y];
				if(y!=0)y--;
				else 
				{
					B[0]=b;
					x++;
					break;
				}
			}
			else 
			{
				B[y+1]=b;
				x++;
				break;
			}
		}
		i++;
	}
	printf("��С��������Ϊ:");
	for(i=0;i<10;i++)
	{
		Sleep(500);
		printf("%d ",B[i]);	
	}
	printf("\n");
	getch();
	return 0;
}



