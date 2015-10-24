/*
    https://www.quora.com/challenges#upvotes
    Author - Ashish Kedia (@ashish1294)
    National Institute of Technology Karnataka, Surathkal, India
    <a>https://www.ashishkedia.me</a>
    ashish1294@gmail.com
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#define min(a,b) (a < b? a: b)
using namespace std;
int arr[100010];
/*
    inc_st denotes the number of non-decreasing sub-ranges starting from index i
    dec_st denotes the number of non-increasing sub-ranges starting from index i
    inc_en denotes the number of non-decreasing sub-ranges ending on index i
    dec_en denotes the number of non-increasing sub-ranges ending on index i
    curr_inc denotes the total number of non-decreasing sub-ranges in current
        window
    curr_dec denotes the total number of non-increasing sub-ranges in current
        window
*/
long long int inc_st[100010], dec_st[100010], inc_en[100010], dec_en[100010];
int brute(int st, int en)
{
    int inc = 0;
    for(int i = st; i < en; i++)
    {
        for(int j = i + 1; j <= en; j++)
        {
            if(arr[j] >= arr[j - 1]) inc++;
            else break;
        }
        for(int j = i + 1; j <= en; j++)
        {
            if(arr[j] <= arr[j - 1]) inc--;
            else break;
        }
    }
    return inc;
}
int main()
{
    int n, k;
    long long curr_inc = 0, curr_dec = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    inc_st[n - 1] = 0, dec_st[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--)
    {
        inc_st[i] = arr[i] <= arr[i + 1] ? inc_st[i + 1] + 1 : 0;
        dec_st[i] = arr[i] >= arr[i + 1] ? dec_st[i + 1] + 1 : 0;
        //printf("dec start[%d] = %lld\n", i, dec_st[i]);
    }
    inc_en[0] = 0, dec_en[0] = 0;
    for(int i = 1; i < n; i++)
    {
        inc_en[i] = arr[i] >= arr[i - 1] ? inc_en[i - 1] + 1 : 0;
        dec_en[i] = arr[i] <= arr[i - 1] ? dec_en[i - 1] + 1 : 0;
    }
    for(int i = 0; i < n; i++)
    {
        /*
            In a given window of length k the maximum number of sub-ranges that
            can start from the first element will be k - 1
        */
        inc_st[i] = min(k - 1, inc_st[i]);
        dec_st[i] = min(k - 1, dec_st[i]);
        inc_en[i] = min(k - 1, inc_en[i]);
        dec_en[i] = min(k - 1, dec_en[i]);
        //printf("dec start[%d] = %lld\n", i, dec_st[i]);

    }

    //Initializing inc_en, dec_en, curr_inc, curr_dec
    for(int i = 1; i < k - 1; i++)
    {
        curr_inc += inc_en[i];
        curr_dec += dec_en[i];
        //printf("%d = %d\n", i, curr_inc);
    }
    for(int i = 0; i <= n - k; i++)
    {
        /*
            Computing result for window i to i + k - 1
        */
        //printf("curr 1= %d %d\n", curr_inc, curr_dec);
        curr_inc += inc_en[i + k - 1];
        curr_dec += dec_en[i + k - 1];
        printf("%lld\n", curr_inc - curr_dec);
        //printf("curr 2= %d %d\n", curr_inc, curr_dec);
        //int br = brute(i, i + k - 1);
        //printf("brute = %d algo = %d\n", br, curr_inc - curr_dec);
        //if(br != curr_inc - curr_dec)
        //{
        //    printf("Failed \n");
        //    return 0;
        //}
        curr_inc -= inc_st[i];
        curr_dec -= dec_st[i];
        //printf("curr 3= %d %d\n", curr_inc, curr_dec);
    }
    //printf("%d", curr_inc - curr_dec);
    return 0;
}
