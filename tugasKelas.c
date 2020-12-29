#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#define MAX_ELE 16
#define MAX_HD  16 

struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height; 
}; 
typedef struct nodeHitung{
    int data;
    struct nodeHitung *sebelum, *sesudah;
}nodeHitung;

nodeHitung* newnodeHitung(int data)
{
    struct nodeHitung* temp = (struct nodeHitung*) malloc(sizeof(struct nodeHitung));
    temp->data = data;
    temp->sebelum = temp->sesudah = NULL;
    return temp;
}

int max(int a, int b); 

int height(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

struct Node* newNode(int key) 
{ 
    struct Node* node = (struct Node*) 
                        malloc(sizeof(struct Node)); 
    node->key   = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1; 
    return(node); 
} 
struct Node *rightRotate(struct Node *y) 
{ 
    struct Node *x = y->left; 
    struct Node *T2 = x->right;  
    x->right = y; 
    y->left = T2; 

    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 

    return x; 
} 

struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *T2 = y->left; 
    y->left = x; 
    x->right = T2; 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
    return y; 
} 
int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
struct Node* insert(struct Node* node, int key) 
{ 
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else 
        return node; 

    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
    int balance = getBalance(node);  
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
    return node; 
} 
int sums[MAX_HD + 1] = {0, };

void jumlah(struct Node *tree, int hd)
{
    
    int index = hd + MAX_HD / 2;

    if (tree == NULL) {
        return ;
    }

    sums[index] += tree->key;

    if (tree->left != NULL) {
        jumlah(tree->left, hd - 1);
    }
    if (tree->right != NULL) {
        jumlah(tree->right, hd + 1);
    }
}
void jumlahCoba1(struct Node *root, nodeHitung *jumlahNode)
{
    jumlahNode->data = jumlahNode->data + root->key;

    if(root->left)
    {
        if(jumlahNode->sebelum == NULL)
        {
            jumlahNode->sebelum = newnodeHitung(0);
            jumlahNode->sebelum->sesudah = jumlahNode;
        }
        jumlahCoba1(root->left, jumlahNode->sebelum);
    }

    if(root->right)
    {
        if(jumlahNode->sesudah == NULL)
        {
            jumlahNode->sesudah = newnodeHitung(0);
            jumlahNode->sesudah->sebelum = jumlahNode;
        }
        jumlahCoba1(root->right, jumlahNode->sesudah);
    }
}


void jumlahCoba(struct Node* root)
{
    nodeHitung* jumlahNode = newnodeHitung(0);

    jumlahCoba1(root, jumlahNode);

    while(jumlahNode->sebelum != NULL){
        jumlahNode = jumlahNode->sebelum;
    }

    while(jumlahNode != NULL){
        printf("%d ", jumlahNode->data);
        jumlahNode = jumlahNode->sesudah;
    }
}
int main() 
{ 
    struct Node *root = NULL;
    int kasus,i,j;
    char str1[50];
    scanf("%d",&kasus);
    for(j=0;j<kasus;j++){
        scanf("%s",&str1);
        if(strcmp("insert",str1) == 0){
            int angka;
            scanf("%d\n", &angka);
            root=insert(root, angka);
        }else if(strcmp("print",str1) == 0){
            // jumlah(root, 0);
            // for (i = 0; i < MAX_HD; i++) {
            //     if(sums[i]==0){
            //         printf("");
            //     }else{
            //         printf("%d ", sums[i]);
            //     }
            // }
            jumlahCoba(root);
            printf("\n");
        }
    } 
} 