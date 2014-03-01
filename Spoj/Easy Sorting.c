//http://www.spoj.com/problems/LEXISORT/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<string.h>
int comp(const void* a, const void* b)
{
    return strcmp(((char*)a),((char*)b));
}
inline void fast_string(char *str)
{
    register char c = 0;
    register int i = 0;
    //while (c < 33) c = getchar_unlocked();
    while (c < 33) c = getc(stdin);
    while (c!='\n')
    {
        str[i]=c;
        //c=getchar_unlocked();
        c=getc(stdin);
        i++;
    }
    str[i] ='\0';
};
inline int inp()
{
    register int noRead=0;
    int neg=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked()){if(p=='-') neg=1;};
    for(;p<48 || p>57;p=getc(stdin)){if(p=='-') neg=1;}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    if (neg) return -noRead;
    else return noRead;
};
int main()
{
    int t=inp();
    while(t--)
    {
        int n=inp(),i;
        char str[n][20];
        for(i=0;i<n;i++) {scanf("%s",str[i]);}
        qsort(str,n,sizeof(str[0]),comp);
        for(i=0;i<n;i++) {puts(str[i]);}
    }
    return 0;
}
