#include<stdio.h>
#include<stdbool.h>
#define pc(x) putchar_unlocked(x);
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
int main()
{
    long long int c,s;
    int i;
    static int arr[1000001];
    for(i=1;i<=1000000;i++)
        arr[i]=1;
    for(i=1;i<=1000000;i++)
    {
        if(arr[i]==1)
            printf("%d\n",i);
        c=i;
        s=0;
        while(c>0)
        {
            s += c%10;
            c /= 10;
        }
        s += i;
        if(s<=1000000)
            arr[s]=0;
    }
    return 0;
}
