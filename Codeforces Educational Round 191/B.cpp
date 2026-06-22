#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void evenFunct(vector<int>& arr,int a,int b,int ptr){
    arr[ptr] = b;
    arr[ptr+1] = a;
    arr[ptr+2] = a;
    arr[ptr+3] = b;
    arr[ptr+4] = a;
    arr[ptr+5] = b;
    arr[ptr+6] = b;
    arr[ptr+7] = a;
}
void oddOneTwoThree(vector<int>& arr){
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 3;
    arr[6] = 1;
    arr[7] = 3;
    arr[8] = 2;
    arr[9] = 2;
    arr[10] = 3;
    arr[11] = 3;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if(n%2==0){
            vector<int> arr(4*n);
            int ptr = 0;
            int a = 1;
            int b = 2;
            int temp = n/2;
            while(temp--){
                evenFunct(arr,a,b,ptr);
                ptr+=8;
                a = b+1;
                b = b+2;
            }
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }
        }else{
            vector<int> arr(4*n);
            oddOneTwoThree(arr);
            if(n!=3){
                int a = 4;
                int b = 5;
                int ptr = 12;
                int temp = (n-3)/2;
                while(temp--){
                    evenFunct(arr,a,b,ptr);
                    ptr+=8;
                    a = b+1;
                    b = b+2;
                }
            }
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }
        }
        cout<<"\n";
    }
}