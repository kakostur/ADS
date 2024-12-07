#include <bits/stdc++.h>

using namespace std;

vector<size_t> f(string str){
    size_t n = str.size();
    vector<size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i < n; i++) {
        size_t j = v[i - 1];
        while(j > 0 && str[j] != str[i]) {
            j = v[j - 1];
        }
        if(str[j] == str[i]) {
            v[i] = j + 1;
        }
    }
    return v;
}

int main() {
    string s; cin >> s;
    int cnt = 0;
    string ans = "";
    vector<size_t> v = f(s);
    cout << s.size() - v[s.size() - 1];
}

