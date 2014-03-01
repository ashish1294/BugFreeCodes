//http://www.spoj.com/problems/OLOLO/
//@ashish1294 NITK Surathkal
int main()
{
	int t,n,a=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		a ^= n;
	}
	printf("%d",a);
	return 0;
}
