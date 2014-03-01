//http://www.spoj.com/problems/STAMPS/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<algorithm>
inline int inp()
{
    register int noRead=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked());
    for(;p<48 || p>57;p=getc(stdin));
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
int arr[1010];
int main()
{
	int t,n,bur,ans,sum,i,j;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		bur=inp();n=inp();ans=0;sum=0;
		for(i=0;i<n;i++) arr[i]=inp();
		std::sort(arr,arr+n);
		for(i=n-1;i>=0;i--)
		{
			ans++;
			sum+=arr[i];
			if(sum>=bur) break;
		}
		if(sum>=bur) printf("Scenario #%d:\n%d\n\n",j,ans);
		else printf("Scenario #%d:\nimpossible\n\n",j);
	}
	return 0;
}
