//http://www.codechef.com/APRIL14/problems/TANGDIV/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define getchar_unlocked getchar
#define putchar_unlocked putchar
int chef[501][2], boy[501][2];
inline int inp()
{
    int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int main()
{
    int n,k,p,i,j,ans,flag,t=inp();
    while(t--)
    {
        n=inp();k=inp();p=inp();
        for(i=0;i<k;i++) chef[i][0]=inp(),chef[i][1]=inp();
        for(i=0;i<p;i++) boy[i][0]=inp(),boy[i][1]=inp();
        for(i=0,ans=1;i<k;i++)
        {
            for(j=0,flag=0;j<p;j++)
            {
                if(chef[i][0]<=chef[i][1])
                {
                    if(boy[j][0]<=boy[j][1])
                    {
                        if(chef[i][0]>=boy[j][0] && chef[i][1]<=boy[j][1])
                        {
                            flag=1;
                            break;
                        }
                    }
                    else
                    {
                        if(chef[i][0]>=boy[j][0] || boy[j][1]>=chef[i][1])
                        {
                            flag=1;
                            break;
                        }
                    }
                }
                else
                {
                    if(boy[j][0]<=chef[i][0] && boy[j][1]>=chef[i][1] && boy[j][1]<boy[j][0])
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0)
            {
                ans=0;
                break;
            }
        }
        if(ans)
        {
            putchar_unlocked('Y');
            putchar_unlocked('e');
            putchar_unlocked('s');
        }
        else
        {
            putchar_unlocked('N');
            putchar_unlocked('o');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
