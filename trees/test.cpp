#include <bits/stdc++.h>
using namespace std;

int query(int i, int j, int k) {
    cout << "? " << i << " " << j << " " << k << endl;
    cout.flush();
    int res;
    cin >> res;
    if (res == -1) exit(0); 
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> points(n);
    iota(points.begin(), points.end(), 1);
    
    int a = 1, b = 2, c = 3;
    while (true) {
        int p = query(a, b, c);
        if (p == 0) {
            cout << "! " << a << " " << b << " " << c << endl;
            return;
        }
        
        vector<tuple<int, int, int>> candidates = {{a, b, p}, {a, p, c}, {p, b, c}};
        for (auto [x, y, z] : candidates) {
            if (query(x, y, z) == 0) {
                a = x, b = y, c = z;
                break;
            }
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
