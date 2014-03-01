#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,n,j;
	char str[500];
	scanf("%d",&n);
	while(n!=0)
	{
		scanf("%s",str);
		int lim = strlen(str)/n;
		for(i=0;i<n;i++)
			for(j=0;j<lim;j++)
				if(j%2==0)
					printf("%c",str[(j*n)+i]);
				else
					printf("%c",str[(j*n)+n-i-1]);
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
