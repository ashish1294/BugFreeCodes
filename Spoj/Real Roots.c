//http://www.spoj.com/problems/RROOT/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<math.h>
int main()
{
	int t,s;
	double sq2 = sqrt(2);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&s);
		double x = 3*sqrt(s);
		double ans = (x - sq2)/x;
		printf("%.6lf\n",ans);
	}
	return 0;
}
