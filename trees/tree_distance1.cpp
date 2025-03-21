#include <bits/stdc++.h>
using namespace std;

int n, x, y;
vector<int>a[200005];
int vis[200005];
int d[200005];
int par[200005];
 
void dfs(int src, int p, int dis){
    vis[src]=1;
    d[src]=dis;
    
    for(auto i:a[src]){
        if(!vis[i] and i!=p){
            par[i] = src;
            dfs(i, src, dis+1);
        }
    }
}
 
 
int main(){

    int t=1;
    while(t--){
        cin>>n;
        for(int i=0;i<n-1;i++){
            int x, y;cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        memset(par, 0, sizeof(par));
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        par[1]=0;
        dfs(1, par[1], 0);
        int node1 = -1 , node2 = -1 , ma = INT_MIN;
        for(int i=2;i<=n;i++){
            if(ma<d[i]){
                node1 = i;
                ma = d[i];
            }
        }
        
        
        ma=INT_MIN;
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        dfs(node1 , 0 , 0);
        
        for(int i=1;i<=n;i++){
            if(ma<d[i] and i!=node1){
                node2 = i;
                ma = d[i];
            }
        }
        
        //node1 and node2 mil gaye...
        //ab unse dfs call kardo 
        
        
        // cout<<node1<<" "<<node2<<endl;
        // for(int i=1;i<=n;i++)cout<<par[i]<<" ";
        
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        dfs(node1, 0 , 0);
        vector<int>d1;d1.push_back(0);
        for(int i=1;i<=n;i++){
            d1.push_back(d[i]);
        }
        
        
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        dfs(node2, 0 , 0);
        
        //cout<<d[node1]<<endl;
        for(int i=1;i<=n;i++){
            cout<<max(d[i], d1[i])<<" ";
        }
        
    }
    return 0;
}