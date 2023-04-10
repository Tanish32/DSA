#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> bulbs(n);
    for (int i = 0; i < n; i++) {
        cin >> bulbs[i];
    }

    long long count = 0;
    int left = 0;
    int right = 0;
    int lit_count = 0;

    while (right < n) {
        if (bulbs[right] == 1) {
            lit_count++;
        }
        while (lit_count > k) {
            if (bulbs[left] == 1) {
                lit_count--;
            }
            left++;
        }
        count += right - left + 1;
        right++;
    }

    cout << count << endl;
    return 0;
}
