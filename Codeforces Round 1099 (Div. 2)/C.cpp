// C. Chipmunk Theo and Equality
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            int curr = arr[i];
            int oper = 0;
            mp[curr].first += oper;
            mp[curr].second++;
            if(curr==1){
                int temp = curr+1;
                mp[temp].first += 1;
                mp[temp].second++;
            }
            while(curr>1){
                if((curr % 2) == 0){
                    curr /= 2;
                } else {
                    curr += 1;
                }
                oper++;
                mp[curr].first += oper;
                mp[curr].second++;
            }
        }
        int ans = INT_MAX;
        for(auto &it : mp){
            if(it.second.second == n){
                ans = min(ans, it.second.first);
            }
        }
        cout<<ans<<"\n";
    }
    
}