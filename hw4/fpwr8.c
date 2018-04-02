static float u2f(unsigned u)
{
  union number
  {
    int integer;
    float decimal;
  }x;
  x.integer = u;
  float result = x.decimal;
  return result;

}

float fpwr8(int x)
{
  unsigned exp,frac;
  unsigned u;
  if(x < -49) /* smallest float 2^-23 * 2^ -126 = 2^-149 < 8^-49) */
    {
      exp = 0;
      frac = 0;
    }
  else if( x < -42  )/* smallest normalized : 1*2^-127 = 2^-127 < 8^-42 */
    {
      exp=0;
      frac =1<<(3*x+149);
    }
  else if (x < 43) /* biggest float: (1+1-2^-23)* 2^127 = 2^128-2^104 < 8^43 */
    {
      exp = 3*x + 127;
      frac = 0;
    }
  else
    {
      exp = 2**8 - 1;
      frac = 0;
    }
  u = exp << 23 | frac;
  return u2f(u);
}
