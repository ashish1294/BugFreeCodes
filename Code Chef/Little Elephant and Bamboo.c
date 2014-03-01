#include<stdio.h>

int main()
{
    int t,n,i,h[50],d[50],hsum,dsum,steps,stsum,flag,temp,sflag;
    scanf("%d",&t);
    while(t--)
    {
        sflag=0;
        hsum=0;
        dsum=0;
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
            hsum +=h[i];
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&d[i]);
            dsum +=d[i];
            if((d[i]-h[i])!=0)
                sflag=1;
        }
        if (sflag==0)
            printf("0\n");
        else if (n==1)
        {
            if (dsum>hsum)
                printf("-1\n");
            else
                printf("%d\n",(h[0]-d[0]));
            continue;
        }
        else if (n==2)
        {
            if (dsum!=hsum)
                printf("-1\n");
            else if(d[0]>h[0])
                printf("%d\n",(d[0]-h[0]));
            else
                printf("%d\n",(h[0]-d[0]));
            continue;
        }
        else if ((dsum<=hsum)||(((dsum-hsum)%(n-2))!=0))
            printf("-1\n");
        else
        {
            steps = (dsum-hsum)/(n-2);
            stsum=0;
            flag=0;
            for(i=0;i<n;i++)
            {
                temp=steps-d[i]+h[i];
                if(temp<0||((temp!=0)&&(temp%2!=0)))
                {
                    flag=1;
                    //printf("\nbreaking\n");
                    break;
                }
                stsum += (temp/2);
            }
            if(stsum==steps&&flag==0)
                printf("%d\n",steps);
            else
                printf("-1\n");
        }
    }
    return 0;
}
