#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(void) {
    string s;
    cin >> s;
    vector<int> a(3), b(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    int x;
    cin >> x;
    map<char, int> mp;
    mp['B'] = 0;
    mp['S'] = 0;
    mp['C'] = 0;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }

    auto can_make = [&](int k) {
        int cost = 0;
        cost += max(0LL, k * mp['B'] - a[0]) * b[0];
        cost += max(0LL, k * mp['S'] - a[1]) * b[1];
        cost += max(0LL, k * mp['C'] - a[2]) * b[2];
        return cost <= x;
    };

    int low = 0, high = 1e12, ans = 0; // Adjusted high value to 1e12
    while (low <= high) {
        int mid = (low + high) / 2;
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