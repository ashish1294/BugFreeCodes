#include<stdio.h>
#include<string.h>
#define lp co++;l++;ans[cc++]='L';ans[cc++]='+';
#define lm co++;l--;ans[cc++]='L';ans[cc++]='-';
#define rp co++;r++;ans[cc++]='R';ans[cc++]='+';
#define rm co++;r--;ans[cc++]='R';ans[cc++]='-';
char ans[10000000];
int co,cc=0;
inline int inp()
{
    int noRead=0;
    int neg=0;
    register char p=getchar_unlocked();
    //register char p=getc(stdin);
    for(;p<48 || p>57;p=getchar_unlocked()){if (p=='-') neg=1;}
    //for(;p<48 || p>57;p=getc(stdin)){if(p=='-') neg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    if(neg) return -noRead;
    else return noRead;
};
int main()
{
    int t,n,l,r,l1,r1;
    t=inp();
    while(t--)
    {
        n=inp();l=inp();r=inp();
        n--;co=0;cc=0;
        ans[0]='\0';
        while(n--)
        {
            l1=inp();r1=inp();
            if(l<=l1)
            {
                while(l<l1 && ((l+1)!=r)) {lp}
                if(l<l1) while(l<l1){rp lp}
                while(r<r1) {rp}
                while(r>r1) {rm}
            }
            else
            {
                while(l>l1){lm}
                while(r<r1){rp}
                while(r>r1){rm}
            }
        }
        ans[cc]='\0';
        printf("%d\n%s\n",co,ans);
    }
    return 0;
}
