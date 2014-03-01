#include<stdio.h>
struct breakpoint{
    int duration;
    int priority;
};
int main()
{
    int n,N[10],i,m,time[100000][10];
    long int j,k;
    struct breakpoint M[5];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&N[i]);

    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&M[i].duration);
        scanf("%d",&M[i].priority);
    }
    Quick_Sort(M,0,m);

    for(i=0;i<m;i++)
    {
        for(j=0;j<100000;j++)
            time[j]=-1;
        for(j=0;j<n;j++)
        {

        }
    }
}

void Quick_Sort(struct breakpoint Arr[],long int l,long int u)
{
    long int i=l,j=u-1,k,pivot;
    struct breakpoint temp;
    srand(time(NULL));
    if((u-l)==0)
        return;
    pivot= (rand()%(u-l)) +l;
    while(i<=j)
    {
        while(Arr[i].priority<Arr[pivot].priority)
              i++;
        while(Arr[j].priority>Arr[pivot].priority)
              j--;

        if(i<=j)
        {
            temp=Arr[i];
            Arr[i]=Arr[j];
            Arr[j]=temp;
            if(i==pivot)
            {
                pivot=j;
            }
            else if (j==pivot)
            {
                pivot=i;
            }
            i++;
            j--;
        }
    }
    if (pivot<j)
    {
        temp=Arr[pivot];
        Arr[pivot]=Arr[j];
        Arr[j]=temp;
        pivot=j;

    }
    if (pivot>i)
    {

        temp=Arr[pivot];
        Arr[pivot]=Arr[i];
        Arr[i]=temp;
        pivot=i;
    }
    if(j>l)
        Quick_Sort(Arr,l,pivot);
    if(i<u-1)
        Quick_Sort(Arr,pivot+1,u);
}
