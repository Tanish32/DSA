#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void kthLargestUtil(Node* root, int k, int& c){
    if (root == NULL || c >= k) return;
    kthLargestUtil(root->right, k, c);
    c++;
    if (c == k) {
        cout << "K'th largest element is " << root->data << endl;
        return;
    }
    kthLargestUtil(root->left, k, c);
}
void kthLargest(Node* root, int k){
    int c = 0;
    kthLargestUtil(root, k, c);
}
int main(){
    Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);
 
    int k = 3;
    kthLargest(root, k);
 
    return 0;
}
