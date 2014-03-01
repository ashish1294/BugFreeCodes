//http://www.spoj.com/problems/GPACALC/
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
    int t,n,cr,poi,ch,top,toc;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        top=toc=0;
        while(n--)
        {
            scanf("%d",&cr);
            ch=getc(stdin);
            while (!(ch=='S' || (ch>='A' && ch<='E')))
                ch=getc(stdin);
            if(ch=='S') poi=10;
            else if(ch=='A') poi=9;
            else if(ch=='B') poi=8;
            else if(ch=='C') poi=7;
            else if(ch=='D') poi=6;
            else if(ch=='E') poi=5;
            toc += cr;
            top += (cr*poi);
        }
        double ans = ((double)top)/((double)toc);
        printf("%.2f\n",ans);
    }
    return 0;
}
