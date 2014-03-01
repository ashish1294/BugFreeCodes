#include<stdio.h>
int main()
{
    int t;
    long long int x,co2,co3,co4,coun,i,j;
    long int A[100001],B[100001],n;
    double ans;
    scanf("%d",&t);
    while(t--)
    {
        x=0;
        scanf("%ld",&n);
        for(i=0;i<n;i++)
            scanf("%ld",&A[i]);
        for(i=0;i<n;i++)
            scanf("%ld",&B[i]);
        Quick_Sort(A,0,n);
        Quick_Sort(B,0,n);
        i=0;
        while(i<n&&B[i]==1)
            i++;
        coun=0;
        while(i<n&&B[i]==2)
            {coun++;i++;}
        j=0;
        while(j<n&&A[j]==1)
            j++;
        x += n*j;
        co2=0;
        co3=0;
        co4=0;
        while(j<n&&A[j]==2)
            {co2++;j++;}
        while(j<n&&A[j]==3)
            {co3++;j++;}
        while(j<n&&A[j]==4)
            {co4++;j++;}
        //printf("\n  co2=%ld co3=%ld co4=%ld",co2,co3,co4);
        x += (co2+co4+n-j)*coun;
        //printf("\n%ld\n",x);
        coun=0;
        while(i<n&&B[i]==3)
            {coun++;i++;}
        x += (co3+co2+n-j+co4)*coun;
        //printf("\n%ld\n",x);
        coun=0;
        while(i<n&&B[i]==4)
            {coun++;i++;}
        x += coun*(co2+co4+n-j);
        while (i<n)
        {
            while(j<n&&A[j]<B[i])
                j++;
            x += n-j;
            i++;
        }
        ans =(double) x/n;
        printf("%lf\n",(n-(ans)));
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
