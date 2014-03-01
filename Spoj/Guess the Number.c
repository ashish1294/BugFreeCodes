//http://www.spoj.com/problems/GUESSTHE/
//Author - Ashish Kedia,, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<string.h>
int main()
{
    char s[25];
    while(1)
    {
        scanf("%s",s);
        if(s[0]=='*') break;
        long long int no=1;
        int flag=0,i;
        for(i=1;i<=strlen(s);i++)
        {
            if(i==1 && s[0]=='N') {flag=1;break;}
            if(i==2 && s[1]=='Y') no*=2;
            if(i==3 && s[2]=='Y') no*=3;
            if(i==4 && s[3]=='Y')
            {
                if(s[1]=='N') {flag=1;break;}
                else no*=2;
            }
            if(i==5 && s[4]=='Y') no*=5;
            if(i==6 && s[5]=='Y')
            {
                    if(s[1]=='N' || s[2]=='N') {flag=1;break;}
            }
            if(i==7 && s[6]=='Y') no*=7;
            if(i==8 && s[7]=='Y')
            {
                if(s[1]=='N'||s[3]=='N') {flag=1;break;}
                else no*=2;
            }
            if(i==9 && s[8]=='Y')
            {
                if(s[2]=='N') {flag=1;break;}
                else no*=3;
            }
            if(i==10 && s[9]=='Y')
            {
                if(s[1]=='N' || s[4]=='N') {flag=1;break;}
            }
            if(i==11 && s[10]=='Y') no*=11;
            if(i==12 && s[11]=='Y')
            {
                if(s[3]=='N' || s[2]=='N' || s[1]=='N' || s[5]=='N') {flag=1;break;}
            }
            if(i==13 && s[12]=='Y') no*=13;
            if(i==14 && s[13]=='Y')
            {
                if(s[1]=='N' || s[6]=='N') {flag=1;break;}
            }
            if(i==15 && s[14]=='Y')
            {
                if(s[4]=='N' || s[2]=='N') {flag=1;break;}
            }
            if(i==16 && s[15]=='Y')
            {
                if(s[1]=='N' || s[3]=='N' || s[7]=='N') {flag=1;break;}
                else no*=2;
            }
            if(i==17 && s[16]=='Y') no*=17;
            if(i==18 && s[17]=='Y')
            {
                if(s[1]=='N' || s[2]=='N' || s[5]=='N' || s[8]=='N') {flag=1;break;}
            }
            if(i==19 && s[18]=='Y') no*=19;
            if(i==20 && s[19]=='Y')
            {
                if(s[1]=='N' || s[3]=='N' || s[4]=='N' || s[9]=='N') {flag=1;break;}
            }
            //printf("i=%d no=%lld flag=%d\n",i,no,flag);
        }
        for(i=1;i<=strlen(s) && flag==0;i++)
            if(no%i==0 && s[i-1]=='N') {flag=1;break;}
        if(flag) printf("-1\n");
        else printf("%lld\n",no);
    }
    return 0;
}
