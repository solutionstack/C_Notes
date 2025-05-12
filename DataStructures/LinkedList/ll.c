#include "ll.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

Node *Nalloc(void) {
  Node *np = malloc(sizeof(Node));
  assert(np != NULL);
  np->next = NULL;

  return np;
}
Node *insert_at_head(Node *head, int val) {
  Node *new_n = Nalloc();
  new_n->value = val;

  return !head ? new_n : (new_n->next = head), new_n;
}

Node *insert_at_tail(Node *head, int val) {
  Node *new_n = Nalloc();
  new_n->value = val;

  if (!head)
    return new_n;

  Node *curr = head;
  while (curr && curr->next) { // loop till curr->next is NULL
    curr = curr->next;
  }
  curr->next = new_n;
  return head;
}

void print_node(Node *list) {

  if (!list)
    return;
  int idx = 0;
  do {
    printf("current node{%d} val : %d: %p\n", idx++, list->value, list);
  } while ((list = list->next));
}

int len_list(Node *list) {

  if (!list)
    return 0;
  int len = 0;
  while (list) {
    list = list->next;
    ++len;
  }
  return len;
}
void free_list(Node *head) {

  if (!head)
    return;
  if (head->next) // recurse till no valid next node and free on the rewind
    free_list(head->next);

  free(head);
}

Node *delete_at_index(Node *list, int index) {
  if (!list) {
    return list;
  };

  int c = 0;
  Node *current = list;
  Node *previous = NULL;
  do {

    if (c == index) {
      if (previous) // for index = 0, prev isn't set yet
        previous->next = current->next;

      if (c == 0) // if we're deleting the start of the list reset list
                  // to point to the next node
        list = current->next;

      free(current);
      current = NULL;

      return list;
    }

  } while (previous = current, (current = current->next) && ++c);

  return list;
}

Node *search_list(Node *head, int val) {

  Node *curr = head;

  while (curr) {
    if (val == curr->value) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

Node *reverse_list(Node *list) {

  Node *prev = NULL;
  Node *current = list;
  Node *next = NULL;

  while (current) {
    next = current->next;
    current->next = prev;

    prev = current;
    current = next;
  }
  return prev;
}
/*Node *reverse_list(Node *list) {*/
/**/
/*  int len = len_list(list);*/
/*  if (!len)*/
/*    return list;*/
/*  Node *current = list;*/
/*  Node *next = NULL;*/
/*  Node *next2 = NULL;*/
/**/
/*  while (current) {*/
/*    next = next2 ? next2 : current->next;*/
/**/
/*    if (current == list)*/
/*      current->next = NULL; // if we're processing the head node set its next
 * to*/
/*                            // NULL as other nodes would point to it in
 * reverse*/
/**/
/*    while (next) {*/
/*      next2 = next->next;*/
/*      next->next = current;*/
/*      current = next;*/
/*      break;*/
/*    }*/
/*    if (!next2 || !next)*/
/*      break;*/
/*  }*/
/*  return current;*/
/*}*/
int main(void) {

  Node *n = Nalloc(), *p;
  n->value = 10;

  p = insert_at_head(n, 25);
  p = insert_at_tail(p, 26);

  p = insert_at_head(p, 2);
  print_node(p);

  printf("\n After delete ...\n");
  p = delete_at_index(p, 0);

  print_node(p);

  p = reverse_list(p);

  printf("After reverse\n");
  print_node(p);

  free_list(p);
}
