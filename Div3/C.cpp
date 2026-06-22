#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void print(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a,b,x;
        cin>>a>>b>>x;
        if(x>a && x>b && abs(a-b)>=2){
            cout<<2<<"\n";
            continue;
        }
        vector<pair<int,int>> A_nums;
        vector<pair<int,int>> B_nums;
        
        int oper = 0;
        int curr = a;
        while(true){
            A_nums.push_back({curr,oper});
            if(curr==0) break;
            curr = curr/x;
            oper++;
        }
        oper = 0;
        curr = b;   
        while(true){
            B_nums.push_back({curr,oper});
            if(curr==0) break;
            curr = curr/x;
            oper++;
        }
        int ans = 1e9;
        for(auto& [va,operA] : A_nums){
            for(auto& [vb,operB] : B_nums){
                ans = min(ans,operA+operB+ abs(va-vb));
            }
        }
        cout<<ans<<"\n";
    }
}