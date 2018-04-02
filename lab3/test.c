#include<unistd.h>

int main()
{
  unlink("target.txt");
  return 0;
}
