#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<int> pq;
    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            cnt++;
            sum += a[i];
        } else {
            if (sum + a[i] >= 0) {
                cnt++;
                sum += a[i];
                pq.push(-a[i]);
            } else if (!pq.empty() && -pq.top() < a[i]) {
                sum += pq.top();
                pq.pop();
                sum += a[i];
                pq.push(-a[i]);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
