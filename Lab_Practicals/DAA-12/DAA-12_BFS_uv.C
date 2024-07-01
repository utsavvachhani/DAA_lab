#include<stdio.h>
#include<stdlib.h>
struct queue
{
  int size;
  int f;
  int r;
  int* arr;
};
int isempty(struct queue *q)
{
   if(q->r==q->f)
   {
    return 1;
   }
   return 0;
}
int isfull(struct queue *q)
{
   if(q->r==q->size-1)
   {
    return 1;
   }
   return 0;
}
void enqueue(struct queue *q,int val)
{
   if(isfull(q))
   {
     printf("the Queue is full");
   }
   else
    {
      q->r++;
      q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q)
{
 int a=-1;
 if(isempty(q))
 {
   printf("This Queue is empty");
 }
 else
  {
    q->f++;
    a=q->arr[q->f];
  }
  return a;
}
int main()
{
  //initializing Queue (array Implementation
  struct queue q;

  int node;
  int i=1,j;
  int visited[7]={0,0,0,0,0,0,0};

  //BFS Implementation
int  a[7][7]={
	    {0,1,1,1,0,0,0},
	    {1,0,1,0,0,0,0},
	    {1,1,0,1,1,0,0},
	    {1,0,1,0,1,0,0},
	    {0,0,1,1,0,1,1},
	    {0,0,0,0,1,0,0},
	    {0,0,0,0,1,0,0}
	  };
	printf("Code by utsav vachhani(UV)");
	printf("\nBFS is \n");
q.size=400;
  q.f=q.r=0;
  q.arr=(int*)malloc(q.size*sizeof(int));
	  printf("%d-->",i);
	  visited[i]=1;
	  enqueue(&q,i); //Enqueue i for exploration
	  while(!isempty(&q))
	  {
	    node=dequeue(&q);
	    for(j=0;j<7;j++)
	    {
	      if(a[node][j]==1 && visited[j]==0)
	      {
	       printf("%d-->",j);
	       visited[j]=1;
	       enqueue(&q,j);
	      }
	    }
	  }
return 0;
}