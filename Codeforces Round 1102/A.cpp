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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool ok = true;
        sort(arr.begin(), arr.end(),greater<int>());
        for(int i=0;i<n-2;i++){
            if(arr[i+2]!=arr[i]%arr[i+1]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout<<arr[0] <<" "<<arr[1]<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}