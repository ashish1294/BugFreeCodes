//http://www.spoj.com/problems/PIHU1/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<algorithm>
//Fast Input
inline int inp()
{
    register int noRead=0;
    register char p=getchar_unlocked();
    //register char p=getc(stdin);
    for(;p<48 || p>57;p=getchar_unlocked());
    //for(;p<48 || p>57;p=getc(stdin));
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
int main()
{
	int n,t=inp(),i,f,p,j;
	while(t--)
	{
		n=inp();
		int ar[n];
		for(i=0;i<n;i++) ar[i]=inp();
		p=inp();
		std::sort(ar,ar+n);
		for(i=0,f=1;i<n-2;i++)
			for(j=i+1;j<n-1;j++)
			{
				if(std::binary_search(ar+j+1,ar+n,p-ar[i]-ar[j])) f=0;
			}
		if(f==1) puts("NO");
		else puts("YES");
	}
	return 0;
}
