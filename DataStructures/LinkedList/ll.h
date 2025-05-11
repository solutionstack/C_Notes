#ifndef LL_H
#define LL_H

typedef struct node {
  int value;
  struct node *next;
} Node;

Node *Nalloc(void);
Node *insert_at_head(Node *, int);
Node *insert_at_tail(Node *, int);
Node *delete_at_index(Node *, int);
Node *search_list(Node *, int);
Node *reverse_list(Node *);
void print_node(Node *);
int len_list(Node *);

#endif // LL_H
