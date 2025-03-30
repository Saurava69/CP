#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, h;
        cin >> n >> h;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int l=0,r=h,ans = 0;
        auto check = [&](vector<int> a,int x){
            int cS=0;
            for(int i=0;i<n-1;i++){
                cS+=min(x,abs(a[i+1]-a[i]));
            }
            cS+=x;
            return cS>=h;
        };
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(check(a,mid)){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}