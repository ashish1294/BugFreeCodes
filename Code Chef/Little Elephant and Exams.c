#include<stdio.h>
double ansprob =0.0;
void solve(int start,int end,int Selected[], int A[],int B[],int P[],double prob)
{
    int flag=0,i;
    for(i=0;i<start;i++)
        if(Selected[i]==A[start])
        {
            flag=1;
            break;
        }
    if(!flag)
    {
        double prob1 = (double)(((double)P[start])/100);
        prob1 *= prob;
        Selected[start]=A[start];
        if(start==end)
            ansprob += prob1;
        else
            solve(start+1,end,Selected,A,B,P,prob1);
    }
    flag=0;
    for(i=0;i<start;i++)
    {
        if(Selected[i]==B[start])
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        double prob2 = (double)(((double)(100-P[start]))/100);
        prob2 *= prob;
        Selected[start]=B[start];
        if(start==end)
            ansprob += prob2;
        else
            solve(start+1,end,Selected,A,B,P,prob2);
    }
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int A[n],B[n],P[n],i,min=20;
        ansprob=0.0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&P[i],&A[i],&B[i]);
        }
        if(n>16)
            ansprob=0.0;
        else
        {
            int Selected[n];
            solve(0,n-1,Selected,A,B,P,1);
        }
        printf("%.14lf\n",ansprob);
    }
    return 0;
}
