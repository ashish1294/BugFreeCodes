#include<stdio.h>

int main()
{
	int n,x1,x2,x3,y1,y2,y3,tr=0;
	int maxin,minin;
	double max,min,area;
	scanf("%d",&n);
	while(n--)
	{
		tr++;
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
		area = x1*(y2-y3);
		area += x2*(y3-y1);
		area += x3*(y1-y2);
		if (area<0)
			area = -area;
		area /=2;
		if (tr==1)
		{	maxin=1;
            minin = 1;
			max=area; min=area;}
		if (area<=min)
		{	minin=tr; min=area;}
		if (area>=max)
		{	maxin=tr;max=area;}
	}
	printf("%d %d\n",minin,maxin);
	return 0;
}
