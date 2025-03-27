//
// Created by olu on 13/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "../get_next_line.h"

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;

};

struct tnode *addtree(struct tnode *, char *);

struct tnode *talloc(void);

void treeprint(struct tnode *);

int main() {

    struct tnode *root = NULL;
    char *line;

    while ((line = get_next_line()) != NULL) {
        if (isalpha(*line)) {
            root = addtree(root, line);
        }
    }
    treeprint(root);
}

struct tnode *addtree(struct tnode *n, char *w) {
 size_t line_len = strlen(w);
    int cond;
    char *tmp = (char *) malloc(line_len + 1);
    if (n == NULL) {
        n = talloc(); //new node
        n->word = memcpy(tmp, w, line_len + 1);
        n->count = 1;
        n->left = n->right = NULL;
    } else if ((cond = strcmp(w, n->word)) == 0)
        n->count++;
    else if (cond < 0) //less than current root so go to left substree
        n->left = addtree(n->left, w);
    else
        n->right = addtree(n->right, w); //greater than current root so go to right substree
    return n;
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}


void treeprint(struct tnode *n) {//in order traversal
    if (n != NULL) {

        treeprint(n->left);
        printf("%4d %s\n", n->count, n->word);
        treeprint(n->right);
    }
}
# define CORVID_NAME /**/ \
(char const*const[corvid_num]){ \
[chough] = "chough", \
[raven] = "raven", \
[magpie] = "magpie", \
[jay] = "jay", \
}
