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
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        long long sum = 0;
        long long ans = INT_MAX;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            long long h = sum/(i+1);
            if(h<ans){
                ans = h;
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}