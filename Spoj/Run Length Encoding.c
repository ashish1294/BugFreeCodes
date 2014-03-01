//http://www.spoj.com/problems/RLE/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
    char str[100000],ans[100000];
    int i,j,co,k,dig;
    while(scanf("%s",str)!=EOF)
    {
        i=0;j=0,k;
        while(str[i]!='\0')
        {
            co=1;
            while(str[i]==str[i+1])
                {co++;i++;}
            if(co<=3)
            {
                for(k=0;k<co;k++)
                    ans[j++]=str[i];
            }
            else
            {
                if(co<10) dig=1;
                else if(co<100) dig=2;
                else if(co<1000) dig=3;
                else if(co<10000) dig=4;
                else if(co<100000) dig=5;
                else dig=6;
                int tdig=dig;
                while(co>0)
                {
                    dig--;
                    ans[j+dig]=(co%10)+48;
                    co/=10;
                }
                j+=tdig;
                ans[j++]='!';
                ans[j++]=str[i];
            }
            i++;
        }
        ans[j]='\0';
        printf("%s\n",ans);
    }
    printf("Finish");
    return 0;
}
