//http://www.codechef.com/MARCH14/problems/SEASORT2
//Author - Ashish Kedia, NITK SUrathkal
//@ashish1294
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 18
inline int inp()
{
    int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int comp(const void* a, const void*b)
{
   return ((*((int*)a)) - (*((int*)b)));
}
int arr[MAX+1][10010],res[MAX<<1][10010][2],cost[MAX<<1],rp[MAX<<1],n,act[10010];
double score[MAX<<1];
void ppr(int t)
{
    int i;
    printf("Arr = [");
    for(i=0;i<n;i++)
        printf("%d,",arr[t][i]);
    printf("]\n");
}
void sw(int t,int st, int en)
{
    if(st==en) return;
    if(en==st+1 && arr[t][st]==arr[t][en]) return;
    int lim = st + ((en-st)/2);
    int j,tmp;
    for(j=st;j<=lim;j++)
    {
        tmp=arr[t][j];
        arr[t][j]=arr[t][en-j+st];
        arr[t][en-j+st]=tmp;
    }
    res[t][rp[t]][0]=st+1;
    res[t][rp[t]][1]=en+1;
    cost[t]+=en-st+1;
    rp[t]++;
}
void func()
{
    int i,j,ma,lim,tmp;
    int n1 = n>>1;int n2 = n-n1;

    //Minimum at the front with min extension
    for(i=0;i<n-1;i++)
    {
        while(i<n-1 && arr[0][i]==act[i]) i++;
        j=i;
        while(arr[0][j]!=act[i]) j++;
        if(i!=j) sw(0,i,j);
    }
    //Maximum at the end with min extension
    for(i=0;i<n;i++)
    {
        while(i<n && arr[1][n-i-1]==act[n-i-1]) i++;
        j=n-i-1;
        while(arr[1][j]!=act[n-i-1]) j--;
        if(j!=n-i-1) sw(1,j,n-i-1);
    }

    //50-50 Method with min extension
    for(i=0;i<n2;i++)
    {
        while(i<n2 && arr[2][n-i-1]==act[n-i-1]) i++;
        j=n-i-1;
        while(j>=0 && arr[2][j]!=act[n-i-1]) j--;
        if(j!=n-i-1) sw(2,j,n-i-1);
    }
    for(i=0;i<n1;i++)
    {
        while(i<n1 && arr[2][i]==act[i]) i++;
        j=i;
        while(j<n && arr[2][j]!=act[i]) j++;
        if(i!=j) sw(2,i,j);
    }

    //Minimum at the front with max extension
    for(i=0;i<n-1;i++)
    {
        j=i;
        while(arr[3][j]!=act[i]) j++;
        if(i!=j)
        {
            while(j<n-1 && arr[3][j+1]==act[i]) j++;
            sw(3,i,j);
        }
    }
    //Maximum at the end with max extension
    for(i=n-1;i>0;i--)
    {
        j=i;
        while(arr[4][j]!=act[i]) j--;
        if(j!=i)
        {
            while(j>0 && arr[4][j-1]==act[i]) j--;
            sw(4,j,i);
        }
    }

    //50-50 Method with max extension
    for(i=0;i<n2;i++)
    {
        j=n-i-1;
        while(j>=0 && arr[5][j]!=act[n-i-1]) j--;
        if(i!=n-i-1)
        {
            while(j>0 && arr[5][j-1]==act[n-i-1]) j--;
            sw(5,j,n-i-1);
        }
    }
    for(i=0;i<n1;i++)
    {
        j=i;
        while(j<n && arr[5][j]!=act[i]) j++;
        if(i!=j)
        {
            while(j<n-1 && arr[5][j+1]==act[i]) j++;
            sw(5,i,j);
        }
    }

    //Minimum at front, start at last
    for(i=0;i<n-1;)
    {
        j=n-1;tmp=0;
        while(arr[6][j]!=act[i]) j--;
        ma=j;j--;tmp++;
        while(j>i && arr[6][j]==act[i]) {j--;tmp++;}
        while(j>i)
        {
            if(arr[6][j]==act[i])
            {
                sw(6,j+1,ma);
                ma=j+tmp;
                j--;tmp++;
                while(j>i && arr[6][j]==act[i]) {j--;tmp++;}
            }
            else j--;
        }
        if(arr[6][i]!=act[i] && i!=ma) sw(6,i,ma);
        while(i<n && arr[6][i]==act[i]) i++;
    }

    //Maximum at end, start at front
    for(i=n-1;i>0;)
    {
        j=0;tmp=0;
        while(arr[7][j]!=act[i]) j++;
        ma=j;j++;tmp++;
        while(j<i && arr[7][j]==act[i]) {j++;tmp++;}
        while(j<i)
        {
            if(arr[7][j]==act[i])
            {
                sw(7,ma,j-1);
                ma=j-tmp;
                j++;tmp++;
                while(j<i && arr[7][j]==act[i]) {j++;tmp++;}
            }
            else j++;
        }
        if(arr[7][i]!=act[i] && i!=ma) sw(7,ma,i);
        while(i>0 && arr[7][i]==act[i]) i--;
    }

    //50-50 Method with opposite start
    for(i=0;i<n1;i++)
    {
        j=n-1;tmp=0;
        while(arr[8][j]!=act[i]) j--;
        ma=j;j--;tmp++;
        while(j>i && arr[8][j]==act[i]) {j--;tmp++;}
        while(j>i)
        {
            if(arr[8][j]==act[i])
            {
                sw(8,j+1,ma);
                ma=j+tmp;
                j--;tmp++;
                while(j>i && arr[8][j]==act[i]) {j--;tmp++;}
            }
            else j--;
        }
        if(arr[8][i]!=act[i] && i!=ma) sw(8,i,ma);
    }
    for(i=n-1;i>n1;i--)
    {
        j=0;tmp=0;
        while(arr[8][j]!=act[i]) j++;
        ma=j;j++;tmp++;
        while(j<i && arr[8][j]==act[i]) {j++;tmp++;}
        while(j<i)
        {
            if(arr[8][j]==act[i])
            {
                sw(8,ma,j-1);
                ma=j-tmp;
                j++;tmp++;
                while(j<i && arr[8][j]==act[i]) {j++;tmp++;}
            }
            else j++;
        }
        if(arr[8][i]!=act[i] && i!=ma) sw(8,ma,i);
    }

    //50-50 Method with Min extension 2
    for(i=0;i<n1;i++)
    {
        j=i;
        while(j<n && arr[9][j]!=act[i]) j++;
        if(i!=j) sw(9,i,j);
    }
    for(i=0;i<n2;i++)
    {
        j=n-i-1;
        while(j>=0 && arr[9][j]!=act[n-i-1])
            j--;
        if(j!=n-i-1) sw(9,j,n-i-1);
    }

    //50-50 Method with max extension
    for(i=0;i<n1;i++)
    {
        j=i;
        while(j<n && arr[10][j]!=act[i]) j++;
        if(i!=j)
        {
            while(j<n-1 && arr[10][j+1]==act[i]) j++;
            sw(10,i,j);
        }
    }
    for(i=0;i<n2;i++)
    {
        j=n-i-1;
        while(j>=0 && arr[10][j]!=act[n-i-1]) j--;
        if(i!=n-i-1)
        {
            while(j>0 && arr[10][j-1]==act[n-i-1]) j--;
            sw(10,j,n-i-1);
        }
    }

    //50-50 Method with opposite start
    for(i=n-1;i>n1;i--)
    {
        j=0;tmp=0;
        while(arr[11][j]!=act[i]) j++;
        ma=j;j++;tmp++;
        while(j<i && arr[11][j]==act[i]) {j++;tmp++;}
        while(j<i)
        {
            if(arr[11][j]==act[i])
            {
                sw(11,ma,j-1);
                ma=j-tmp;
                j++;tmp++;
                while(j<i && arr[11][j]==act[i]) {j++;tmp++;}
            }
            else j++;
        }
        if(arr[11][i]!=act[i] && i!=ma) sw(11,ma,i);
    }
    for(i=0;i<n1;i++)
    {
        j=n-1;tmp=0;
        while(arr[11][j]!=act[i]) j--;
        ma=j;j--;tmp++;
        while(j>i && arr[11][j]==act[i]) {j--;tmp++;}
        while(j>i)
        {
            if(arr[11][j]==act[i])
            {
                sw(11,j+1,ma);
                ma=j+tmp;
                j--;tmp++;
                while(j>i && arr[11][j]==act[i]) {j--;tmp++;}
            }
            else j--;
        }
        if(arr[11][i]!=act[i] && i!=ma) sw(11,i,ma);
    }

    //Swwep in opposite direction whenever possible
    int ri=n-1,rma,rj,rtmp;
    while(arr[12][ri]==act[ri]) ri--;
    i=0;
    while(arr[12][i]==act[i]) i++;
    for(i=0;i<ri;)
    {
        if(arr[12][i]==act[ri])
        {
            rj=i;rtmp=1;
            rma=i;rj++;
            while(rj<ri && arr[12][rj]==act[ri]) {rj++;rtmp++;}
            while(rj<ri)
            {
                if(arr[12][rj]==act[ri])
                {
                    sw(12,rma,rj-1);
                    rma=rj-rtmp;
                    rj++;rtmp++;
                    while(rj<ri && arr[12][rj]==act[ri]) {rj++;rtmp++;}
                }
                else rj++;
            }
            if(arr[12][ri]!=act[ri] && ri!=rma) sw(12,rma,ri);
            while (ri>0 && arr[12][ri]==act[ri]) ri--;
        }
        j=n-1;tmp=0;
        while(arr[12][j]!=act[i]) j--;
        ma=j;j--;tmp++;
        while(j>i && arr[12][j]==act[i]) {j--;tmp++;}
        while(j>i)
        {
            if(arr[12][j]==act[i])
            {
                sw(12,j+1,ma);
                ma=j+tmp;
                j--;tmp++;
                while(j>i && arr[12][j]==act[i]) {j--;tmp++;}
            }
            else j--;
        }
        if(arr[12][i]!=act[i] && i!=ma) sw(12,i,ma);
        while(i<n && arr[12][i]==act[i]) i++;
    }

    //Sweep in opposite direction whenever we find an element that belongs to other half
    ri=0;
    while(arr[13][ri]==act[ri]) ri++;
    for(i=n-1;i>0;)
    {
        if(arr[13][i]==act[ri])
        {
            rj=i;rtmp=1;
            rma=rj;rj--;
            while(rj>ri && arr[13][rj]==act[ri]) {rj--;rtmp++;}
            while(rj>ri)
            {
                if(arr[13][rj]==act[ri])
                {
                    sw(13,rj+1,rma);
                    rma=rj+rtmp;
                    rj--;rtmp++;
                    while(rj>ri && arr[13][rj]==act[ri]) {rj--;rtmp++;}
                }
                else rj--;
            }
            if(arr[13][ri]!=act[ri] && ri!=rma) sw(13,ri,rma);
            while(ri<n && arr[13][ri]==act[ri]) ri++;
        }
        j=0;tmp=0;
        while(arr[13][j]!=act[i]) j++;
        ma=j;j++;tmp++;
        while(j<i && arr[13][j]==act[i]) {j++;tmp++;}
        while(j<i)
        {
            if(arr[13][j]==act[i])
            {
                sw(13,ma,j-1);
                ma=j-tmp;
                j++;tmp++;
                while(j<i && arr[13][j]==act[i]) {j++;tmp++;}
            }
            else j++;
        }
        if(arr[13][i]!=act[i] && i!=ma) sw(13,ma,i);
        while(i>0 && arr[13][i]==act[i]) i--;
    }

    //First Sweep from left to right and then from right to left like CombSort
    ri=n-1,rma,rj,rtmp;i=0;
    while(arr[14][ri]==act[ri]) ri--;
    while(arr[14][i]==act[i]) i++;
    while(i<ri)
    {
        rj=i;rtmp=0;
        while(arr[14][rj]!=act[ri]) rj++;
        rma=rj;rj++;rtmp++;
        while(rj<ri && arr[14][rj]==act[ri]) {rj++;rtmp++;}
        while(rj<ri)
        {
            if(arr[14][rj]==act[ri])
            {
                sw(14,rma,rj-1);
                rma=rj-rtmp;
                rj++;rtmp++;
                while(rj<ri && arr[14][rj]==act[ri]) {rj++;rtmp++;}
            }
            else rj++;
        }
        if(arr[14][ri]!=act[ri] && ri!=rma) sw(14,rma,ri);
        while (ri>0 && arr[14][ri]==act[ri]) ri--;
        j=ri;tmp=0;
        while(arr[14][j]!=act[i]) j--;
        ma=j;j--;tmp++;
        while(j>i && arr[14][j]==act[i]) {j--;tmp++;}
        while(j>i)
        {
            if(arr[14][j]==act[i])
            {
                sw(14,j+1,ma);
                ma=j+tmp;
                j--;tmp++;
                while(j>i && arr[14][j]==act[i]) {j--;tmp++;}
            }
            else j--;
        }
        if(arr[14][i]!=act[i] && i<ma) sw(14,i,ma);
        while(i<n && arr[14][i]==act[i]) i++;
    }

    //First sweep from right to left and then from left to right - like CombSort
    ri=0;i=n-1;
    while(arr[15][ri]==act[ri]) ri++;
    while(arr[15][i]==act[i]) i--;
    while(i>ri)
    {
        rj=i;rtmp=0;
        while(arr[15][rj]!=act[ri]) rj--;
        rma=rj;rj--;rtmp++;
        while(rj>ri && arr[15][rj]==act[ri]) {rj--;rtmp++;}
        while(rj>ri)
        {
            if(arr[15][rj]==act[ri])
            {
                sw(15,rj+1,rma);
                rma=rj+rtmp;
                rj--;rtmp++;
                while(rj>ri && arr[15][rj]==act[ri]) {rj--;rtmp++;}
            }
            else rj--;
        }
        if(arr[15][ri]!=act[ri] && ri!=rma) sw(15,ri,rma);
        while(ri<n && arr[15][ri]==act[ri]) ri++;

        j=0;tmp=0;
        while(arr[15][j]!=act[i]) j++;
        ma=j;j++;tmp++;
        while(j<i && arr[15][j]==act[i]) {j++;tmp++;}
        while(j<i)
        {
            if(arr[15][j]==act[i])
            {
                sw(15,ma,j-1);
                ma=j-tmp;
                j++;tmp++;
                while(j<i && arr[15][j]==act[i]) {j++;tmp++;}
            }
            else j++;
        }
        if(arr[15][i]!=act[i] && i!=ma) sw(15,ma,i);
        while(i>0 && arr[15][i]==act[i]) i--;
    }

    //Same as above with first reversal
    //First Sweep from left to right and then from right to left like CombSort
    ri=n-1,rma,rj,rtmp;i=0;
    while(arr[16][ri]==act[ri]) ri--;
    while(arr[16][i]==act[i]) i++;
    if(i<ri) sw(16,i,ri);
    while(arr[16][ri]==act[ri]) ri--;
    while(arr[16][i]==act[i]) i++;
    while(i<ri)
    {
        rj=i;rtmp=0;
        while(arr[16][rj]!=act[ri]) rj++;
        rma=rj;rj++;rtmp++;
        while(rj<ri && arr[16][rj]==act[ri]) {rj++;rtmp++;}
        while(rj<ri)
        {
            if(arr[16][rj]==act[ri])
            {
                sw(16,rma,rj-1);
                rma=rj-rtmp;
                rj++;rtmp++;
                while(rj<ri && arr[16][rj]==act[ri]) {rj++;rtmp++;}
            }
            else rj++;
        }
        if(arr[16][ri]!=act[ri] && ri!=rma) sw(16,rma,ri);
        while (ri>0 && arr[16][ri]==act[ri]) ri--;
        j=ri;tmp=0;
        while(arr[16][j]!=act[i]) j--;
        ma=j;j--;tmp++;
        while(j>i && arr[16][j]==act[i]) {j--;tmp++;}
        while(j>i)
        {
            if(arr[16][j]==act[i])
            {
                sw(16,j+1,ma);
                ma=j+tmp;
                j--;tmp++;
                while(j>i && arr[16][j]==act[i]) {j--;tmp++;}
            }
            else j--;
        }
        if(arr[16][i]!=act[i] && i<ma) sw(16,i,ma);
        while(i<n && arr[16][i]==act[i]) i++;
    }

    //First sweep from right to left and then from left to right - like CombSort
    ri=0;i=n-1;
    while(arr[17][ri]==act[ri]) ri++;
    while(arr[17][i]==act[i]) i--;
    if(i>ri) sw(17,ri,i);
    while(arr[17][ri]==act[ri]) ri++;
    while(arr[17][i]==act[i]) i--;
    while(i>ri)
    {
        rj=i;rtmp=0;
        while(arr[17][rj]!=act[ri]) rj--;
        rma=rj;rj--;rtmp++;
        while(rj>ri && arr[17][rj]==act[ri]) {rj--;rtmp++;}
        while(rj>ri)
        {
            if(arr[17][rj]==act[ri])
            {
                sw(17,rj+1,rma);
                rma=rj+rtmp;
                rj--;rtmp++;
                while(rj>ri && arr[17][rj]==act[ri]) {rj--;rtmp++;}
            }
            else rj--;
        }
        if(arr[17][ri]!=act[ri] && ri!=rma) sw(17,ri,rma);
        while(ri<n && arr[17][ri]==act[ri]) ri++;

        j=0;tmp=0;
        while(arr[17][j]!=act[i]) j++;
        ma=j;j++;tmp++;
        while(j<i && arr[17][j]==act[i]) {j++;tmp++;}
        while(j<i)
        {
            if(arr[17][j]==act[i])
            {
                sw(17,ma,j-1);
                ma=j-tmp;
                j++;tmp++;
                while(j<i && arr[17][j]==act[i]) {j++;tmp++;}
            }
            else j++;
        }
        if(arr[17][i]!=act[i] && i!=ma) sw(17,ma,i);
        while(i>0 && arr[17][i]==act[i]) i--;
    }
}
int main()
{
    srand(time(NULL));
    n=inp();
    int i,j,ma,lim,tmp;
    for(i=0;i<n;i++)
    {
        act[i]=inp();
        for(j=0;j<=MAX;j++) arr[j][i]=act[i];
    }
    qsort(act,n,sizeof(act[0]),comp);
    func();
    for(i=0;i<n;i++)
        for(j=0;j<MAX;j++) arr[j][i]=arr[MAX][i];
    for(i=0;i<MAX;i++)
    {
        score[MAX+i]=score[i];
        cost[MAX+i]=cost[i];
        rp[MAX+i]=rp[i];

        for(j=0;j<rp[i];j++)
        {
            res[MAX+i][j][0]=res[i][j][0];
            res[MAX+i][j][1]=res[i][j][1];
        }
        for(j=0;j<n;j++) arr[i][j] = arr[MAX][j];
        score[i]=cost[i]=rp[i]=0;
    }
    int ll=rand()%(n/2);
    int rr=rand()%(n/2);
    for(i=0;i<MAX;i++) sw(i,ll,ll+rr);
    func();
    //Printing the best solution
    ma=0;
    score[0]=((double)cost[0]/n) + rp[0];
    for(i=1;i<(MAX<<1);i++)
    {
        score[i] = ((double)cost[i]/n) +rp[i];
        if(score[i]<=score[ma] && rp[i]<=n) ma=i;
    }
    //for(i=0;i<(MAX<<1);i++) printf("i=%d score = %lf rp[i]=%d\n",i,score[i],rp[i]);
    printf("%d\n",rp[ma]);
    for(i=0;i<rp[ma];i++)
        printf("%d %d\n",res[ma][i][0],res[ma][i][1]);

    return 0;
}
