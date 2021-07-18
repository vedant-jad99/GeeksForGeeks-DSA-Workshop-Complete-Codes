/*
Link to the question - https://practice.geeksforgeeks.org/problems/pairs-violating-bst-property/1/?category[]=Algorithms&category[]=Algorithms&page=1&query=category[]Algorithmspage1category[]Algorithms#
*/

struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

void inorder(Node *root, vector<int> &v) {
    if(root) {
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
}
int mergeSort(vector<int> &, int, int);
int merge(vector<int> &, int, int, int);


int pairsViolatingBST(Node *root,int n){
          /*Your code here */
    
    vector<int> v;
    inorder(root, v);
          
    return mergeSort(v, 0, v.size() - 1);
}

int mergeSort(vector<int> &v, int p, int q) {
    if(p == q)
        return 0;
    
    int mid = (p + q)/2;
    int a = mergeSort(v, p, mid);
    int b = mergeSort(v, mid + 1, q);
    
    return merge(v, p, mid, q) + a + b;
}
int merge(vector<int> &v, int p, int mid, int q) {
    int A[mid - p + 1], B[q - mid];
    for(int i = p, c = 0; i <= mid; i++, c++)
        A[c] = v[i];
    for(int i = mid + 1, c = 0; i <= q; i++, c++)
        B[c] = v[i];
        
    int inversions = 0;
    int c = p, i = p, j = mid + 1;

    while(i <= mid && j <= q) {
        if(A[i - p] < B[j - mid - 1]) {
            v[c++] = A[i - p];
            i++;
        }
        else {
            v[c++] = B[j - mid - 1];
            j++;
            inversions += mid - i + 1;
        }
    }

    while(i <= mid) {
        v[c++] = A[i - p];
        i++;
    }
    while(j <= q) {
        v[c++] = B[j - mid - 1];
        j++;
    }

    return inversions;
}


//Diver code with main and function to construct tree.
