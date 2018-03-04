#include <stdio.h>
#include <stdlib.h>

#include "iq.h"
#include "graph.h"

il *bfs(graph *g, unsigned int start_key)
{
  iq *q=iq_new();
  il *ret=NULL;
  vertex *v;
  il *neighbors;
  int deq;
  enqueue(q,start_key);
  while (q->n){
    deq=dequeue(q);
    v=g->vs[deq];
    //if not yet visited, enqueue the neighbors & add to ret
    if (!(v->visited)){
      ret=il_snoc(ret,deq);
      neighbors=g->es[deq];
      while (neighbors){
        enqueue(q,neighbors->n);
        neighbors=neighbors->next;
        iq_show(q);
      }
    }
    //mark v as visited
    v->visited=1;
  }
  iq_free(q);
  return ret;
}

int main(int argc, char *argv[])
{
  graph *g;
  if (argc>1)
    g = sample_graph(atoi(argv[1]));
  else
    g = sample_graph(0);

  printf("--- graph ---\n");
  graph_show(g);
  putchar('\n');

  printf("--- breadth-first search ---\n");
  il *ns = bfs(g,0);
  graph_show_labels(g,ns);
  putchar('\n');

  il_free(ns);
  graph_free(g);

  return 0;
}
