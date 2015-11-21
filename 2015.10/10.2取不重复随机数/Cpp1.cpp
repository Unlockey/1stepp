//取不重复的随机数
	while(i<4)
	{
		r[i]=rand()%10+1;
		j=1;
		while(j<4)
		{
			if(i==j)j++;
			else if(r[i]==r[j]||r[i]==10){i--;break;}
				 else j++;
		}
		i++;
	}