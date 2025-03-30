#include<bits/stdc++.h>
using namespace std;

typedef long long L;
const L NINF = -1e18;

int32_t main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<L> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<vector<L>> LDP(n + 1, vector<L>(k + 1, NINF)), RDP(n + 1, vector<L>(k + 1, NINF));
        LDP[0][0] = 0;
        RDP[n][0] = 0;
        
        for (int i = 1; i <= n; i++) {
            LDP[i] = LDP[i - 1];
            for (int j = 1; j <= min(i, k); j++) {
                if (LDP[i - 1][j - 1] != NINF) {
                    LDP[i][j] = max(LDP[i][j], LDP[i - 1][j - 1] + a[i - 1]);
                }
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            RDP[i] = RDP[i + 1];
            for (int j = 1; j <= min(n - i, k); j++) {
                if (RDP[i + 1][j - 1] != NINF) {
                    RDP[i][j] = max(RDP[i][j], RDP[i + 1][j - 1] + a[i]);
                }
            }
        }
        
        L res = 0;
        for (int p = 0; p < n; p++) {
            L cur = NINF;
            if (p == 0) {
                cur = a[0] + RDP[1][k];
            } else if (p == n - 1) {
                cur = a[n - 1] + LDP[n - 1][k];
            } else {
                for (int lc = 1; lc <= min(k - 1, p); lc++) {
                    int rc = k - lc;
                    if (rc < 1 || rc > (n - p - 1)) continue;
                    if (LDP[p][lc] == NINF && RDP[p + 1][rc] == NINF) continue;
                    cur = max(cur, a[p] + LDP[p][lc] + RDP[p + 1][rc]);
                }
            }
            res = max(res, cur);
        }
        cout << res << "\n";
    }
    return 0;
}