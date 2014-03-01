#include<stdio.h>
#include<stdlib.h>

int main()
{
    long int m,i,t1,t2,j,temp;
    long long int n;
    char c;
    scanf("%lld%ld",&n,&m);
    long int Arr[n+1];
    long int gr_mem[n+1];
    for(j=0;j<=n;j++)
    {
        Arr[j]=0;
        gr_mem[j]=0;
    }
    long long int ans = (n*(n-1))/2;
    long int gr_no=1;
    for(j=0;j<m;j++)
    {
        fflush(stdin);
        scanf("%ld%ld",&t1,&t2);
        if ((Arr[t1]==0)&&(Arr[t2]==0))
        {
            Arr[t1]=gr_no;
            Arr[t2]=gr_no;
            gr_mem[Arr[t1]] += 2;
            gr_no++;
        }
        else if((Arr[t1]==0))
        {
            Arr[t1]=Arr[t2];
            gr_mem[Arr[t2]] +=1;
        }
        else if(Arr[t2]==0)
        {
            Arr[t2]=Arr[t1];
            gr_mem[Arr[t1]] +=1;
        }
        else
        {
            temp = Arr[t2];
            for(i=1;i<=n;i++)
            {
                if (Arr[i]==temp)
                {
                    Arr[i]=Arr[t1];
                    gr_mem[temp] -= 1;
                    gr_mem[Arr[t1]] += 1;
                }
            }
        }
    }
    for (i=1;i<=gr_no;i++)
        if(gr_mem[i]>1)
            ans -= (gr_mem[i]*(gr_mem[i]-1))/2;
    printf("%lld\n",ans);
    return 0;
}
