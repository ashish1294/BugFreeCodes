//http://projecteuler.net/problem=42
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<string.h>
#include<math.h>
char str[1000];
void inpstr()
{
    char c = getchar();
    int i=0;
    while(c<65 || c>89) c= getchar();
    while(c>64 && c<90) {str[i++]=c;c=getchar();}
    str[i]='\0';
}
int main()
{
    int co=0,i,j,trian[5100];
    for(i=0;i<5100;i++) trian[i]=0;
    for(i=1;i<100;i++)
    {
        j=i*(i+1);
        j/=2;
        trian[j]=1;
    }
    while(1)
    {
        inpstr();
        if(strcmp(str,"YOUTH")==0) {printf("The count is:%d\n",co);return 0;}
        int l=strlen(str),sum=0;
        for(i=0;i<l;i++)
        {
            sum += (str[i]-64);
        }
        double x = (sqrt(8*sum+1)-1.0)/2.0;
        if(trian[sum] && x==((int)x)) {co++;printf("String = %s Sum = %d co=%d\n",str,sum,co);}
    }
    return 0;
}
