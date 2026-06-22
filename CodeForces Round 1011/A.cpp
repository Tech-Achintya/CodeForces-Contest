#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, x, s;
        cin >> n >> x >> s;

        string str;
        cin >> str;

        vector<int> tables(x, 0);

        int ptrE = -1;
        int ptrI = 0;
        int ptrA = 0;

        int kick = 0;

        for(int i = 0; i < n; i++) {
            char curr = str[i];

            if(curr == 'E') {

                while(ptrE < x &&
                      (ptrE == -1 || tables[ptrE] == 0 || tables[ptrE] == s))
                    ptrE++;

                if(ptrE >= x) {
                    kick++;
                }
                else {
                    tables[ptrE]++;

                    while(ptrE < x &&
                          (tables[ptrE] == 0 || tables[ptrE] == s))
                        ptrE++;

                    while(ptrA < x && tables[ptrA] == s)
                        ptrA++;
                }
            }

            else if(curr == 'A') {

                while(ptrA < x && tables[ptrA] == s)
                    ptrA++;

                if(ptrA >= x) {
                    kick++;
                }
                else {
                    tables[ptrA]++;

                    if(ptrE == -1)
                        ptrE = ptrA;

                    while(ptrE < x &&
                          (ptrE == -1 || tables[ptrE] == 0 || tables[ptrE] == s))
                        ptrE++;

                    while(ptrA < x && tables[ptrA] == s)
                        ptrA++;
                }
            }

            else { // I

                int temp = ptrI;

                while(temp < x && tables[temp] != 0)
                    temp++;

                if(temp == x) {
                    kick++;
                }
                else {
                    tables[temp] = 1;

                    ptrI = temp + 1;

                    if(ptrE == -1)
                        ptrE = temp;
                }

                while(ptrE < x &&
                      (ptrE == -1 || tables[ptrE] == 0 || tables[ptrE] == s))
                    ptrE++;

                while(ptrA < x && tables[ptrA] == s)
                    ptrA++;
            }
        }

        cout << n - kick << "\n";
    }

    return 0;
}