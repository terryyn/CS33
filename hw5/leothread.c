#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int n;
int nthread;
pthread_t* tid;

struct node {
  int id;
  int level;
};

int leonardo(int a )
{
  int temp1,temp2;
  if(a == 0 || a== 1)
    {
      return 1;
    }
  temp1 = leonardo(a-1);
  temp2 = leonardo(a-2);
  return (temp1+temp2+1);
}

void* thread(void* vargp)
{
  struct node test = *((struct node*)vargp);
  struct node left;
  struct node right;
  int i = test.id;
  int level  = test.level;
  if(level == 0 || level ==1)
   {
      printf("[%d]\n",i);
      return NULL;
    }
  int temp1 = i+1;
  int temp2 = i+1+leonardo(level-1);
  level --;
  left.level = level;
  right.level = level;
  left.id = temp1;
  right.id = temp2;
  if(temp1 <= nthread && temp2<=nthread )
    {
      printf("(%d\n",i);
      pthread_create(&tid[temp1],NULL,thread,&left);
      pthread_join(tid[temp1],NULL);
      pthread_create(&tid[temp2],NULL,thread,&right);
      pthread_join(tid[temp2],NULL);
      printf("%d)\n",i);
    }
  else
    {
      printf("[%d]\n",i);
    }
  return NULL;
}

int main(int argc , char** argv)
{
  int a;
  int i=0;
  if(argc != 2)
    {
      printf("wrong number of arguments");
      exit(1);
    }
  a = atoi(argv[1]);
  if(a == 1 || a==0)
    {
      /*main thread is a leaf code now  */
      printf("[0]\n");
      exit(0);
    }
  
  nthread = leonardo(a)-1;
  n = a;
  tid = malloc(nthread * sizeof(pthread_t));
  if(tid == NULL)
    {
      printf( "allocation error");
      exit(1);
    }
  struct node temp;
  temp.id = 0;
  temp.level = n;
  pthread_create(&tid[0],NULL,thread, (void*)&temp);
  pthread_join(tid[0],NULL);
  free(tid);
  exit(0);
}
