#include <stdio.h>

int bit(int x, int i)
{
  return (x>>i)&1;
}

int main()
{
  for(int v=0;v<16;v++)
  {
    printf("%d   %d   %d   %d   %d\n", v, bit(v,0), bit(v,1), bit(v,2), bit(v,3));
  }
}
