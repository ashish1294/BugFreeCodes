//http://www.spoj.com/problems/CPCRC1C/
//http://www.spoj.com/problems/PR003004/

#include<stdio.h>
#include<math.h>
int sum(long long int d)
{
	int ans=0;
	while(d>0)
	{
		int digit=d%10;
		ans = ans +digit;
		d /=10;
	}
	return ans;
}
long long int sumdd(int n)
{
    int i;
    long long int ans = 1;;
    for(i=1;i<=n-1;i++)
        ans *=10;
    ans *= n*45;
    return ans;
}
int summ(int d)
{
    switch(d)
    {
        case -1: return 0;
        case 0: return 0;
        case 1: return 1;
        case 2: return 3;
        case 3: return 6;
        case 4: return 10;
        case 5: return 15;
        case 6: return 21;
        case 7: return 28;
        case 8: return 36;
        case 9: return 45;
    }
}
long long int sumupto(long long int d)
{
    int i=0;
    long long int ans = sum(d);
    while(d>0)
    {
        int digit = d%10;
        ans += (digit*(sum(d)-digit)*pow(10,i)) + summ(digit-1)*pow(10,i) +sumdd(i)*digit;
        //printf("d=%ld,digit=%d,i=%d,ans=%lld\n",d,digit,i,ans);
        i++;
        d /=10;
    }
    return ans;
}
int main()
{
	int t;
	long long int a,b;
	while(1)
	{
		scanf("%lld %lld",&a,&b);
		if(a==-1 && b==-1)
			break;
		long long int ans=0;
		//for(c=a;c<=b;c++)
			//ans += sum(c);
		//printf("%lld\n",ans);
		long long int tb = sumupto(b);
		long long int ta = sumupto(a-1);
		//printf("sumdd 3 %lld",sumdd(3));
		printf("%lld\n",tb-ta);
	}
	return 0;
}
