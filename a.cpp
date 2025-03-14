#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main (void) {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n][2];
        unordered_set<int>xx,yx;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1];
            if(a[i][1] == 1){
                yx.insert(a[i][0]);
            }else{
                xx.insert(a[i][0]);
            }
        }
        
        int count = 0;
        for(int i=0;i<n;i++){
           if(a[i][1] == 1 and xx.find(a[i][0]) != xx.end()){
               count++;
           }
        }
        int ans = 0;
        for(auto x:yx){
            if(xx.find(x-1) != xx.end() and xx.find(x+1) != xx.end()){
                ans++;
            }
        }
        for(auto x:xx){
            if(yx.find(x-1) != yx.end() and yx.find(x+1) != yx.end()){
                ans++;
            }
        }
        ans += (count)*(xx.size()-1);
        ans += count*(yx.size()-1);
        cout<<ans<<endl;
    }
    return 0;
}