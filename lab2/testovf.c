#include <stdio.h>
_Bool testovf (long n)
{
  return n + -321 < n;
}

int main()
{
  printf("%d",testovf(-1));
  return 0;
}
