#include<stdio.h>

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

int main()
{
	int n,i;
	long int t;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%d",&n);
		int arr1[n],arr2[n];
		for(i=0;i<n;i++)
			scanf("%d",&arr1[i]);
		for(i=0;i<n;i++)
			scanf("%d",&arr2[i]);
		Quick_Sort(arr1,0,n);
		Quick_Sort(arr2,0,n);
		long long int ans=0;
		for(i=0;i<n;i++)
			ans += (arr1[i]*arr2[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
