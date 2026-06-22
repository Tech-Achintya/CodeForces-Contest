#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;

        vector<int> arrA(size), arrB(size);
        for (int i = 0; i < size; i++) cin >> arrA[i];
        for (int i = 0; i < size; i++) cin >> arrB[i];
        vector<int> posList(size);
        bool possible = true;
        for (int i = 0; i < size; i++) {
            int pos = lower_bound(arrB.begin(), arrB.end(), arrA[i]) - arrB.begin();

            if (pos == size) {
                possible = false;
                break;
            }

            posList[i] = pos;
        }
        if (!possible) {
            cout << -1 << '\n';
            continue;
        }
        vector<pair<int,int>> pairsList;
        for (int i = 0; i < size; i++) {
            pairsList.push_back({posList[i], i});
        }

        sort(pairsList.begin(), pairsList.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        vector<int> order;
        int pointer = 0;
        for (int pos = 0; pos < size; pos++) {
            while (pointer < size && pairsList[pointer].first <= pos) {
                minHeap.push(pairsList[pointer].second);
                pointer++;
            }
            if (minHeap.empty()) {
                possible = false;
                break;
            }
            order.push_back(minHeap.top());
            minHeap.pop();
        }
        if (!possible) {
            cout << -1 << '\n';
            continue;
        }
        ll inversions = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (order[i] > order[j]) inversions++;
            }
        }
        cout << inversions << '\n';
    }

    return 0;
}
