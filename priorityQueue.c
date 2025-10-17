#include <stdio.h>
#define MS 20 

typedef struct
{
  int arr[MS];
  int rear;
} PQ;


void init(PQ *pq)
{
  pq->rear = -1;
}


void enqueue(PQ *ptr, int val)
{
  if (ptr->rear == MS - 1)
  {
    printf("Priority Queue is full!\n");
    return;
  }
  else
  {
    ptr->rear++;
    ptr->arr[ptr->rear] = val;
    int c = ptr->rear;

    while (c != 0)
    {
      int p = (c - 1) / 2; 
      if (ptr->arr[p] > ptr->arr[c])
      {
        int t = ptr->arr[p];
        ptr->arr[p] = ptr->arr[c];
        ptr->arr[c] = t;
        c = p;
      }
      else
        break;
    }
  }
}


int dequeue(PQ *ptr)
{
  if (ptr->rear == -1)
  {
    printf("Priority Queue is empty!\n");
    return -1;
  }
  else
  {
    int t = ptr->arr[0];
    ptr->arr[0] = ptr->arr[ptr->rear];
    ptr->rear--;

    int p = 0, c;
    do
    {
      c = 2 * p + 1;
      if (c > ptr->rear)
        break; 

      
      if (c < ptr->rear && ptr-> arr[c] > ptr->arr[c + 1])
      {
        c = c + 1;
      }
        
      if (ptr->arr[p] > ptr->arr[c])
      {
        int temp = ptr->arr[p];
        ptr->arr[p] = ptr->arr[c];
        ptr->arr[c] = temp;
        p = c;
      }
      else
        break; 

    } while (c <= ptr->rear);

    return t;
  }
}


void display(PQ *pq)
{
  if (pq->rear == -1)
  {
    printf("Priority Queue is empty!\n");
    return;
  }

  printf("Priority Queue (Heap): ");
  for (int i = 0; i <= pq->rear; i++)
  {
    printf("%d ", pq->arr[i]);
  }
  printf("\n");
}


int main()
{
  PQ pq;
  init(&pq);
  int choice, val, res;

  while (1)
  {
    printf("\n--- Priority Queue Menu ---\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value to insert: ");
      scanf("%d", &val);
      enqueue(&pq, val);
      break;
    case 2:
      res = dequeue(&pq);
      if (res != -1)
        printf("Dequeued element: %d\n", res);
      break;
    case 3:
      display(&pq);
      break;
    case 4:
      return 0;
    default:
      printf("Invalid choice!\n");
    }
  }
}