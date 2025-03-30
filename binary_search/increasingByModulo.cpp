//Incresing by modulo codeforces
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(void) {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=m,ans=0;
    auto check = [&](int x){
        int prev=0;
        for(int i=0;i<n;i++){
            if(a[i]+x>=prev){
                if(a[i]>prev){
                    prev=a[i];
                }else{
                    prev++;
                }
            }else{
                return false;
            }
        }
        return true;
    }; 
    while(l<=r){
        int mid=(l+(r-l)/2);
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}