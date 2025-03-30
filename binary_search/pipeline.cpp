#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum(int n){
    return n*(n+1)/2;
}
int32_t main(void) {
    int n,k;
    cin>>n>>k;
    int s = sum(k-1);
    n-=1;
    if(s<n){
        cout<<-1<<endl;
    }
    else{
    int l=0,r=k-1;
    while(l<=r){
        int mid=(l+(r-l)/2);
        if(s-sum(mid)>=n){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<k-r-1<<endl;
}
    return 0;
}
