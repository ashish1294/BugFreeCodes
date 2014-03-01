//http://www.spoj.com/problems/PERMUT2/
//Author - Ashish Kedia , NITK Surathkal
//@ashish1294
#include<stdio.h>
int arr[100010];
int ha[100010];
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
int main()
{
	int n,i,flag;
	while(1)
	{
		//scanf("%d",&n);
		n=inp();
		if(n==0) return 0;
		for(i=1;i<=n;i++)
		{
			//scanf("%d",&arr[i]);
			arr[i]=inp();
			ha[arr[i]]=i;
		}
		flag=1;
		for(i=1;i<=n;i++)
		{
			if(ha[i]!=arr[i])
			{
				flag=0;
				break;
			}
		}
		if(flag) puts("ambiguous");
		else puts("not ambiguous");
	}
	return 0;
}
