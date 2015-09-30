#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <map>
#include <vector>
#include <set>
#define min(a, b) ((a)<(b)?(a):(b))
using namespace std;
char x[20010], u[20010];
int a[26], b[26];
int fast_strx()
{
  register int sum = 0;
  register char p = getchar_unlocked();
  while(p < 'a' || p > 'z') p = getchar_unlocked();
  //printf("char = %c\n", p);fflush(stdout);
  //printf("char = %c\n", p);fflush(stdout);
  while(p >= 'a' && p <= 'z')
  {
    a[(int) (p - 'a')]++;
    sum++;
    p = getchar_unlocked();
  }
  return sum;
}
int fast_stru()
{
  register int sum = 0;
  register char p = getchar_unlocked();
  while(p < 'a' || p > 'z') p = getchar_unlocked();
  //printf("char = %c\n", p);fflush(stdout);
  //printf("char = %c\n", p);fflush(stdout);
  while(p >= 'a' && p <= 'z')
  {
    b[(int) (p - 'a')]++;
    sum++;
    p = getchar_unlocked();
  }
  return sum;
}
int main()
{
  int t, de, in, re, lenx, lenu;
  scanf("%d", &t);
  while(t--)
  {
    for(int i = 0; i < 26; i++) a[i] = b[i] = 0;
    //scanf("%s", x);
    //scanf("%s", u);
    //printf("Inputing\n");fflush(stdout);
    lenx = fast_strx();
    //printf("1\n");fflush(stdout);
    lenu = fast_stru();
    //printf("2\n");fflush(stdout);
    scanf("%d%d%d", &de, &in, &re);
    //printf("3\n");fflush(stdout);
    //for(int i = 0; i < strlen(x); i++) a[x[i] - 'a']++;
    //for(int i = 0; i < strlen(u); i++) b[u[i] - 'a']++;
    int extra = 0;
    for(int i = 0; i < 26; i++)
    {
      if(a[i] > b[i]) extra += a[i] - b[i];
    }
    int del = lenx - lenu;
    int cost = 0;
    //printf("ex = %d del = %d\n", extra, del);
    if(del > 0)
    {
      cost += de * del;
      cost += (extra - del) * min(re, in + de);
    }
    else
    {
      del = - del;
      cost += in * del;
      cost += extra * min(re, in + de);
    }
    printf("%d\n", cost);
  }
  return 0;
}
