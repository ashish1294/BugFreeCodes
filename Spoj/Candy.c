#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n>=0)
	{
		int arr[n],i;
		long int sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		float eachpack =((float)sum)/((float)n);
		if (floor(eachpack)!=ceil(eachpack))
		{
			printf("-1\n");
			scanf("%d",&n);
			continue;
		}
		long int ans=0;
		for(i=0;i<n;i++)
		{
			if(arr[i]>eachpack)
				ans+=arr[i]-eachpack;
		}
		printf("%ld\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
