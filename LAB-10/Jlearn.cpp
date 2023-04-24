#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int val, row, col;
    Node(int v, int r, int c) : val(v), row(r), col(c) {}
};
bool operator<(const Node &a, const Node &b)
{
    if (a.val < b.val)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    priority_queue<Node> pq;
    for (int i = 0; i < n; ++i)
        pq.push(Node(matrix[i][0], i, 0));
    for (int i = 0; i < k - 1; ++i)
    {
        Node node = pq.top();
        pq.pop();
        if (node.col == n - 1)
            continue;
        pq.push(Node(matrix[node.row][node.col + 1], node.row, node.col + 1));
    }
    return pq.top().val;
}

int main()
{
    int n, k;
    cin >> n >> k;
    // matrix ( number of elemts, what is each of those elemts)
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
    cout << kthSmallest(matrix, k);
}
