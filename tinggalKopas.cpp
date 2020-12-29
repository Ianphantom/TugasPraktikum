#include <bits/stdc++.h>

using namespace std;
int i=0;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
          Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
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

    void inOrder(Node *root, int val) {
        if(root){
            inOrder(root->left,val);
            i++;
            if(val==i){
                cout<<root->data<<endl;    
            }
//            cout<<root->data<<endl;
            inOrder(root->right,val);
        }
    }
    
    void postOrder(Node *root, int val) {
        if(root){
            postOrder(root->left,val);
            postOrder(root->right,val);
//            cout<<root->data<<endl;
            i++;
            if(val==i){
                cout<<root->data<<endl;    
            }
        }
    }

    void preOrder(Node *root,int val) {
         if(root){
             i++;
//            cout<<root->data<<endl;
            if(val==i){
                cout<<root->data<<endl;    
            }
            preOrder(root->left,val);
            preOrder(root->right,val);
        }
    }

};


int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;
    int angka;
    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        if(data==1){
            cin >> angka;
            root = myTree.insert(root, angka);    
        }else if(data==2){
            string s;
            int angka2;
            cin >> s >> angka2;
            if(s=="inorder"){
                myTree.inOrder(root,angka2);
                i=0;
            }else if(s=="preorder"){
                myTree.preOrder(root,angka2);
                i=0;
            }else if(s=="postorder"){
                myTree.postOrder(root,angka2);
                i=0;
            }
        }
    }
    return 0;
}