//http://www.codechef.com/JAN14/problems/METEORAK
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<limits.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
inline int inp()
{
    register int noRead=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked());
    for(;p<48 || p>57;p=getc(stdin));
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
int mat[1010][1010],dp[1010][1010],a[1010][1010],dp1[1010][1010],ansdp[1010][1010],n,m;
void min_max(int arr[],int s,int te[],int *x,int *y)
{
	if(s==1){te[arr[1]]=*x=*y=arr[1]; return;}
	int i,minin=1,left[n+1],right[n+1],ll=-1,lh=-1,rl=-1,rh=-1;
	for(i=2;i<=s;i++) if(arr[i]<arr[minin]) minin=i;
	if(minin>1) min_max(arr,minin-1,left,&ll,&lh);
	if(minin<s) min_max(arr+minin,(s-minin),right,&rl,&rh);
	*x=arr[minin];*y=max(lh,rh);
	for(i=*x;i<=*y;i++) te[i] = (*x)*s;
	if(ll>=0)
    {
        for(i=*x;i<=*y;i++)
            if(i<=ll) te[i]=max(te[i],i*(minin-1));
			else if(i<=lh) te[i]=max(te[i],left[i]);
			else if(i>lh) te[i]=max(te[i],left[lh]);
    }
    if(rl>=0)
    {
        for(i=*x;i<=*y;i++)
            if(i<=rl) te[i]=max(te[i],i*(s-minin));
			else if(i<=rh) te[i]=max(te[i],right[i]);
			else if(i>rh) te[i]=max(te[i],right[rh]);
    }
}
int main()
{
    int k,i,j,u,v,q;
    n=inp();m=inp();k=inp();
    int temp[n+1],min_val[n+1],max_val[n+1]; //For storing min and max of each row
    for(i=0;i<=n;i++) for(j=0;j<=m;j++) {mat[i][j]=0;ansdp[i][j]=0;}
    for(i=0;i<k;i++)
    {
        u=inp();v=inp();
        mat[u][v]=1;
    }

    //Traversing Columnwise
    for(i=1;i<=m;i++) a[1][i]=mat[1][i]==0?1:0;
    for(j=1;j<=m;j++)
        for(i=1;i<=n;i++)
        {
            if(mat[i][j]) a[i][j]=0;
            else a[i][j]=a[i-1][j]+1;
        }
    //min_max for each row
    for(i=1;i<=n;i++)
	{
		min_max(a[i],m,temp,&min_val[i],&max_val[i]);
		for(j=min_val[i];j<=max_val[i];j++)	dp1[i-1][j] = temp[j];
	}
	//Final Main Dp
    for(i=1;i<=n;i++)
	{
		if(max_val[i]==0) ansdp[i][i]=0;
		else if(min_val[i]>0) ansdp[i][i]=m;
		else ansdp[i][i] = dp1[i-1][1];
		for(j=i+1;j<=n;j++)
		{
		    k=j-i+1;
			if(min_val[j]>=k) ansdp[i][j]=k*m;
			else if(max_val[j]<=k) ansdp[i][j]=dp1[j-1][max_val[j]];
			else ansdp[i][j]=dp1[j-1][k];
			ansdp[i][j]=max(ansdp[i][j],ansdp[i][j-1]);
		}
	}
    q=inp();
    while(q--)
    {
        u=inp();v=inp();
        printf("%d\n",ansdp[u][v]);
    }
    return 0;
}
