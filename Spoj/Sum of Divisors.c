//http://www.spoj.com/problems/ABA12D/

#include<stdio.h>

static long int arr[]={2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921, 1190281};

int main()
{
	int t,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		long int a,b;
		scanf("%ld %ld",&a,&b);
		ans=0;
		for(i=0;;i++)
		{
			if(arr[i]>=a&&arr[i]<=b)
				ans++;
			else if(arr[i]>b)
				break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
