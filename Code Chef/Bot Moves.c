#include<stdio.h>
int main()
{
    int t;
    long int n,i,temp,te;
    long long int ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%ld",&n);
        long int Arr[n];
        for(i=0;i<n;i++)
            scanf("%ld",&Arr[i]);
        Quick_Sort(Arr,0,n);
        //for(i=0;i<n;i++)
          //  printf("%ld ",Arr[i]);
        //printf("\n");
        if (n%2==0)
            temp = ((Arr[(n/2)] - Arr[((n/2)-1)])/2) + Arr[(n/2)-1];
        else
            temp = n/2;
        //printf("\ntemp=%ld",temp);
        for(i=0;i<n;i++)
        {
            te = Arr[temp]-Arr[i];
            if (te<0)
                ans = ans - te;
            else
                ans = ans + te;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
void Quick_Sort(long int Arr[],long int l,long int u)
{
    long int i=l,j=u-1,temp,k,pivot;
    srand(time(NULL));
    if((u-l)==0)
        return;
    pivot= (rand()%(u-l)) +l;
    while(i<=j)
    {
        while(Arr[i]<Arr[pivot])
              i++;
        while(Arr[j]>Arr[pivot])
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
