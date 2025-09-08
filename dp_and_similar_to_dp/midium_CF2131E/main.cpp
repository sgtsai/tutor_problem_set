#include <bits/stdc++.h>

using namespace std;
const int MaxN = 2e5 + 5;
int arra[MaxN], arrb[MaxN];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arra[i];
        for(int i = 0; i < n; i++)
            cin >> arrb[i];
        int i = n-1;
        if(arra[i] != arrb[i]) {
            cout << "no\n";
            continue;
        }
        bool OK = true;
        while(i--) {
            //cout << "OK: " << OK << endl;
            if(((arra[i] ^ arra[i+1]) != arrb[i]) && ((arra[i] ^ arrb[i+1]) != arrb[i]) && arra[i] != arrb[i]) {// bug
                //cout << "arra[i]^arra[i+1]: " << arra[i] ^ arra[i+1] << endl;
                OK = false;
                break;
            }
        }
        if(OK) cout << "yes\n";
        else cout << "no\n";
    }
}