#include <bits/stdc++.h>
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
int search(int arr[], int strt, int end, int value){
    for (int i = strt; i <= end; i++)
        if (arr[i] == value)
            return i;
}
Node* buildUtil(int in[], int pre[], int inStrt,
                int inEnd, unordered_map<int, int>& mp){
    static int preIndex = 0;
    if (inStrt > inEnd) return NULL;
    int curr = pre[preIndex++];
    Node* tNode = newNode(curr);
    if (inStrt == inEnd) return tNode;
    int inIndex = mp[curr];
    tNode->left = buildUtil(in, pre, inStrt, inIndex - 1, mp);
    tNode->right = buildUtil(in, pre, inIndex + 1, inEnd, mp);
 
    return tNode;
}
Node* buildTree(int in[], int pre[], int len){
    unordered_map<int, int> mp;
    for (int i = 0; i < len; i++)
        mp[in[i]] = i;
 
    return buildUtil(in, pre, 0, len - 1, mp);
}
void printInorder(Node* node){
    if (node == NULL) return;
 
    printInorder(node->left);
 
    cout << node->data << " ";
 
    printInorder(node->right);
}
int main(){
    int in[] = { 4, 2, 5, 1, 3 };
    int pre[] = { 1, 2, 4, 5, 3 };
    int len = sizeof(in) / sizeof(in[0]);
 
    Node* root = buildTree(in, pre, len);
 
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}
