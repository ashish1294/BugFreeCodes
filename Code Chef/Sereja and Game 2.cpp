//http://www.codechef.com/JULY15/problems/SEAGM2
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <cassert>
#define MAX 10000
//#define DEBUG 1
using namespace std;
double temp, ans, jj;
bool isprime[MAX + 10], iszero[15];
vector<int> primes;
int rev[MAX + 10];
vector< vector<pair<int, int> > > factors;
vector< vector<int> > won;

int main()
{
    int n, m, i, j, t, k, prc = 0;
    #ifdef DEBUG
        printf("Starting Sieve\n");
    #endif
    //Sieving Primes Here
    isprime[2] = true;
    rev[2] = prc++;
    primes.push_back(2);
    for(i = 3; i <= MAX; i+=2)
    {
        isprime[i] = true;
        isprime[i + 1] = false;
    }
    for(i = 3; i <= MAX; i+=2)
    {
        if(isprime[i])
        {
            #ifdef DEBUG
                printf("Found Prime = %d\n", i);
                fflush(stdout);
            #endif
            primes.push_back(i);
            rev[i] = prc++;
            for(j = i * i; j <= MAX; j += i)
                isprime[j] = false;
        }
    }
    #ifdef DEBUG
        printf("prime Seiving Done, no of primes = %d\n", (int)primes.size());
        fflush(stdout);
    #endif
    vector <pair<int, int> > fact;
    factors.push_back(fact);
    for(i = 1; i <= MAX; i++)
    {
        int no = i;
        vector <pair<int, int> > fact;
        #ifdef DEBUG
            printf("remainder = i= %d, no = %d\n", i, no);
            fflush(stdout);
        #endif
        for(j = 0; j < primes.size() && primes[j] < 100 && no > 1; j++)
        {
            #ifdef DEBUG
                printf("j = %d, prime[j] = %d\n", j, primes[j]);
                fflush(stdout);
            #endif
            if(no % primes[j] == 0)
            {
                pair<int, int> f = make_pair(j, 0);
                while(no % primes[j] == 0)
                {
                    f.second++;
                    no /= primes[j];
                }
                fact.push_back(f);
            }
        }
        if(no > 1)
        {
            //printf("remainder = i= %d, no = %d\n", i, no);
            assert(isprime[no]);
            fact.push_back(make_pair(rev[no], 1));
        }
        factors.push_back(fact);
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        won.clear();
        for(i = 0; i < n; i++)
        {
            vector<int> nf(primes.size());
            for(j= 0; j < primes.size(); j++) nf[i] = 0;
            iszero[i]= false;
            for(j = 0; j < m; j++)
            {
                scanf("%lf", &jj);
                jj *= 10000;
                int num = floor(jj + 0.5);
                #ifdef DEBUG
                    printf("temp = %lf, num = %d\n", jj, num);
                #endif
                if(num == 0) iszero[i] = true;
                for(k = 0; k < factors[num].size() && iszero[i] == false; k++)
                {
                    #ifdef DEBUG
                        printf("num = %d, temp = %lf factor = %d\n", num, jj * 10000, primes[factors[num][k].first]);
                    #endif
                    nf[factors[num][k].first] += factors[num][k].second;
                    #ifdef DEBUG
                        printf("Done\n");
                    #endif
                }
            }
            won.push_back(nf);
        }
        #ifdef DEBUG
            for(j = 0; j < primes.size(); j++)
            {
                if(won[0][j] > 0) printf("won[0][%d](%d) = %d\n", j, primes[j], won[0][j]);
                if(won[1][j] > 0) printf("won[1][%d](%d) = %d\n", j, primes[j], won[1][j]);
            }
            fflush(stdout);
        #endif
        ans = 0;
        temp = 1;
        if(!iszero[0])
        {
            for(i = 1; i < n; i++)
            {
                if(iszero[i]) continue;
                long double xx = 1, dd = 0;
                for(j = 0; j < primes.size(); j++)
                {
                    
                    if(won[i][j] - won[0][j] != 0)
                    {
                        dd += log(primes[j]) * (won[i][j] - won[0][j]);
                        //xx *= pow(primes[j], won[i][j] - won[0][j]);
                        #ifdef DEBUG
                            printf("i = %d j = %d prime = %d pow = %d\n", i, j, primes[j], won[i][k] - won[0][k]);
                        #endif                        
                    }
                    
                    //temp += ((long double)(won[i][k] - won[0][k])) * log(primes[k]);
                }
                #ifdef DEBUG
                    printf("i = %d xx = %Lf\n", i, xx);
                    fflush(stdout);
                #endif
                //temp += xx;
                temp += exp(dd);
            }
            ans = ((double)1.0) / temp;
            //ans += 0.0000009;
            //ans = ((long double)1.0) / pow(temp, 10);
        }
        printf("%.10lf\n", ans);
    }
    return 0;
}