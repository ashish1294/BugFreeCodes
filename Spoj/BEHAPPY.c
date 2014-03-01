#include<stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}

//Calculate the sol using dp. Index Max from 1 to noofele+1
long int DiophantineSol(int noofele,int sumval,int Max[])
{
    int p,i,j,r,n=noofele,k=sumval;
    long int S[n+1][k+1];
    for(p=0;p<=min(Max[1],n);p++) S[1][p]=1;
    for(;p<=n;p++) S[1][p]=0;
    for(i=2;i<=n;i++){
        for(j=0;j<=k;j++){
            long int s=0;
            for(r=max(0,j-Max[i]);r<=j;r++){
                s+=S[i-1][r];
            }
            S[i][j]=s;
        }
    }
    return S[n][k];
}

int main()
{
    int M,N;
    scanf("%d%d",&M,&N);
    {
        int i,Low[M+1],High[M+1],k=N,a[M+1];
        for(i=1;i<=M;i++)
        {
            scanf("%d%d",&Low[i],&High[i]);
            k -= Low[i];
            a[i]=High[i]-Low[i];
        }
        long int ans = DiophantineSol(M,k,a);
        printf("%ld\n",ans);
        //scanf("%d%d",&N,&M);
    }
    return 0;
}
