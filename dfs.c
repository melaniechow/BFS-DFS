#include <stdio.h>
#include <stdlib.h>

#include "is.h"
#include "graph.h"

il *dfs(graph *g, unsigned int start_key)
{
  is *s=is_new();
  il *ret=NULL;
  vertex *v;
  il *neighbors;
  int popped;
  push(s,start_key);
  while (s->ns != NULL){
    //pop off and set V
    popped=pop(s);
    v=g->vs[popped];
    //if not yet visited, push the neighbors & add to ret
    if (!(v->visited)){
      ret=il_snoc(ret,popped);
      neighbors=g->es[popped];
      while (neighbors){
        push(s,neighbors->n);
        neighbors=neighbors->next;
      }
    }
    //mark v as visited
    v->visited=1;
  }
  is_free(s);
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

  printf("--- depth-first search ---\n");
  il *ns = dfs(g,0);
  graph_show_labels(g,ns);
  putchar('\n');

  il_free(ns);
  graph_free(g);

  return 0;
}
