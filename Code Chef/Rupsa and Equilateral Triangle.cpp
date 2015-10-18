#include <cstdio>
#include <cstdlib>
#include <vector>
#define MAX 2237
int ispr[5000010], is_hyp[5000010];
std::vector<int> factors, pprimes;
int main()
{
    int t = 1, n;
    ispr[2] = 1;
    is_hyp[0] = is_hyp[1] = is_hyp[2] = 0;
    for(int i = 3; i < 5000000; i+=2)
    {
        ispr[i] = 1;
        ispr[i + 1] = 0;
    }
    for(long long int i = 3; i <= 5000000; i += 2)
    {
        if(ispr[i])
        {
            for(long long int j = i * i; j <= 5000000; j += i)
            {
                ispr[j] = 0;
            }
            if(i % 4 == 1) pprimes.push_back(i);
        }
        is_hyp[i] = 0;
    }
    for(int i = 0; i < pprimes.size(); i++)
    {
        for(int j = 1; pprimes[i] * j <= 5000000; j++) is_hyp[pprimes[i] * j] = 1;
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(is_hyp[n]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
