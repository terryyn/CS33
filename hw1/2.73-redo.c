#include<stdio.h>
#include<limits.h>

int saturating_add(int x,int y)
{
  int result= x+y;
  int temp;
  __builtin_add_overflow_p( x, y,(int)0) &&( result=INT_MAX);
  __builtin_uadd_overflow(x,y,&temp) && (result=INT_MIN);
  return result;
  
}

int main(void)
{
  int test1=0x80000000;
  int test2=0xF2132133;
  int test3=0x45521535;
  int test4=0x41232133;
  printf("%d", saturating_add(test1,test2));
  printf("\n");
  printf("%d", saturating_add(test3,test4));
  printf("\n");
  return 0;
}
