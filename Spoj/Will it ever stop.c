//http://www.spoj.com/problems/WILLITST/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
long long N;
while(scanf("%lld",&N)!=EOF)
{
	if((N&(N-1))==0) printf("TAK\n");
	else printf("NIE\n");
}
return(0);
}
