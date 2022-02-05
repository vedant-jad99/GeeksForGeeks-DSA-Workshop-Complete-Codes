#include <stdio.h>
#include <string.h>
#include "tree.h"

static unsigned test_tree_lib(const char *, int, char *, char *);

#define TEST_BINARY_TREE(input, expected) failures += test_tree_lib(__FILE__, __LINE__, input, expected)

static unsigned test_tree_lib(const char *file, int line, char *input, char *expected) {
  Tree *tree = makeTree(input);
  char *inorder_traversal = inorder(tree);
  int result = strcmp(inorder_traversal, expected);
  printf("%s\n", inorder_traversal);
  free(inorder_traversal);
  deleteTree(tree);
  return result == 0;
}

int main() {
  unsigned failures = 0;
  unsigned test = 3;

  char test1[] = "1 2 3 4";
  TEST_BINARY_TREE(test1, "4 2 1 3 ");
  char test2[] = "4 2 6 1 3 5 7";
  TEST_BINARY_TREE(test2, "1 2 3 4 5 6 7 ");
  char test3[] = "50 30 60 5 20 45 70 N N N N N N 65 80";
  TEST_BINARY_TREE(test3, "5 30 20 50 45 60 65 70 80 ");

  printf("\n---------------- Tests completed ----------------\n");
  printf("\n---------------- Total tests : %u ---------------\n", test);
  printf("\n-------------- Successful tests : %u ------------\n", failures);
  return failures > 0;
}
