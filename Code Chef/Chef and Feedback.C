//http://www.codechef.com/JAN14/problems/ERROR
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<string.h>
char str[100001];
inline void inpstr()
{
    register int i=0;
    register char c=getc(stdin);
    //register char c=getchar_unlocked();
    while(c!='0' && c!='1') c=getc(stdin);
    //while(c!='0' && c!='1') c=getchar_unlocked();
    while(c=='0'||c=='1'){str[i++]=c;c=getc(stdin);}
    //while(c=='0'||c=='1'){str[i++]=c;c=getchar_unlocked();}
    str[i]='\0';
}
int main()
{
    int n,i,flag;
    scanf("%d",&n);
    while(n--)
    {
        inpstr();
        if(str[0]=='\0' || str[1]=='\0' || str[2]=='\0') {printf("Bad\n");continue;}
        i=2;flag=1;
        while(str[i]!='\0')
        {
            if ((str[i]=='0' && str[i-1]=='1' && str[i-2]=='0') || (str[i]=='1' && str[i-1]=='0' && str[i-2]=='1'))
            {
                printf("Good\n");
                flag=0;
                break;
            }
            i++;
        }
        if(flag) printf("Bad\n");
    }
    return 0;
}
