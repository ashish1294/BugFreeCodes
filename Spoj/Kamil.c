#include<stdio.h>
int main(){int t=10,i,a;char s[22];while(t--){scanf("%s",s);i=-1;a=1;while(s[++i]!='\0')if(s[i]=='T'||s[i]=='D'||s[i]=='L'||s[i]=='F')a*=2;printf("%d\n",a);}return 0;}
