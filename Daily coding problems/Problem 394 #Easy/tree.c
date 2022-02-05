#include "tree.h"
#define delim ' '

static int count_nodes_in_string(char *string) {
  int index = 0, count = 0;
  while(string[index] != '\0') {
    if(string[index] == delim) {
      count++;
    }
    index++;
  }

  return count + 1;
}

static char** word_break(char *string, int number) {
  int index = 0, count = 0, prev = 0;
  char **words = (char **)malloc(sizeof(char*) * number);

  while(string[index] != '\0') {
    if(string[index] == delim) {
      words[count] = (char *)malloc(sizeof(char) * (index - prev + 1));
      strncpy(words[count], string + prev, index - prev);
      words[count][index - prev] = '\0';
      prev = index + 1;
      count++;
    }
    index++;
  }
  //For last word.
  words[count] = (char *)malloc(sizeof(char) * (index - prev + 1));
  strncpy(words[count], string + prev, index - prev);
  words[count][index - prev] = '\0';
  
  return words;
}

static int convert_to_integer(char *number) {
  int index = 0, result = 0;
  while(number[index] != '\0') {
    result = result * 10 + number[index] - '0';
    index++;
  }
  free(number);
  return result;
}

static char *convert_to_string(int val) {
  int digits = log10(val) + 1, rem;
  int index = digits - 1;
  char *number_to_string = malloc((digits + 1) * sizeof(char));
  if(number_to_string == null) {
    printf("Error: Unable to allocate memory.");
    exit(1);
  }
  while(val > 0) {
    number_to_string[index] = (val % 10 + '0');
    val = val / 10;
    index--;
  }
  number_to_string[digits] = ' ';
  return number_to_string;
}


static TreeNode *create_node(int val) {
  TreeNode *node = malloc(sizeof(TreeNode));
  if(node == null) {
    printf("Error: Unable to allocate memory.");
    exit(1);
  }
  node->val = val;
  node->right = node->left = null;
  return node;
}

static TreeNode *make_tree_helper(char **words, int n, int i) {
  if(i >= n) {
    return null;
  }
  if(strcmp(words[i], "N") == 0) {
    return null;
  }
  TreeNode *root = create_node(convert_to_integer(words[i]));
  root->left = make_tree_helper(words, n, 2 * i + 1);
  root->right = make_tree_helper(words, n, 2 * i + 2);
  return root;
}

static void inorder_helper(TreeNode *root, char **inorder_string) {
  if(root) {
    inorder_helper(root->left, inorder_string);
    char *converted_integer = convert_to_string(root->val);
    if(*inorder_string == null) {
      *inorder_string = strdup(converted_integer);
    }
    else {
      strcat(*inorder_string, converted_integer);
    }
    free(converted_integer);

    inorder_helper(root->right, inorder_string);
  }
  return;
}

static void delete_helper(TreeNode *root) {
  if(root) {
    delete_helper(root->left);
    delete_helper(root->right);
    free(root);
  }
  return;
}


char* inorder(Tree *tree) {
  char *inorder_string = null;
  inorder_helper(tree->root, &inorder_string);
  return inorder_string;
}

Tree *makeTree(char *string) {
  Tree *tree = malloc(sizeof(Tree));
  if(tree == null) {
     printf("Error: Unable to allocate memory.");
     exit(1);
  }
  int nodes = count_nodes_in_string(string);
  char **words = word_break(string, nodes);
  tree->root = make_tree_helper(words, nodes, 0);
  return tree;
}

void deleteTree(Tree *tree) {
  delete_helper(tree->root);
  free(tree);
  tree = null;
}
