//http://www.codechef.com/COOK41/GERALD04
//Author - Ashish Kedia, NITK Surathkal,
//@ashish1294

#include<stdio.h>
inline int inp()
{int noRead=0;
  register char p=getc(stdin);
  for(;p<48 || p>57;p=getc(stdin));
  while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');
  p=getc(stdin);}return noRead;};
int main()
{
    int t,h1,m1,h2,m2,dis;
    scanf("%d",&t);
    while(t--)
    {
        h1=inp();
        m1=inp();
        h2=inp();
        m2=inp();
        dis=inp();
        //scanf("%d%d%d%d%d",&h1,&m1,&h2,&m2,&dis);
        int diff = ((h1-h2)*60)+(m1-m2);
        float ans1 = diff+dis,ans2;
        if((2*dis)<=diff) ans2 = diff;
        else ans2 = dis+ (diff/2.0);
        printf("%.1f %.1f\n",ans1,ans2);
    }
    return 0;
}
