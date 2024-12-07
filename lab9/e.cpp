#include <bits/stdc++.h>

using namespace std;

vector<size_t> f(string str) {
    size_t n = str.size();
    vector<size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i < n; i++) {
        size_t j = v[i - 1];
        while(j > 0 && str[j] != str[i]) {
            j = v[j - 1];
        }
        if(str[i] == str[j]) {
            v[i] = j + 1;
        }
    }
    return v;
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        int k;
        cin >> s >> k;
        vector<size_t> v = f(s);
        for(auto i : v) cout << i <<" ";
        cout <<endl;
        size_t last = v[s.size() - 1];
        if(k == 1) {
            cout << s.size()<<endl;
            continue;
        }
        cout << (v.size() - last) * k + last<<endl;
    }

}