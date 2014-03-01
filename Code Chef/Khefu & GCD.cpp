#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <cmath>
using namespace std;

const long int N1 = 10000001, N2=10000001;
bool isPrime[N1];
static long int prime[N2], nPrime, totient[N1];

void sieveAndTotient() {
    // reset
    for (long int i = 0; i < N1; ++i)
        totient[i] = i;
    isPrime[0] = isPrime[1] = false;
    for (long int i = 3; i < N1; i += 2)
        isPrime[i] = true;
    for (long int i = 4; i < N1; i += 2)
        isPrime[i] = false;
    nPrime = 0;
    // 2
    // update for 2
    prime[nPrime++] = 2;
    for (long int j = 2; j < N1; j += 2) {
        isPrime[j] = false;
        // totient for 2
        totient[j] -= totient[j] / 2;
    }
    isPrime[2] = true;
    // odds
    for (long int i = 3; i < N1; i += 2)
        if (isPrime[i]) {
            // update for i
            prime[nPrime++] = i;
            if (i < 10000001)
                for (long int j = i; j < N1; j += i) {
                    isPrime[j] = false;
                    // totient for i
                    totient[j] -= totient[j] / i;
                }
            isPrime[i] = true;
        }
}

int main() {
    sieveAndTotient();
    int in,t;
    long int n,i;
    long long int sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=3;
        for(i=2;i<n;i++)
        {
            sum += 2*totient[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
