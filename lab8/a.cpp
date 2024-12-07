#include <bits/stdc++.h>

using namespace std;

long long f(string s) {
    size_t n = s.size();

    long long p[n];
    long long q =  1e9 + 7;

    p[0] = 1;

    for(size_t i = 1; i < n; i++) {
        p[i] = (p[i - 1] * 11) % q;
    }

    long long h_s = 0;
    for(size_t i = 0; i < n; i++) {
        h_s = (h_s + ((s[i] - 47) * p[i]) % q) % q;
    }
    return h_s;
}

int main() {
    int k; cin >> k;
    int n = k * 2;
    string a[n];
    map<string, bool> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = true;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        string s = to_string(f(a[i]));
        if(mp[s]) {
            cout << "Hash of string \"" << a[i] << "\" is " << s<<endl;
            cnt++;
        }
        if(cnt == k) 
            break;
    }
}