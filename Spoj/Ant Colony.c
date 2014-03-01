//http://www.codechef.com/KGP13ACM/problems/KGP13F
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct point{
	int x,y;
};
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int ip(struct point a,struct point b)
{
	int aa = abs(a.x-b.x),bb=abs(a.y-b.y);
	if (aa==0) return bb+1;
	if (bb==0) return aa+1;
	return (1+gcd(aa,bb));
}
int main()
{
	int t,i,j,lm,rm,ll;
	struct point p[4],tem;
	scanf("%d",&t);
	for(ll=1;ll<=t;ll++)
	{
		for(i=0;i<4;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		long double ei=0,eb=0,ear=0;
		eb += ip(p[0],p[1]);
		eb += ip(p[1],p[2]);
		eb += ip(p[2],p[3]);
		eb += ip(p[3],p[0]);
		eb -= 4;
		ear = abs((p[0].x*p[1].y-p[0].y*p[1].x)+(p[1].x*p[2].y-p[1].y*p[2].x)+(p[2].x*p[3].y-p[2].y*p[3].x)+(p[3].x*p[0].y-p[3].y*p[0].x))/2.0;
		//printf("Area=%Lf eb=%Lf\n",ear,eb);
		//printf("Area=%Lf eb=%Lf\n",ear,eb);
		ei = (ear+1)+(eb/2.0);
		int ansd = (int)ei;
		printf("Case %d: %d\n",ll,ansd);
	}
	return 0;
}
