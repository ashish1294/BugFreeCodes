#include <cmath>
#include <cstdio>

int main()
{
  float error = 1.0 / 120;
  float h[12], m[61], deg;
  for(int i=0;i<12;i++)
    h[i] = i * 30;
  for(int i=0;i<60;i++)
    m[i] = i * 6;
  int t;
  scanf("%d", &t);
  while(t--)
  {
    float diff;
    scanf("%f", &diff);
    for(int i = 0;i < 12; i++)
    {
      for(int j = 0;j < 60; j++)
      {
        deg = fabs(m[j] - (h[i] + j/2.0));
        if(deg >= 180)
          deg = 360 - deg;
        if(fabs(deg - diff) <= error)
        {
          printf("%02d:%02d\n",i, j);
        }
      }
    }
  }
  return 0;
}
