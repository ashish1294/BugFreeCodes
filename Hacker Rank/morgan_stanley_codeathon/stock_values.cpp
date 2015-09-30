#include <cstdio>
#include <cstdlib>
using namespace std;
int arr[25], t, n, min;
int compute_sum()
{
  int sum = 0, lim;
  if(n % 2 == 0) lim = (n / 2) - 1;
  else lim = ((int) (n / 2) ) - 1;
  for(int i = 0; i <= lim; i++)
  {
    sum += abs(arr[i] - arr[n - 1 - i]);
  }
  return sum;
}
void solve(int i)
{
  if(i == n - 1) return;
  int sum = 0;
  if( (arr[i - 1] % 2 == 0) && (arr[i + 1] % 2 == 0) )
  {
    int temp = arr[i];
    arr[i] = (arr[i + 1] + arr[i - 1] ) / 2;
    sum = compute_sum();
    //printf("i = %d, changed sum = %d\n", i , sum);
    if(min < sum) min = sum;
    solve(i + 1);
    arr[i] = temp;
  }
  solve(i + 1);
}
int main()
{
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    min = compute_sum();
    //printf("Min SUm init = %d\n", min);
    solve(1);
    printf("%d\n", min);
  }
  return 0;
}
