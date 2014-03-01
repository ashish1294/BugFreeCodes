#include<stdio.h>
#include<string.h>
#define LI long int
LI lo(char a[],LI mo)
{
    long ans=0;
    int length=strlen(a),i;
	for(i=0;i<length;i++)
	{
		ans *=10;
		ans += a[i]-'0';
		ans %= mo;
	}
	return ans;
}
LI gcd(LI a, LI b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{   int t;
    LI num1,num2,aa;
    char str[1000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld%s",&num1,str);
        if(num1==0)
            printf("%s\n",str);
        else
        {
            num2=lo(str,num1);
            aa = gcd(num1,num2);
            printf("%ld\n",aa);
        }
    }
    return 0;
}
