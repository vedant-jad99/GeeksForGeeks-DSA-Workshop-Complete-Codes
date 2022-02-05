#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#define MAX 1000000

char *parse_input(int argc, char *argv[]) {
    int count = 0, index = 0;
    for(int i = 1; i < argc; i++) {
        count += strlen(argv[i]);
        count += 1;
    }
    char *input = malloc(sizeof(char) * count);
    count = 0;
    
    for(int i = 1; i < argc; i++) {
        for(int j = 0; j < strlen(argv[i]); j++) {
            input[index] = argv[i][j];
            index++;
        }
        input[index] = ' ';
        index++;
    }
    input[index] = '\0';
    return input;
}

int root_path_sum(TreeNode *root, int sum)
{   
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
    {
        if(root->val == sum)
            return 1;
        else
            return 0;
    }
    return root_path_sum(root->left, sum - root->val) + root_path_sum(root->right, sum - root->val);
}

int main(int argc, char *argv[]) {
    int n;
    Tree *tree = makeTree(parse_input(argc, argv));
    scanf("%d", &n);
    printf("%s\n", root_path_sum(tree->root, n) ? "Yes" : "No");
}