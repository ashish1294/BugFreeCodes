//http://www.codechef.com/MAY14/problems/COMPILER
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define getchar_unlocked() getc(stdin)
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a=0,b=0,i=0,j=0;
        char c = getchar_unlocked();
        while(c!='<' && c!='>') c = getchar_unlocked();
        while(1)
        {
            if(c=='<') a++;
            else if(c=='>') a--;
            else break;
            if(a<0)
            {
                while(c!='\n') c=getchar_unlocked();
                break;
            }
            else if(a==0) b=i+1;
            i++;
            c=getchar_unlocked();
        }
        printf("%d\n",b);
    }
    return 0;
}
