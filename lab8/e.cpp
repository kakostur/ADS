#include <bits/stdc++.h>

using namespace std;

string f(int n, long long * a) {
    string word = "";
    long long q = LONG_LONG_MAX;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            word += char(a[i] + 97);
        } 
        if(i > 0) {
            long long d = a[i] % q - a[i - 1] % q;
            d /= pow(2, i);
            word += char(d + 97);
        }
    }
    return word;
}
 
int main() {
    int n; cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << f(n, a);
}