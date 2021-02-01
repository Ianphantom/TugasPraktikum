#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long data;
    Node *left, *right;
    long long leftSize;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->leftSize = 0;
    return temp;
}

Node* insert(Node*& root, long long data)
{
    if (!root)
        return newNode(data);
    if (data >= root->data) {
        root->left = insert(root->left, data);
        root->leftSize++;
    }
    else
        root->right = insert(root->right, data);

    return root;
}

int ranking(Node* root, long long x){
    if (root->data == x){
            return root->leftSize+1;
    }
    if (x > root->data) {
        if (!root->left)
            return -1;
        else
            return ranking(root->left, x);
    }
    else {
        if (!root->right)
            return -1;
        else {
            long long rightSize = ranking(root->right, x);
            if(rightSize == -1 ) return -1;
            return root->leftSize + 1 + rightSize;
        }
    }
}

int main()
{
    long long jumlah;
    cin >> jumlah;
    set<int>s;
    Node* root = NULL;
    for (int i = 0; i < jumlah; i++){
        long long angka1;
        cin >> angka1;
        if(s.insert(angka1).second){
            root = insert(root, angka1);
        }
        cout << ranking(root,angka1)<<endl;
    }
    return 0;
}