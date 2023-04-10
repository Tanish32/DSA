#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

pair<ll, ll> get_slope(pair<ll, ll> p1, pair<ll, ll> p2) {
    ll delta_x = p2.first - p1.first;
    ll delta_y = p2.second - p1.second;
    ll gcd_xy = gcd(delta_x, delta_y);
    return {delta_x / gcd_xy, delta_y / gcd_xy};
}

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    ll total_triangles = 0;
    for (int i = 0; i < n; i++) {
        map<pair<ll, ll>, int> slopes_count;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                pair<ll, ll> slope = get_slope(points[i], points[j]);
                slopes_count[slope]++;
            }
        }

        ll triangles = (n - 1) * (n - 2) / 2;
        for (auto it = slopes_count.begin(); it != slopes_count.end(); it++) {
            int count = it->second;
            triangles -= count * (count - 1) / 2;
        }

        total_triangles += triangles;
    }
    cout<<total_triangles/3<<endl;
}
