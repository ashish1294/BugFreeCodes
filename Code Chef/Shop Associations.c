#include<stdio.h>
long int maxSubArray2(int a[], int siz)
{
    long int ma(long int,long int);
	long int maxsofar = 0,i;
	long int currentmax = 0;
	for(i = 0; i < siz; i++)
	{
		currentmax = ma(currentmax + a[i], 0);
		maxsofar = ma(maxsofar, currentmax);
	}
	return maxsofar;
}
long int ma(long int a,long int b)
{
    if (a>b)
        return a;
    else
        return b;
}
int main()
{
    int t,n,i;
    long int max_subarray(int array[], int *low, int *high);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int Arr[n];
        for(i=0;i<n;i++)
            scanf("%d",&Arr[i]);
        int low=0,high=n-1;
        printf("%ld\n",max_subarray(Arr,&low,&high));
    }
    return 0;
}
long int max_subarray(int array[], int *low, int *high)
{
    long int max_crossing_subarray(int array[], int *low, int mid, int *high);
    if (*low == *high) {
        return array[*low];
    } else {
        //Don't change avoids overflow
        int mid = *low + (*high - *low)/2;

        int left_low = *low;
        int left_high = mid;
        long int left_sum = max_subarray(array, &left_low, &left_high);

        int right_low = mid + 1;
        int right_high = *high;
        long int right_sum = max_subarray(array, &right_low, &right_high);

        int cross_low = *low;
        int cross_high = *high;
        long int cross_sum = max_crossing_subarray(array, &cross_low, mid, &cross_high);

        if (left_sum >= right_sum && left_sum >= cross_sum)
        {
            *low = left_low;
            *high = left_high;
            return left_sum;

        } else if (right_sum >= left_sum && right_sum >= cross_sum) {
            *low = right_low;
            *high = right_high;
            return right_sum;

        } else {
            *low = cross_low;
            *high = cross_high;
            return cross_sum;
        }
    }
}

long int max_crossing_subarray(int array[], int *low, int mid, int *high)
{
    long int left_sum = 0,i,sum;
    int max_left = mid;
    for (i = mid, sum = 0; i >= *low; i--) {
        sum += array[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    long int right_sum = 0;
    int max_right = mid;
    for (i = mid + 1, sum = 0; i <= *high; i++) {
        sum += array[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }

    *low = max_left;
    *high = max_right;
    return left_sum + right_sum;
}
