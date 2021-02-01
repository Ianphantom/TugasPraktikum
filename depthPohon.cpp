#include <bits/stdc++.h>
using namespace std;
priority_queue<long long> level;
int leaves;
class Node {
    public:
        long long data;
        Node *left;
        Node *right;
        Node(long long d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        Node* insert(Node* root, long long data) {
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
        long long findLevelUtil(Node *node,  long long data, long long depth){ 
            if (node == NULL) 
                return 0; 
          
            if (node -> data == data) 
                return depth; 
          
            long long downdepth = findLevelUtil(node -> left, data, depth + 1); 
            if (downdepth != 0) 
                return downdepth; 
          
            downdepth = findLevelUtil(node->right, data, depth + 1); 
            return downdepth; 
        }
        
        void showpq(long long leaves)
        {
            long long jumlah = 0;
            long long i=0;
            if(leaves >= 2){
                while (i<2) {
                    i++;
                    if(!level.empty()){
                        jumlah = jumlah + level.top();
                        level.pop();
                    }
                }    
            }else{
                jumlah = jumlah + level.top();
            }
            if(!level.empty()){
                level.pop();
            }
            cout << jumlah;
        } 
        
        long long findLevel(Node *node, long long data){ 
            return findLevelUtil(node, data, 1); 
        } 
        
        bool isLeaf(Node *root) {
            return (root->left == NULL) && (root->right == NULL);
        }

        void printLeaves(Node *root,Node *node) {
            if (root) {
                printLeaves(root->left,node);
                if (isLeaf(root)) {
                    leaves++;
                    level.push(findLevel(node, root->data)-1);
//                    cout <<"Level "<<root->data<<"= "<< findLevel(node, root->data)-1;
                }
                printLeaves(root->right,node);
            }
        }
        
};

int main(){
    Solution myTree;
    Node* root = NULL;
    long long t;
    long long data;
    long long angka;
    std::cin >> t;

    for(long long i=0;i<t;i++){
        leaves = 0;
        cin >> angka;
        root = myTree.insert(root, angka);
        myTree.printLeaves(root,root);
        myTree.showpq(leaves);
        cout << endl;
    }
    return 0;
}