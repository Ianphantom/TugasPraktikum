#include <stdio.h> 
#include <stdlib.h> 
  
struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
struct Node* newNode(int item) 
{ 
    struct Node* temp 
        = (struct Node*)malloc( 
            sizeof(struct Node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
void modifikasi( struct Node* root, int* jumlah) 
{ 
    if (root == NULL) 
        return; 
    modifikasi(root->right, jumlah); 
    *jumlah = *jumlah + root->data; 
    root->data = *jumlah; 
    modifikasi(root->left, jumlah); 
} 
  
void ubah(struct Node* root) 
{ 
    int jumlah = 0; 
    modifikasi(root, &jumlah); 
} 
void inorder(struct Node* root) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 

struct Node* insert( struct Node* root, int data ) {
        
    if(root == NULL) {
        struct Node* node = (struct node*)malloc(sizeof(struct Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    } else {
        struct node* cur;
        if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
        return root;
    }
}
int main() 
{ 
    struct Node* root = NULL;
    int data;
    while(scanf("%d", &data) != EOF) {
        root = insert(root, data);
    } 
    ubah(root); 
    inorder(root); 
  
    return 0; 
} 