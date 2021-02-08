#include<bits/stdc++.h>

using namespace std;

void solve(int n) {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    else {
        if (n % 2 == 0) {
            int i = 0;
            int even = n / 2, odd = n;
            while (i != n) {
                int toPrint;
                if (i % 2 == 0) {
                    toPrint = even;
                    even--;
                }
                else {
                    toPrint = odd;
                    odd --;
                }
                cout << toPrint << " ";
                i++;
            }

        } else {
            int i = 0;
            int even = n / 2 + 1, odd = n;
            while (i != n) {
                int toPrint;
                if (i % 2 == 0) {
                    toPrint = even;
                    even--;
                }
                else {
                    toPrint = odd;
                    odd --;
                }
                cout << toPrint << " ";
                i++;
            }
        }
    }
    return;

}


int main() {
    int n;
    cin >> n;
    solve(n);

}