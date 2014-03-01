//http://www.spoj.com/problems/PIHU1/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
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
int ar[1005];
int main()
{
	int n,t=inp(),i;
	while(t--)
	{
		n=inp();
		for(i=0;i<n;i++) a[i]=inp();

	}
	return 0;
}
