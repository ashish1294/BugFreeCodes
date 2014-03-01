//http://www.spoj.com/problems/CANTON/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
	int t,s,i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s=0;
		for(i=1;;i++)
		{
			if(s+i>=n) break;
			s+=i;
		}
		i++;
		if(i%2!=0) printf("TERM %d IS %d/%d\n",n,n-s,i-n+s);
		else printf("TERM %d IS %d/%d\n",n,i-n+s,n-s);
	}
	return 0;
}
