#include<stdio.h>
#include<limits.h>
int saturating_add(int x,int y)
{
  int vol_bits= sizeof(int)<<3;
  int msb_x= x>>(vol_bits-1);
  int msb_y= y>>(vol_bits-1);
  msb_x= !!(msb_x);
  msb_y= !!(msb_y);
  int msb_x_and_y=(x+y)>>(vol_bits-1);
  msb_x_and_y= !!(msb_x_and_y);
  int  positiveFlow = (msb_x==0)& (msb_y==0)&(msb_x_and_y==1);
  int  negativeFlow = (msb_x==1)& (msb_y==1)&(msb_x_and_y==0);
  int result=0;
  result= x+y;
  positiveFlow && (result=INT_MAX); /* it will assingn max to result if positive flow but won't otherwise*/ 
  negativeFlow && (result=INT_MIN); /* same method*/
  return result;
}

int main()
{
  int test1= 0x80000000;
  int test2= 0xF2133122;
  int test3= 0x55555555;
  int test4= 0x52132132;
  printf("%d", saturating_add(test1,test2));
  printf("\n");
  printf("%d", saturating_add(test3,test4));
  printf("\n");
  return 0;
}

