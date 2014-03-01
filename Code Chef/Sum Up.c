//http://www.codechef.com/CODX2014/problems/REN2013A
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int t,la,lb,numa,numb,i;
    char a[10],b[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",&a,&b);
        la=a[0]-'0';lb=b[0]-'0';
        i=1;
        while(a[i]!='\0')
        {
            if(a[i]-'0'>la) la=a[i]-'0';
            i++;
        }
        i=1;
        while(b[i]!='\0')
        {
            if(b[i]-'0'>lb) lb=b[i]-'0';
            i++;
        }
        la++;lb++;numa=numb=0;
        for(i=strlen(a)-1;i>=0;i--)
            numa += pow(la,(strlen(a)-1-i))*(a[i]-'0');
        for(i=strlen(b)-1;i>=0;i--)
            numb += pow(lb,(strlen(b)-1-i))*(b[i]-'0');
        printf("%d\n",numa+numb);
    }
    return 0;
}
