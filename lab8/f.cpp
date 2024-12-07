#include <bits/stdc++.h>

using namespace std;

int f(string s) {
    size_t n = s.size();

    long long h[n];
    long long p[n];
    long long q = LONG_LONG_MAX;

    p[0] = 1;

    for(size_t i = 1; i < n; i++) {
        p[i] = (p[i-1] * 31) % q;
    }

    for(size_t i = 0; i < n; i++) {
        h[i] = ((s[i] - int('a') + 1) * p[i]) % q;
        if(i > 0) {
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }
    
    long long cnt = 0;
    for(int i = 1; i <= n; i++) {
        set<long long> h_s;
        for(size_t j = 0; j + i - 1 < n; j++) {
            long long d = h[j + i - 1];
            if(j > 0) {
                d -= h[j - 1];
            }
            d *= p[n - j - 1];
            h_s.insert(d);
        }
        cnt += h_s.size();
    }
    return cnt;
}

int main() {
    string s; cin >> s;
    cout << f(s);
}