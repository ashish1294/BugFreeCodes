//http://www.spoj.com/problems/EIGHTS/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
	int t,r;
	long long int cube,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&k);
		cube = ((k-1)/4)*1000;
		r=(k-1)%4;
		if(r==0) cube +=192;
		else if(r==1) cube+=442;
		else if(r==2) cube+=692;
		else cube+=942;
		printf("%lld\n",cube);
	}
	return 0;
}
