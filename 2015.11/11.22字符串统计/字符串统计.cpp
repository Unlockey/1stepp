#include"stdio.h"
char str[50];
int wod=1,let=0,num=0,oth=0;
void count(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')let++;
		else if(str[i]==' '&&str[i+1]!=' ')wod++;
		else if(str[i]>='0'&&str[i]<='9')num++;
		else oth++;
	}
}
int main()
{
	printf("please enter your string:");
	gets(str);
	count(str);
	printf("You have %d words, %d letters, %d numbers and %d others\n",wod,let,num,oth);
	printf("Totoal: %d\n",let+num+oth);
	return 0;
}