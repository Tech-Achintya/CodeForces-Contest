//  Another Sorting Problem
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
        int maxDiff = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i!=0){
                if(arr[i-1]>arr[i]){
                    maxDiff = max(maxDiff,arr[i-1]-arr[i]);
                }
            }
        }
        if(maxDiff==0){
            cout<<"YES";
        }
        else{
            for(int i=1;i<n;i++){
                if(arr[i-1]>arr[i]){
                    arr[i]+= maxDiff;
                }
            }
            bool flag = true;
            for(int i=1;i<n;i++){
                if(arr[i-1]>arr[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<"YES";
            }else{
                cout<<"NO";
            }
        }
        cout<<"\n";
    }    
}