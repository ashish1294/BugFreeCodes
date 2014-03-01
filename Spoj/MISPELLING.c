//http://www.spoj.com/problems/GNY07A/
#include<stdio.h>

int main()
{
	int t,i,n,j;
	scanf("%d",&t);
	char str[100];
	for(i=1;i<=t;i++)
	{
		scanf("%d %s",&n,str);
		j=n;
		while(1)
		{
			str[j-1]=str[j];
			if(str[j]=='\0')
				break;
			j++;
		}
		printf("%d %s\n",i,str);
	}
	return 0;
}
