#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(void){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int>> queries(m, vector<int>(3));
    for(int i = 0; i < m; i++){
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    
    vector<int> op(m + 1, 0);
    for(int i = 0; i < k; i++){
        int l, r;
        cin >> l >> r;
        op[l - 1]++;
        op[r]--;
    }
    
    for(int i = 1; i < m; i++){
        op[i] += op[i - 1];
    }
    
    vector<int> diff(n + 1, 0);
    for(int i = 0; i < m; i++){
        int l = queries[i][0] - 1;
        int r = queries[i][1];
        int val = queries[i][2] * op[i];
        diff[l] += val;
        diff[r] -= val;
    }
    
    for(int i = 1; i < n; i++){
        diff[i] += diff[i - 1];
    }
    
    for(int i = 0; i < n; i++){
        a[i] += diff[i];
    }
    
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}