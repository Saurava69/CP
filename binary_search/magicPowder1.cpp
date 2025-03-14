#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    auto can_make = [&](int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (x > (b[i] + k) / a[i]) return false; // Prevents overflow
            cnt += max(0LL, x * a[i] - b[i]);
            if (cnt > k) return false; // Early exit if cost exceeds k
        }
        return cnt <= k;
    };

    int low = 0, high = *max_element(b.begin(), b.end()) + k, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoids integer overflow
        if (can_make(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}
