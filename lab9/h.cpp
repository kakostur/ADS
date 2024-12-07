#include <bits/stdc++.h>

using namespace std;

vector<size_t> get_prefix(string t) {
    size_t n = t.size();
    vector<size_t> v(n);
    int i = 1, j = 0;
    while(i < n) {
        if(t[i] == t[j]) {
            v[i] = j + 1;
            i++;
            j++;
        } else {
            if(j == 0) {
                v[i] = 0;
                i++;
            } else {
                j = v[j - 1];
            }
        }
    }
    return v;
}

int c(string s) {
    vector<size_t> v = get_prefix(s);
    int cnt = 0;
    for(size_t i = 1; i < s.size(); i++) {
        size_t size = i - v[i-1];
        if(v[i-1] == 0) 
            continue;
        if((i / size) % 2 == 0 && i % size == 0) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    string s; cin >> s;
    cout << c(s);

}