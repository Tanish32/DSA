#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void insertBST(int val, TreeNode **root)
{
    // cout<<root<<"@ "<<endl;

    if (*root == nullptr)
    {
        TreeNode *temp = new TreeNode(val);
        *root = temp;
        return;
    }
    if (val > (**root).val)
    {
        insertBST(val, &((*root)->right));
    }
    else
    {
        insertBST(val, &((*root)->left));
    }
}
void BSTify(int size, int arr[], TreeNode *root)
{
    // cout<<root<<endl;
    for (int i = 1; i < size; i++)
    {
        insertBST(arr[i], &root); // what is the need to pass this as a reference????
    }
    // cout<<root;
}

int main()
{
    int n, l, r, count = 0;
    cin >> n >> l >> r;
    vector<int> a;
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        if (temp >= l && temp <= r && temp != -1)
        {
            a.push_back(temp);
            count++;
        }
    }
    int arr[count];

    for (int i = 0; i < count; i++)
    {
        arr[i] = a[i];
    }
    TreeNode *rootptr = new TreeNode(arr[0]);
    BSTify(count, arr, rootptr);
    cout << rootptr->right->val;
    return 0;
}
