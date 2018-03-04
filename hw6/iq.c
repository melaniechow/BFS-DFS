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

void enqueue(iq *q,int n)
{
  il *old=q->back;
  il *end=il_singleton(n);
  //if empty
  if (q->n == 0){
    q->front=end;
  } else{
    old->next=end;
  }
  q->back=end;
  q->n++;
}

int dequeue(iq *q)
{
  il *old=q->front;
  il_show(old);
  //update front of queue
  if (old->next == NULL){
    q->front=NULL;
    q->back=NULL;
  }
  q->front=old->next;
  q->n--;
  int ret=old->n;
  free(old);
  return ret;
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
