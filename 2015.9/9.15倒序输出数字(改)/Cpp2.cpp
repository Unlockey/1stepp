//����һ�����֣��Ե������
//���������ʵ�ַ��������������
#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
	int a,b,c,d,x;
	printf("������һ�����֣�");          
	scanf("%d",&a);                             //��������a
	b=0;
	x=a;                                        //�����ж�����λ��
	d=a;                                        //����a��ֵ���ж��Ƿ񴥷��ʵ�
//�õ���������b
	while(a>0)
	{
		c=a%10;
		b=b*10+c;
		a=a/10;
	}
//�ж�����λ��
	int i=0;                                      
	while(x>0)
	{
		x=x/10;
		i++;                                   //�õ�����λ��i
	}
//�Ի������
	Sleep(1000);
	printf("�����㡭��\n");
	Sleep(3000);
    printf("��������һ��%dλ�� %d\n",i,d);
    Sleep(1700);
	printf("���������� ");
	printf("%d\n",b);
//�������������ʱ�����ʵ�
	if(b==d)
	{	Sleep(1800);
	    printf("������\n");
        Sleep(1300);
		printf("����\n");
		Sleep(3100);
        printf("����û���������(�s�F����)�s��ߩ���\n");
        
	}
	return 0;
}
