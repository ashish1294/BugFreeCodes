//http://www.spoj.com/problems/TWOSQRS/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<math.h>
long long int ar[1000010];
inline int linp()
{
    register long long int noRead=0;
    register char p=getchar_unlocked();
    //register char p=getc(stdin);
    for(;p<48 || p>57;p=getchar_unlocked());
    //for(;p<48 || p>57;p=getc(stdin));
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
void f(int* a){*a =10;}
int main()
{
	int a[10],b[10];
	int dd;
	f(&dd);
	int *c=b;
	long long int t,fl,i;
	for(i=0;i<=1000000;i++) ar[i]=1LL*i*i;
	long long int n,r,sq;
	scanf("%lld",&t);
	while(t--)
	{
		n=linp();
		fl=1;
		for(i=0;i*i<=n;i++)
		{
			sq=ar[i];
			r=sqrt(n-sq);
			if(ar[r]==(n-sq))
			{
				fl=0;
				break;
			}
		}
		if(fl) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
