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
    vector<long long> preCompute = {
        0, 1, 2, 3, 4, 5,
        6, 7, 8, 9, 22, 11
    };
    while (t--) {
        long long n;
        cin >> n;

        long long a = preCompute[n % 12];

        if (a > n) {
            cout << -1 << '\n';
        } else {
            cout << a << ' ' << (n - a) << '\n';
        }
    }
}