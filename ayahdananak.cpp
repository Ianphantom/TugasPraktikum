#include <bits/stdc++.h>
#include <string.h>

using namespace std;

class Node {
    public:
        int key, size;
        Node *left;
        Node *right;
        Node(int d) {
            key = d;
            size = 1;
            left = NULL;
            right = NULL;
        }
};

class BST {
    public:
        Node *root;
        int size;
        BST() {
            root = NULL;
        }

        int getSize(Node *root) {
            return root ? root->size : 0;
        }

        Node* insert(Node* root, int key) {
            if(root == NULL) {
                return new Node(key);
            } 
            
            if (key < root->key)
                  root->left = insert(root->left, key);
             else if (key > root->key)
                  root->right = insert(root->right, key);
           return root;
        }
        
        void PrintChild(Node *root) {
            if (root==NULL)
                cout << "NULL ";
            else
                printf("%d ", root->key);
        }


        void findPathChild(Node *root, int val) {
            if (root == NULL )
            return;
            if (root->key == val) {
                PrintChild( root->left );
                   PrintChild( root->right );
                   cout <<endl;
            }else if (val < root->key) {
                findPathChild(root->left, val);
            } else if (val > root->key) {
                findPathChild(root->right, val);
            }
        }

        void findParent(Node* node, int val, int parent){
            if (node == NULL)
                return;
            if (node->key == val) {
                cout << parent<<endl;
            }
            else {
                findParent(node->left, val, node->key);
                findParent(node->right, val, node->key);
            }
        }
};

int main() {
    BST myTree;
    int kasus,que,angka1,angka2;
    string s;
    cin >> kasus;
    for(int i=0;i<kasus;i++){
        cin >> que;
        if(que==1){
            cin >> angka2;
            myTree.root = myTree.insert(myTree.root, angka2);
        }else if(que==2){
            cin >> s >> angka2;
            if(s.compare("child")==0){
                myTree.findPathChild(myTree.root,angka2);
            }else if(s.compare("parent")==0){
                myTree.findParent(myTree.root, angka2,-1);
            }
        }
    }    
    return 0;
}