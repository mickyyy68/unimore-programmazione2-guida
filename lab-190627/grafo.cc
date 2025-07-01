/*
 * grafi.cc
 *
 *  Created on: 29 mag 2018
 *      Author: federica
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

#include "grafi.h"

graph new_graph(int n){
	graph G;
	G.dim=n;
	G.nodes= new adj_list[n];
	  for (int i=0; i<n; i++) {
	    G.nodes[i] = NULL;  //indicazione di lista vuota
	  }
	  return G;

}

/* Funzione che aggiunge l'arco orientato (u,v) alla lista di adiacenza del
 * nodo u (aggiunge in testa alla lista). L'arco ha peso w. */

void add_arc(graph& G, int u, int v, float w) {
  adj_node* t = new adj_node;
  t->node = v-1;
  t->weight = w;
  t->next = G.nodes[u-1];
  G.nodes[u-1] = t;
}


/* Funzione che aggiunge l'arco non orientato (u,v) alle liste
 * di adiacenza di u e v. L'arco ha peso w. */
void add_edge(graph& g, int u, int v, float w) {
  add_arc(g,u,v,w);
  add_arc(g,v,u,w);
}


int get_dim(graph g){
	return g.dim;
}

adj_list get_adjlist(graph g,int u){
	return g.nodes[u-1];
}

int get_adjnode(adj_list l){
	return (l->node+1);
}

adj_list get_nextadj(adj_list l){
	return l->next;
}

void print_graph(graph g) {
    for (int i = 1; i <= get_dim(g); ++i) {
        cout << i << ": ";
        adj_list l = get_adjlist(g, i);
        while (l != NULL) {
            cout << get_adjnode(l) << " ";
            l = get_nextadj(l);
        }
        cout << endl;
    }
}
