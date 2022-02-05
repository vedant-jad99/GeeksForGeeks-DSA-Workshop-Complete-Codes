#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define null NULL

#endif

typedef struct tree_node {
  int val;
  struct tree_node *left, *right;
} TreeNode;
typedef struct tree {
  TreeNode *root;
} Tree;

static int count_nodes_in_string(char *);
static char** word_break(char *string, int n);
static int convert_to_integer(char *);
static char *convert_to_string(int val);
static TreeNode *create_node(int);
static TreeNode *make_tree_helper(char **, int, int);
static void inorder_helper(TreeNode *, char **);
static void delete_helper(TreeNode *);

char* inorder(Tree *);
Tree *makeTree(char *);
void deleteTree(Tree *);
