#include "iq.h"

iq *iq_new()
{
  iq *q = (iq*)malloc(sizeof(iq));
  if (q==NULL) {
    fprintf(stderr,"iq_new: malloc failed\n");
    exit(1);
  }
  q->n = 0;
  q->front = q->back = NULL;
  return q;
}

void enqueue(iq *q, int n)
{
  il *end=q->back;
  end=il_snoc(end,n);
  if (q->n == 0){
    q->front=end;
  }
  //update end of queue
  q->n++;
  q->back=end;
}

int dequeue(iq *q)
{
  il *front=q->front;
  //update front of queue
  if (front->next == NULL){
    q->front=NULL;
    q->back=NULL;
  }
  else {
    q->front=front->next;
  }
  q->n--;
  //return first element
  return front->n;
}

void iq_show(iq *q)
{
  printf("begin queue (%d items, front shown at left))\n",q->n);
  printf("  ");
  il_show(q->front);
  printf("end queue\n");
}

void iq_free(iq *q)
{
  if (q!=NULL) {
    il_free(q->front);
    free(q);
  }
}
