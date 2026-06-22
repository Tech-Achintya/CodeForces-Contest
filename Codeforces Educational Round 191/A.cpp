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
        int n,x,y,z;
        cin >> n >> x >> y >> z;
        int optOne = (n + (x + y) - 1) / (x + y);
        int optTwo;
        if (x * z >= n) {
            optTwo = (n + x - 1) / x;
        } else {
            int rem = n - x * z;
            int speed = x + 10 * y;
            optTwo = z + (rem + speed - 1) / speed;
        }
        cout<<min(optOne,optTwo)<<"\n";
    }
}
    