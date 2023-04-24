#include <iostream>
#include <vector>
using namespace std;

string search_matrix(vector<vector<int>> &a, int m, int n, int v) {
    int row = 0;
    int col = n - 1;
    while (row < m && col >= 0) {
        if (a[row][col] == v) {
            return "YES";
        } else if (a[row][col] > v) {
            col--;
        } else {
            row++;
        }
    }
    return "NO";
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int v;
    cin >> v;
    cout << search_matrix(a, m, n, v) << endl;
    return 0;
}
