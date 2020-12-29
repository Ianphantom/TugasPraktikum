#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t 
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);

    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
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

    if (temp->key == value)
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

int bst_left(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if(temp->key == value) {
        if(temp->left!=NULL) {
            temp = temp->left;
            return temp->key;
        }
    }
    return -1;
}

int bst_right(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if(temp->key == value) {
        if(temp->right!=NULL) {
            temp = temp->right;
            return temp->key;
        }
    }
    return -1;
}

BSTNode* __bst__searchParent(BSTNode *root, int value) {
    BSTNode *temp = NULL;
    while (root != NULL) {
        if (value < root->key) {
            temp = root;
            root = root->left;
        }else if (value > root->key){
            temp = root;
            root = root->right;
        }else{
            return temp;
        }
    }
    return temp;
}

int bst_findParent(BST *bst, int value) {
    BSTNode *temp = __bst__searchParent(bst->_root, value);
    if(temp == NULL) {
        return -1;
    } else {
        return temp->key;
    }
}

int main()
{
    BST tree;
    bst_init(&tree);
    int banyak, init,i;
    int nilai1, nilai2;
    scanf("%d", &banyak);
    while(banyak>0){
        scanf("%d", &init);
        if(init == 1) {
            int angka;
            scanf("%d", &angka);
            bst_insert(&tree, angka);
        }else if(init == 2) {
            int angka;
            char string[1000];
            scanf("%s %d", string, &angka);
            if(strcmp(string, "anaK") == 0) {
                nilai1 = bst_left(&tree, angka);
                nilai2 = bst_right(&tree, angka);
                if(nilai1<1 && nilai2<1) {
                    printf("diManakah Anak- aNakkuu :(\n");
                    break;
                }
                if(nilai1<1) printf("- ");
                else printf("%d ", nilai1);
                if(nilai2<1) printf("-\n");
                else printf("%d\n", nilai2);
            }else if(strcmp(string, "ibU") == 0) {
                int a;
                a = bst_findParent(&tree, angka);
                if(a == -1) printf("Aku adalaH sesepuH\n");
                else printf("%d\n", a);
            }
        }
        banyak--;
    }
}