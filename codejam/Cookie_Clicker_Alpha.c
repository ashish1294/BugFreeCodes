#include<stdio.h>
int main()
{
    int t,ti;
    long double c,f,x,r,time,oh;
    scanf("%d",&t);
    for(ti=1;ti<=t;ti++)
    {
        scanf("%Lf%Lf%Lf",&c,&f,&x);
        r=2;time=0;
        while(1)
        {
            oh = (c/r) + (x/(r+f));
            if(oh<(x/r))
            {
                time += (c/r);
                r += f;
            }
            else
            {
                time += (x/r);
                break;
            }
        }
        printf("Case #%d: %.7Lf\n",ti,time);
    }
    return 0;
}
