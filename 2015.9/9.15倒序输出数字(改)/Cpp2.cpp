//输入一串数字，以倒序输出
//不用数组的实现方法相比数组更简洁
#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
	int a,b,c,d,x;
	printf("请输入一串数字：");          
	scanf("%d",&a);                             //输入数字a
	b=0;
	x=a;                                        //用于判断数字位数
	d=a;                                        //保留a的值来判断是否触发彩蛋
//得到反序数字b
	while(a>0)
	{
		c=a%10;
		b=b*10+c;
		a=a/10;
	}
//判断数字位数
	int i=0;                                      
	while(x>0)
	{
		x=x/10;
		i++;                                   //得到数字位数i
	}
//对话并输出
	Sleep(1000);
	printf("我算算……\n");
	Sleep(3000);
    printf("你输入了一个%d位数 %d\n",i,d);
    Sleep(1700);
	printf("倒过来就是 ");
	printf("%d\n",b);
//当输入回文数字时触发彩蛋
	if(b==d)
	{	Sleep(1800);
	    printf("呃……\n");
        Sleep(1300);
		printf("……\n");
		Sleep(3100);
        printf("根本没有区别嘛！！(╯‵□′)╯︵┻━┻\n");
        
	}
	return 0;
}
