#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        for (int empty = 0; empty < n; empty++) {

            vector<long long> water(n, (long long)4e18);

            // Clockwise pass
            long long mx = 0;

            for (int dist = 1; dist <= n; dist++) {
                int pipe = (empty + dist - 1) % n;
                int vessel = (empty + dist) % n;

                mx = max(mx, h[pipe]);
                water[vessel] = min(water[vessel], mx);
            }

            // Counter-clockwise pass
            mx = 0;

            for (int dist = 1; dist <= n; dist++) {
                int pipe = (empty - dist + n) % n;
                int vessel = (empty - dist + n) % n;

                mx = max(mx, h[pipe]);
                water[vessel] = min(water[vessel], mx);
            }

            water[empty] = 0;

            long long answer = 0;
            for (int i = 0; i < n; i++) {
                answer += water[i];
            }

            cout << answer;
            if (empty + 1 < n) cout << ' ';
        }

        cout << '\n';
    }

    return 0;
}