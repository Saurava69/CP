#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    char prev=s[0];
    int ans=1,curr_ans=1;
    for(int i=1;i<s.length();i++){
        if(s[i] == prev){
            curr_ans+=1;
            ans=max(ans,curr_ans);
        }else{
            prev = s[i];
            curr_ans = 1;
        }
    }
    cout<<ans;
}