//http://www.codechef.com/APRIL14/problems/SEAPERM/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<utility>
#define MASZ 5000
using namespace std;
struct ele{
    int n,in;
};
struct ele arr[2010],bans[2010];
struct ele ans[MASZ][2010];
long long int score[MASZ];
int ll,n,k;
long long int S;
bool inc_comp(ele aa, ele bb)
{
    return aa.n<bb.n;
}
inline int inp()
{
    int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int func(int ind, int i)
{
    ll=i; int su=S;
    while(ll<=n)
    {
        if(su-ans[ind][ll].n>=0)
        {
            su = su - ans[ind][ll].n;
            ll++;
        }
        else return su;
    }
    return su;
}
void calc(int ind)
{
    int su=S; int llc=1;
    score[ind]=0;
    while(llc<=n && ans[ind][llc].n<=su)
    {
        su -= ans[ind][llc].n;
        llc++;
    }
    score[ind] += su;
    for(int i=2;i<=k;i++)
    {
        if(su<S)
        {
            su+=ans[ind][i-1].n;
        }
        llc = max(llc,i);
        while(llc<=n && ans[ind][llc].n<=su)
        {
            su -= ans[ind][llc].n;
            llc++;
        }
        score[ind] += su;
    }
}
int main()
{
    int t=inp(),i,j,con,dsum,li,ri;
    while(t--)
    {
        n=inp(),k=inp(),S=inp();
        for(i=1;i<=n;i++)
        {
            arr[i].n=inp();
            arr[i].in=i;
            ans[0][i]=ans[1][n-i+1]=ans[2][i]=arr[i];
        }
        sort(ans[2]+1,ans[2]+n+1,inc_comp);
        for(i=1;i<=n;i++)
            ans[3][n-i+1] = ans[4][n-i+1] = ans[5][n-i+1] = ans[12][n-i+1] = ans[6][i]= ans[7][i] = ans[8][i] = ans[11][i] = ans[13][i] = ans[14][i] = ans[2][i];

        //Method 4
        func(4,1);
        reverse(ans[4]+ll,ans[4]+n+1);

        //Method 5
        if(ll>1)
        reverse(ans[5] + 1,ans[5]+ll);
        reverse(ans[5] + ll,ans[5]+n+1);

        //Method 6
        for(i=0;i<k;i++)
        {
            int tem = func(6,k-i);
            for(li=ll;li<=n && ll>1;li++)
            {
                if(ans[6][li].n>ans[6][ll-1].n && (ans[6][li].n-ans[6][ll-1].n<=tem))
                {
                    tem -= (ans[6][li].n - ans[6][ll-1].n);
                    ele ext = ans[6][li];
                    ans[6][li] = ans[6][ll-1];
                    ans[6][ll-1] = ext;
                }
            }
        }

        //Method 7
        for(i=1;i<=k;i++)
        {
            int tem = func(7,i);
            for(li=ll;li<=n && ll>1;li++)
            {
                if(ans[7][li].n>ans[7][i].n && (ans[7][li].n-ans[7][i].n<=tem))
                {
                    tem -= (ans[7][li].n - ans[7][i].n);
                    ele ext = ans[7][li];
                    ans[7][li] = ans[7][i];
                    ans[7][i] = ext;
                }
            }
        }

        //Method 8
        for(i=1;i<=k;i++)
        {
            int ttmp = func(8,i);
            for(int ci=n;ci>=ll;ci--)
            {
                if((ans[8][ci].n>ans[8][ll-1].n) && (ans[8][ci].n-ans[8][ll-1].n<=ttmp))
                {
                    ele tchk = ans[8][ci];
                    for(int ii=ci;ii>=ll;ii--)
                    {
                        ans[8][ii]=ans[8][ii-1];
                    }
                    ans[8][ll-1]=tchk;
                    break;
                }
            }
        }

        //Method 9
        for(i=1;i<=n;i++) ans[9][i]=ans[4][i];
        for(i=1;i<=k;i++)
        {
            int ttmp = func(9,i);
            for(int ci=n;ci>=ll;ci--)
            {
                if((ans[9][ci].n>ans[9][ll-1].n) && (ans[9][ci].n-ans[9][ll-1].n<=ttmp))
                {
                    ele tchk = ans[9][ci];
                    for(int ii=ci;ii>=ll;ii--)
                    {
                        ans[9][ii]=ans[9][ii-1];
                    }
                    ans[9][ll-1]=tchk;
                    break;
                }
            }
        }

        //Method 10
        for(i=1;i<=n;i++) ans[10][i]=ans[5][i];
        for(i=1;i<=k;i++)
        {
            int ttmp = func(10,i);
            for(int ci=n;ci>=ll;ci--)
            {
                if((ans[10][ci].n>ans[10][ll-1].n) && (ans[10][ci].n-ans[10][ll-1].n<=ttmp))
                {
                    ele tchk = ans[10][ci];
                    for(int ii=ci;ii>=ll;ii--)
                    {
                        ans[10][ii]=ans[10][ii-1];
                    }
                    ans[10][ll-1]=tchk;
                    break;
                }
            }
        }

        //Method 11
        for(i=1;i<=k;i++)
        {
            int ttmp = func(11,i);
            for(int ci=1,ii=ll-1;ci<ii;ci++,ii--)
            {
                ele tx = ans[11][ci];
                ans[11][ci] = ans[11][ii];
                ans[11][ii] = tx;
            }
        }

        //Method 12
        for(i=1;i<=k;i++)
        {
            int tmp12 = func(12,i);
            for(li=ll+1;li<=n;li++)
            {
                if(ans[12][li].n<=tmp12)
                {
                    ele chk12 = ans[12][li];
                    for(int ii=li;ii>ll;ii--)
                        ans[12][ii] = ans[12][ii-1];
                    ans[12][ll]=chk12;
                    tmp12 -= chk12.n;
                    ll++;
                }
            }
        }

        //Method 13
        for(i=1;i<=k;i++)
        {
            int tmp13 = func(13,i);
            for(li=n;li>=ll && ll>i;li--)
            {
                if(ans[13][li].n > ans[13][ll-1].n && (ans[13][li].n - ans[13][ll-1].n <= tmp13))
                {
                    ele chk13 = ans[13][li];
                    for(int ii=li;ii>=ll;ii--)
                        ans[13][ii]=ans[13][ii-1];
                    ans[13][ll-1]=chk13;
                    tmp13 -= chk13.n;
                    break;
                }
            }
        }

        //Method 14
        int lall14=1;
        for(i=1;i<=k;i++)
        {
            int tmp14 = func(14,i);
            if(ll>i && ll>lall14)
            {
                for(li=n;li>=ll && ll>i;li--)
                {
                    if(ans[14][li].n > ans[14][ll-1].n && (ans[14][li].n - ans[14][ll-1].n <= tmp14))
                    {
                        ele chk14 = ans[14][li];
                        for(int ii=li;ii>=ll;ii--)
                            ans[14][ii]=ans[14][ii-1];
                        ans[14][ll-1]=chk14;
                        tmp14 -= chk14.n;
                        break;
                    }
                }
            }
            lall14=ll;
        }

        calc(2);calc(13);calc(14);calc(6);calc(7);calc(8);calc(11);
        int mint;
        if(score[2]<score[13]) mint=2; else mint=13;
        if(score[6]<score[mint]) mint=6;
        if(score[7]<score[mint]) mint=7;
        if(score[8]<score[mint]) mint=8;
        if(score[11]<score[mint]) mint=11;
        if(score[14]<score[mint]) mint=14;

        for(i=3;i<15;i++)
        {
            calc(i);
            if(score[i]<score[mint]) mint=i;
        }

        int lmt = 15;
        int start = (n/6);
        for(j=0;j<135;j++)
        {
            int cn = 10*(j+25);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        lmt = 150;start=k+1;
        for(j=0;j<550;j++)
        {
            int cn = 10*(j+51);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        lmt = 700;start=(n/6);
        for(j=0;j<400;j++)
        {
            int cn = 10*(j+50);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        lmt = 1100;start=(k+1);
        for(j=0;j<400;j++)
        {
            int cn = 10*(j+51);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        lmt = 1500;start=(k+1);
        for(j=0;j<200;j++)
        {
            int cn = 10*(j+65);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        lmt = 1700;start=(k+1);
        for(j=0;j<200;j++)
        {
            int cn = 15*(j+10);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        lmt = 1900;start=(k+1);
        for(j=0;j<200;j++)
        {
            int cn = 5*(j+5);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        lmt = 2100;start=n/6;
        for(j=0;j<200;j++)
        {
            int cn = 5*(j+5);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        /*if(mint!=14) mint=14;
        else
        {
            if(score[2]<score[13]) mint=2; else mint=13;
            if(score[6]<score[mint]) mint=6;
            if(score[7]<score[mint]) mint=7;
            if(score[8]<score[mint]) mint=8;
            if(score[11]<score[mint]) mint=11;
        }*/
        lmt = 2300;start=k+1;
        for(j=0;j<100;j++)
        {
            int cn = 10*(j+51);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        lmt = 2400;start=(k+1);
        for(j=0;j<150;j++)
        {
            int cn = 10*(j+51);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        for(i=0;i<15;i++)
        {
            calc(i);
            if(score[i]<score[mint]) mint=i;
        }
        lmt = 2550;start=(k+1);
        for(j=0;j<150;j++)
        {
            int cn = 10*(j+65);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        lmt = 2700;start=(k+1);
        for(j=0;j<150;j++)
        {
            int cn = 15*(j+10);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        lmt = 2850;start=(k+1);
        for(j=0;j<150;j++)
        {
            int cn = 5*(j+5);
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        lmt = 3000;start=k+1;
        for(j=0;j<(n-k);j++)
        {
            int cn = j+1;
            for(i=1;i<=n;i++) ans[lmt+j][i] = ans[mint][i];
            for(i=start;i<=n;i++)
            {
                int inde = i + cn;
                if(inde>n) inde = start + (inde - start)%(n - start + 1 );
                ans[lmt+j][inde]=ans[mint][i];
            }
        }

        int best=0;calc(0);
        for(i=1;i<min(MASZ,3000+n-k);i++)
        {
            calc(i);
            if(score[i]<score[best]) best=i;
            else if(score[i]<(score[best]>>1))
            {
                reverse(ans[i]+1,ans[i]+n+1);
                calc(i);
                if(score[i]<score[best]) best=i;
            }
        }
        //printing the best solution
        printf("%d",ans[best][1].in);
        for(i=2;i<=n;i++)
        {
            printf(" %d",ans[best][i].in);
        }
        printf("\n");
    }
}
