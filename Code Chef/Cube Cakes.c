//http://www.codechef.com/DEC13/problems/CUBE
//@ashish1294 NITK Surathkal
#include<stdio.h>
#include<math.h>

//Fast Input Functions
inline void fast_int(int *x)
{
    register int c = getchar_unlocked();
    *x = 0;
	int neg = 0;
    while(c<48 || c>57) c = getchar_unlocked();
    for(; c>47 && c<58 ; c = getchar_unlocked())
    {
        *x = ((*x)<<1) + ((*x)<<3) + c - 48;
    }
};
inline void fast_string(char *str)
{
    register char c = 0;
    register int i = 0;
    while (c < 33)
        c = getchar_unlocked();
    while (c != '\n')
    {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
    str[i] = '\0';
};

int main()
{
	int t,n,p,temp;
	register int i,j,k,a,b,c;
	char s1[65000],s2[65000];
	fast_int(&t);
	while(t--)
	{
		fast_int(&n);
		fast_int(&p);
		fast_string(s1);
		fast_string(s2);
		int l = n*n*n;
		int dparr[n+2][n+2][n+2];
		/*for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++)
				{
					int pos = ((i-1)*n*n)+((j-1)*n)+k-1;
					if(s1[pos]==s2[pos]) match[i][j][k]=1;
					else match[i][j][k]=0;
				}*/
		for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                for(k=1;k<=n;k++)
                {
                    long long int pos = ((i-1)*n*n) + ((j-1)*n) + (k-1);
                    if (s1[pos]==s2[pos]) temp=1;
                    else temp=0;
                    dparr[i][j][k]=dparr[i-1][j][k]+dparr[i][j-1][k]+dparr[i][j][k-1]+(dparr[i-1][j-1][k-1])-dparr[i-1][j-1][k]-dparr[i-1][j][k-1]-dparr[i][j-1][k-1]+temp;
                }
        int flag=1,noofele=0,a1,b1,c1;
        for(i=n;i>=1 && flag==1;i--)
        {
            int ll=i*i*i;
            double d = (double)((((double)p)*ll)/100);
            int mm = ceil(d);
            for(a=1;a<=(n-i+1);a++)
                for(b=1;b<=(n-i+1);b++)
                    for(c=1;c<=(n-i+1);c++)
                    {
						a1 = a+i-1;
						b1 = b+i-1;
						c1 = c+i-1;
                        int matches = dparr[a1][b1][c1] - dparr[a-1][b1][c1] - dparr[a1][b-1][c1] - dparr[a1][b1][c-1] + dparr[a-1][b-1][c1] + dparr[a-1][b1][c-1] + dparr[a1][b-1][c-1] - dparr[a-1][b-1][c-1];
                        if(matches>=mm)
                        {
                            flag=0;
                            noofele++;
                        }
                    }
        }
        if(noofele==0) printf("-1\n");
		else  printf("%d %d\n",i+1,noofele);
	}
}
