#include "is.h"

is *is_new()
{
  is *s = (is*)malloc(sizeof(is));
  if (s==NULL) {
    fprintf(stderr,"is_new: malloc failed\n");
    exit(1);
  }
  s->ns = NULL;
  return s;
}

void push(is *s, int n)
{
  //add to front of list
  il *list=il_cons(n,s->ns);
  //update stack
  s->ns=list;
}

int pop(is *s)
{
  //store n value
  il *popped=s->ns;
  int ret=popped->n;
  //update front of list
  s->ns=popped->next;
  free(popped);
  return ret;
}

void is_show(is *s)
{
  printf("begin stack (%d items, top shown at left)\n",il_len(s->ns));
  printf("  ");
  il_show(s->ns);
  printf("end stack\n");
}

void is_free(is*s)
{
  if (s!=NULL) {
    il_free(s->ns);
    free(s);
  }
}
