#include<stdio.h>
int main()
{

	char g;
	printf("Your grade:");
	scanf ("%c",&g);
	printf("Your score:");
	switch(g)
	{
	case'A':
	case'a':printf("85~100\n");break;
	case'B':
	case'b':printf("70~84\n");break;
	case'C':
	case'c':printf("60~74\n");break;
	case'D':
	case'd':printf("<60\n");break;
	default:printf("Please enter grade A-D.\n");
	}
	return 0;
}
