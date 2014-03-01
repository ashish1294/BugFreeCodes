//http://www.spoj.com/problems/IMBOX/
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<math.h>
struct box{long long int x1,x2,y1,y2;int valid;};
int comx1(const void *a, const void *b)
{
    struct box* c = ((struct box *)a);
    struct box* d = ((struct box *)b);
    if(c->x1!=d->x1) return (c->x1 - d->x1);
    else if(c->x2!=d->x2) return (d->x2 - c->x2);
    else return (c->y1 - d->y1);
}
long long int calarea(struct box a)
{
    return ((a.x2-a.x1) * (a.y2-a.y1));
}
int main()
{
    int n,i;
    long long int t;
    scanf("%d",&n);
    struct box wh[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld %lld %lld",&wh[i].x1,&wh[i].y1,&wh[i].x2,&wh[i].y2);
        if(wh[i].x1>wh[i].x2){t=wh[i].x1;wh[i].x1=wh[i].x2;wh[i].x2=t;}
        if(wh[i].y1>wh[i].y2){t=wh[i].y1;wh[i].y1=wh[i].y2;wh[i].y2=t;}
        wh[i].valid=1;
    }
    //for(i=0;i<n;i++)
      //  printf("%lld %lld %lld %lld\n",wh[i].x1,wh[i].y1,wh[i].x2,wh[i].y2);
    //printf("Sending to sort\n");
    qsort(wh,n,sizeof(struct box),comx1);
    //for(i=0;i<n;i++)
      //  printf("%lld %lld %lld %lld\n",wh[i].x1,wh[i].y1,wh[i].x2,wh[i].y2);
    long long int toar=0;
    struct box ll;
    i=0;
    int j=0;
    //printf("\nCal Area\n");
    while(j<n)
    {
        toar += calarea(wh[j]);
        wh[j].valid=0;
        ll=wh[j];
        i=j+1;
        while(i<n && wh[i].x1<ll.x2)
        {
            if(wh[i].y1>=ll.y1 && wh[i].y2<=ll.y2 && wh[i].x2<=ll.x2 && wh[i].x1>=ll.x1) wh[i].valid=0;
            i++;
        }
        while(j<n && wh[j].valid==0) j++;
    }
    printf("%lld\n",toar);
    return 0;
}
