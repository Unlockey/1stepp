//输入一串数字，以倒序输出
//10位以上数字会归零,10位数字会出错
#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
//得到输入数字的位数
	int n,a,g;
	printf("请输入10位以内的数字：");          
	scanf("%d",&n);                               //输入数字n
	g=n;                                        //输入回文数字会有彩蛋~
	a=n;                                          //备份n到数字a
	int i=0;                                      
	while(a>0)
	{
		a=a/10;
		i++;
	}
//对话
	Sleep(1000);
	printf("我算算……\n");
	Sleep(2000);
    printf("你输入了一个%d位数%d\n",i,n);
    Sleep(1000);

//提取各个位上的数
    a=i;                                          //备份i到数字a
	int num[10];                                  
	int t=0;                
    while(a>0)
	{
		t=t+1;
	    a=a-1;
		num[t]=n/pow(10,a);
		n=n-num[t]*pow(10,a);                     //提取过后消除该位
	}
//将各个位上的数倒序输出
	a=0;
	while(t>0)
	{
		i=i-1;
		a=a+num[t]*pow(10,i);
		t=t-1;
	}
	printf("倒过来就是");
	printf("%d\n",a);
//彩~~~~~~~~~~~~~~~~~~~~~蛋
	if(a==g)
	{	Sleep(2000);
	    printf("呃……\n");
        Sleep(1000);
        printf("你在耍我吗！(╯‵□′)╯︵┻━┻\n");
        
	}
	return 0;
}
