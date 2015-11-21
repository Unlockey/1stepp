#include<stdio.h>
#include<time.h>
#include<stdlib.h>
 int main()
 {
	 srand(time(0));
	 int i,j,mai,m_d_tng;
	 int a[5][5];
	 mai=m_d_tng=0;
	 for(i=0;i<5;i++)
	 {
		 for(j=0;j<5;j++)
		 {
			 a[i][j]=rand()%100;
			 printf("%3d",a[i][j]);
			 if(i==j||i+j==4)mai+=a[i][j];
		 }
		 printf("\n");
	 }
	 printf("\n对角线和为%d\n",mai-a[2][2]);
	 printf("\n下三角形为:\n");
	 for(i=1;i<5;i++)
	 {
		 for(j=0;j<i;j++)
			 printf("%3d",a[i][j]);
		 printf("\n");
	 }
	 return 0;

 }
