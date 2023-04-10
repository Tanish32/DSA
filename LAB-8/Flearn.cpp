#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, long long> count;
    count[0] = 1;
    int prefix_xor = 0;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        prefix_xor ^= a[i];
        result += count[prefix_xor];
        count[prefix_xor]++;
    }

    cout << result << endl;
    return 0;
}
