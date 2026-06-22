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
            int n,k;
            string s;
            cin >> n >> k >> s;
            bool possible = true;
            for(int i=0;i<k;i++){
                int cnt = 0;
                for(int j=i;j<n;j+=k){
                    cnt += (s[j]=='1');
                }

                if(cnt&1){
                    cout<<"NO\n";
                    possible = false;
                    break;
                }
            }
            if(possible)
                cout<<"YES\n";
        }
    }
