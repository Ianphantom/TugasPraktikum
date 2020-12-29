#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct bstnode_t {
    int data;
    struct bstnode_t *left, *right, *parent;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->data = value;
    newNode->parent = NULL;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->data) {
        root->left = __bst__insert(root->left, value);
        root->left->parent = root;
    }
    else if (value > root->data) {
        root->right = __bst__insert(root->right, value);
        root->right->parent = root;
    }
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}
 
int main() {
    int banyak, node, testCase,i;
    
    BST cemara;
    bst_init(&cemara);
    
    BSTNode *temp = NULL;
    
    scanf("%d", &banyak);
    for (i = 0; i < banyak; i++) {
        scanf("%d", &node);
        bst_insert(&cemara, node);
    }
    scanf("%d", &testCase);
    while(testCase > 0) {
        scanf("%d", &node);
        if (bst_find(&cemara, node)) {
            temp = __bst__search(cemara._root, node);
            printf("%d", temp->parent? temp->parent->data:-1);
            if (temp->data == node && temp->left){
                printf(" %d", temp->left->data);    
            }
            if (temp->data == node && temp->right){
                printf(" %d", temp->right->data);    
            } 
            printf("\n");
        } else {
            printf("404 Not Found\n");
        }
        testCase--;
    }
    free(temp);

    return 0;
}