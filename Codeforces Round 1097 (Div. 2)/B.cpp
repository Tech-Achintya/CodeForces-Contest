#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        unordered_map<int,int> mp;
        int maxi = -1e9;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            mp[arr[i]]++;
            maxi = max(maxi,arr[i]);
        }
        vector<int> result;
        result.push_back(maxi);
        mp[maxi]--;
        int mex = 0 ;
        while(mp[mex]>0){
            result.push_back(mex);
            mp[mex]--;
            mex++;
        }
        for(auto& it:mp){
            int val = it.first;
            int cnt = it.second;
            while(cnt>0){
                result.push_back(val);
                cnt--;
            }
        }
        int tempMexi = 0;
        long long ans = 0;
        unordered_map<int,int> calcMex;
        for(int x : result){
            calcMex[x]++;
            while(calcMex[tempMexi]>0){
                tempMexi++;
            }
            ans += (tempMexi + maxi);
        }
        cout<<ans<<"\n";
    }
}