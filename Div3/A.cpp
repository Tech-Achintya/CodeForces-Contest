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
        int mini = 1e9;
        int maxi = -1e9;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mini = min(mini, x);
            maxi = max(maxi, x);
        }
        cout<<(maxi+1)-mini<<"\n";
        
    }
}