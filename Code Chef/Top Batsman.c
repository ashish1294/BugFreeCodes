#include<stdio.h>
int main()
{
    int j,t,sc[11],i,k,co,cho,temp;
    int ans;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<11;i++)
            scanf("%d",&sc[i]);
        for(i=1;i<11;i++)
        {
            temp=sc[i];
            j=i-1;
            while((temp<sc[j])&&(j>=0))
            {
                sc[j+1]=sc[j];
                j=j-1;
            }
            sc[j+1]=temp;
        }
        scanf("%d",&k);
        co=0;
        for(i=0;i<11;i++)
            if(sc[i]==sc[11-k])
                co++;
        i=11-k;
        cho=0;
        while(i<11&&sc[i]==sc[11-k])
            {cho++;i++;}
        printf("%ld\n",com(co,cho));
    }
    return 0;
}
int com(int n, int r)
{
	if(r==0 || r==1)
	return n;

	return ((n-r+1)*com(n,r-1)/r);
}
