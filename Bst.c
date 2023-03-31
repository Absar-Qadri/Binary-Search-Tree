#include<iostream>
using namespace std;

class Node{
public:
    Node *left;
    int val;
    Node *right;
};

Node *bst = NULL;

Node *createNode(){
    Node *newNode;
    newNode = new Node;
    return newNode;
}

void insert(Node **root, int key){
    Node *newNode;
    newNode = createNode();
    newNode->val = key; newNode->left = NULL; newNode->right = NULL;
    if(*root == NULL){
        *root = newNode;
        return;
    } else {
        if(key < (*root)->val)
            insert(&((*root)->left), key);
        else
            insert(&((*root)->right), key);
    }
}

int findMinElement(){
    if(bst == NULL) {
        return -1; // tree is empty
    }
    Node* current = bst;
    while (current->left != NULL) {
        current = current->left;
    }
    return(current->val);
}

int main(){
    int items[] = {3, 2, 1, 6, 5, 8};
    int n = sizeof(items)/sizeof(items[0]);
    int i;
    for(i = 0; i<n; i++){
        insert(&bst, items[i]);
    }
    cout << "Minimum element is: " << findMinElement() << endl;
    return 0;
}
