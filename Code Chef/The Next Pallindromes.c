#include<stdio.h>
#include<string.h>

int main()
{
    long int t,len,i,k,tlen,len2,flag;
    char str[1000005],temp[1000005];
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%s",str);
        len=strlen(str);
        len2=len>>2;
        i=0;
        while(str[i]!='\0')
            if(str[i]!='9')
                break;
            else
                i++;
        if(i==len)
        {
            str[0]='1';
            for(i=1;i<len;i++)
                str[i]='0';
            str[len]='1';
            str[len+1]='\0';
        }
        else
        {
            for(i=0;i<len2;i++)
            {
                if(str[i]<str[len-1-i])
                    flag=-1;
                else if(str[i]>str[len-1-i])
                    flag=1;
                str[len-1-i]=str[i];
            }
            if(len%2==0)
                len2--;
            if(flag==0||flag==-1)
            {
                i=0;
                while(str[len2-i]=='9')
                {
                    str[len2-i]='0';
                    str[len-1-len2+i]='0';
                    i++;
                }
                str[len2-i]++;
                str[len-1-len2+i]=str[len2-i];
            }
        }
        printf("%s\n",str);
    }
    return 0;
}








if(len%2==0)
        {
            for(i=0;i<(len/2)-1;i++)
                str[len-1-i]=str[i];
            if(str[len-1-i]>=str[i])
            {
                str[i]++;
                str[len-i-1]=str[i];
            }
            else
                str[len-i-1]=str[i];
        }
        else
        {
            for(i=0;i<((len/2)-1);i++)
                str[len-1-i]=str[i];
            if(str[len-1-i]>=str[i])
                str[i+1]++;
            str[len-i-1]=str[i];
        }
