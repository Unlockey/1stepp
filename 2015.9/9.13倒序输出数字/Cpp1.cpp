//����һ�����֣��Ե������
//10λ�������ֻ����,10λ���ֻ����
#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
//�õ��������ֵ�λ��
	int n,a,g;
	printf("������10λ���ڵ����֣�");          
	scanf("%d",&n);                               //��������n
	g=n;                                        //����������ֻ��вʵ�~
	a=n;                                          //����n������a
	int i=0;                                      
	while(a>0)
	{
		a=a/10;
		i++;
	}
//�Ի�
	Sleep(1000);
	printf("�����㡭��\n");
	Sleep(2000);
    printf("��������һ��%dλ��%d\n",i,n);
    Sleep(1000);

//��ȡ����λ�ϵ���
    a=i;                                          //����i������a
	int num[10];                                  
	int t=0;                
    while(a>0)
	{
		t=t+1;
	    a=a-1;
		num[t]=n/pow(10,a);
		n=n-num[t]*pow(10,a);                     //��ȡ����������λ
	}
//������λ�ϵ����������
	a=0;
	while(t>0)
	{
		i=i-1;
		a=a+num[t]*pow(10,i);
		t=t-1;
	}
	printf("����������");
	printf("%d\n",a);
//��~~~~~~~~~~~~~~~~~~~~~��
	if(a==g)
	{	Sleep(2000);
	    printf("������\n");
        Sleep(1000);
        printf("����ˣ����(�s�F����)�s��ߩ���\n");
        
	}
	return 0;
}
