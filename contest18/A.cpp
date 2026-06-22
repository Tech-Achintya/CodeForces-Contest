#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<ll> prefixMin(n);
        prefixMin[0] = arr[0];
        for(int i=1;i<n;i++){
            prefixMin[i] = min(prefixMin[i-1],arr[i]);
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ans+=prefixMin[i];
        }
        cout<<ans<<"\n";
    }
}