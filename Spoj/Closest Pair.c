//http://www.spoj.com/problems/CLOPPAIR/
//author:ashish1294 NITK Surathkal
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>

//Fast Input Outut
inline int inp()
{
	long long int noRead=0,neg=0;
	register char p=getchar_unlocked();
	for(;p<48 || p>57;p=getchar_unlocked())
	{	if(p=='-') neg=1;}
	while(p>32)
	{
		noRead = (noRead << 3) + (noRead << 1) + (p - '0');
		p=getchar_unlocked();
	}
	if(neg) noRead = -noRead;
	return noRead;
};

struct Point {int in;long long int x,y;};
struct PointPair{int in1,in2;long double dist;};
float minf(float a,float b)
{return a>b?b:a;}
long double minld(long double a, long double b)
{return a>b?b:a;}
struct PointPair minpp(struct PointPair a, struct PointPair b)
{return a.dist>b.dist?b:a;}
int comX(const void* a, const void* b)
{
    return (((struct Point *)a)->x) - (((struct Point *)b)->x);
}
int comY(const void* a, const void* b)
{
    return (((struct Point *)a)->y) - (((struct Point *)b)->y);
}
long double calc_dist(struct Point a,struct Point b)
{
	long long int xdiff=a.x-b.x;
	xdiff *= xdiff;
	long long int ydiff=a.y-b.y;
	ydiff *= ydiff;
	long double ret=sqrt(xdiff + ydiff);
	return ret;
}
struct PointPair brute(struct Point p[],int n)
{
	long double tdist;
	int i,j;
	struct PointPair pa;
	pa.dist=LDBL_MAX;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			tdist=calc_dist(p[i],p[j]);
			if(tdist<pa.dist)
			{
				pa.dist=tdist;
				pa.in1=p[i].in;
				pa.in2=p[j].in;
			}
		}
		return pa;
}
struct PointPair stripClosest(struct Point strip[],int size,struct PointPair d)
{
    qsort(strip, size, sizeof(struct Point), comY);
    long double tdist;
    int i,j;
    for (i=0;i<size;++i)
        for (j=i+1;j<size&&(strip[j].y-strip[i].y)<d.dist;++j)
        {
			tdist=calc_dist(strip[i],strip[j]);
            if (tdist < d.dist)
            {
				d.in1 = strip[i].in;
				d.in2 = strip[j].in;
                d.dist= tdist;
			}
		}
    return d;
}
struct PointPair closestpair(struct Point p[],int n)
{
	if(n<=3)
		return brute(p,n);
	int mid=n/2;
	struct Point midp=p[mid];
	struct PointPair dl = closestpair(p,mid);
	struct PointPair dr = closestpair(p+mid,n-mid);
	struct PointPair d = minpp(dl,dr);
	struct Point strip[n];
    int i=0,j = 0;
    for (i = 0; i < n; i++)
        if (abs(p[i].x - midp.x) < d.dist)
            strip[j] = p[i], j++;
	return minpp(d,stripClosest(strip,j,d));
}
int main()
{
	int n,i;
	scanf("%d",&n);
	struct Point parr[n];
	for(i=0;i<n;i++)
	{
		parr[i].x=inp();
		parr[i].y=inp();
		parr[i].in=i;
	}
	qsort(parr,n,sizeof(struct Point),comX);
	struct PointPair mp=closestpair(parr,n);
	if(mp.in1>mp.in2){i=mp.in1;mp.in1=mp.in2;mp.in2=i;}
	printf("%Lf\n",mp.dist);
	return 0;
}
