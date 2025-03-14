#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        bool flag = true;
        for(int i = 0; i < n - 1; i++){
            if(a[i] > a[i + 1]){
                flag = false;
                break;
            }else{
                int temp=min(a[i],a[i+1]);
                a[i]-=temp;
                a[i+1]-=temp;
            }
        }
        if(flag){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}