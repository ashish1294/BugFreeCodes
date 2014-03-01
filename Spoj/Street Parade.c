//http://www.spoj.com/problems/STPAR/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
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
int stk[1100],arr[1100];
int sp;
int main()
{
	int n,i,curr,a,can;
	while(1)
	{
		n=inp();
		if (n==0) break;
		curr=1;sp=0;can=1;
		for(i=0;i<n;i++) arr[i]=inp();
		for(i=0;i<n;i++)
         {
             if(arr[i]==curr) curr++;
             else if(sp>0 && arr[i]>stk[sp-1]) {can=0;break;}
             else { stk[sp++]=arr[i];}
             while(sp>0 && stk[sp-1]==curr) {sp--;curr++;}
         }
		if(can==1) puts("yes");
		else puts("no");
	}
	return 0;
}
