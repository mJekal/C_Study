#include <stdio.h>

int main(void)
{
  int m = 0;
  int n = 0;
  int x;
  int max = 0;
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      scanf("%d", &x);
      if (max < x)
      {
        max = x;
        n = i;
        m = j;
      }
    }
  }
  printf("%d\n", max);
  printf("%d %d\n", n + 1, m + 1);
  return 0;
}