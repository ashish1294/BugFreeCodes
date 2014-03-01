#include<stdio.h>
int main(){int t,a;long long int n;scanf("%d",&t);while(t--){scanf("%lld",&n);a=2;if(n%2==0)a=2*n&-2*n;printf("%d\n",a);}return 0;}
