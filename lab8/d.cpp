#include <bits/stdc++.h>

using namespace std;

int f(string t, string s) {
    int cnt = 0;
    size_t n = t.size();
    size_t m = s.size();

    long long h[n];
    long long p[n];
    long long q = LONG_LONG_MAX;

    p[0] = 1;

    for(size_t i = 1; i < max(n,m); i++) {
        p[i] = (p[i-1] * 31) % q;
    }

    for(size_t i = 0; i < n; i++) {
        h[i] = ((t[i] - int('a') + 1) * p[i]) % q;
        if(i > 0) {
            h[i] = (h[i] + h[i-1]) % q;
        }
    }
    long long h_s = 0;
    for(size_t i = 0; i < m; i++) {
        h_s = (h_s + ((s[i] - int('a') + 1) * p[i]) % q) % q;
    }

    for(size_t i = 0; i + m - 1 < n; i++) {
        long long d = h[i + m - 1];
        if(i > 0) {
            d -= h[i-1];
        }
        if(d == h_s * p[i] && t.substr(i,m) == s) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    while(cin >> n) {
        if(n == 0) {
            return 0;
        }
        string a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string s; cin >> s;
        int maxv = 0;
        for(int i = 0; i < n; i++) {
            if(f(s, a[i]) > maxv) {
                maxv = f(s, a[i]);
            }
        }
        vector<string> v;
        for(int i = 0; i < n; i++) {
            if(f(s,a[i]) == maxv) {
                v.push_back(a[i]);
            }
        }
        cout << maxv<<endl;
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] <<endl;
        }
    }
}