#include<stdio.h>
int main()
{
    int t,k,i,ps,j,exi,ge,go,le,lo;
    scanf("%d",&t);
    long long int mineven,minodd;
    while(t--)
    {
        ge=-1;
        go=-1;
        scanf("%d",&k);
        for(i=0;i<k;i++)
        {
            scanf("%d",&ps);
            long long int arr[ps];
            minodd=-1;
            mineven=-1;
            for(j=0;j<ps;j++)
            {
                scanf("%lld",&arr[j]);
                if(arr[j]%2==0)
                {
                    if(mineven==-1 || arr[j]<mineven)
                        mineven=arr[j];
                }
                else
                {
                    if(minodd==-1 || arr[j]<minodd)
                        minodd=arr[j];
                }
            }
            le=0;
            lo=0;
            for(j=0;j<ps;j++)
            {
                if(arr[j]%2==0)
                {
                    if(minodd==-1 || arr[j]<minodd)
                        le++;
                }
                else
                {
                    if (mineven=-1 || arr[j]<mineven)
                        lo++;
                }
            }
            if(le>lo && le>ge)
                ge=le;
            if(lo>le && lo>go)
                go=lo;
            /*if(ps>0)
            {
                exi=1;
                if(arr[0]%2==0)
                {
                    ge++;
                    while(exi<ps)
                    {
                        if(arr[exi]%2==0)
                        {
                            ge++;
                        }
                        else
                            break;
                    }
                }
                else
                {
                    go++;
                    while(exi<ps)
                    {
                        if(arr[exi]%2!=0)
                        {
                            go++;
                        }
                        else
                            break;
                    }
                }
            }*/
        }
        if(ge>go)
            printf("EVEN\n");
        else if(go>ge)
            printf("ODD\n");
        else
            printf("DON'T PLAY\n");
    }
    return 0;
}
