#include<stdio.h>
#include<math.h>
int main()
{
    int t,co;
    long int s,te,i,temp;
    scanf("%d",&t);
    while(t--)
    {
        co=0;
        scanf("%ld",&s);
        temp=s;
        while (s%2==0)
            s /=2;
        te = sqrt(s);
        for (i=3;i<=te;i=i+2)
        {
            while (s%i == 0)
            {
                if (((i-1)%4==0)&&(i!=1))
                {
                     co=1;
                }
                s = s/i;
            }
        }
        if ((s>2)&&((s-1)%4==0))
             co=1;
        if (temp==1)
            co=0;
        if(co==1)
            printf("PERFECT\n");
        else
            printf("IMPERFECT\n");
    }
    return 0;
}
