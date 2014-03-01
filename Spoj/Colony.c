#include<stdio.h>
int main()
{
    long long int y,p;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&y,&p);
        if (p==1)
            printf("Male\n");
        else if(p==2)
            printf("Female\n");
        else
        {
            int count =0;
            p--;
            while(p>1)
            {
                if(p%2!=0)
                    count += 1;
                p /=2;
            }
            if (count%2!=0)
                p ^= 1;
            if(p==1)
                printf("Female\n");
            else
                printf("Male\n");
        }
    }
    return 0;
}
