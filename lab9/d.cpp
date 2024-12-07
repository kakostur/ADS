#include <bits/stdc++.h>

using namespace std;

struct city {
   string s;
   size_t num;
   city(string s, size_t num) {
    this->num = num;
    this->s = s;
   }
};


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
    string word; cin >> word;
    int n; cin >> n;
    size_t ans = 0;
    string s2 = "";
    vector<city> cities;
    for(int j = 0; j < word.size(); j++) s2 += tolower(word[j]);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        string s1 = "";
        for(int j = 0; j < s.size(); j++) s1 += tolower(s[j]);
        string str = s1 + '#' + s2;
        vector<size_t> v = f(str);
        for(auto i : v) cout << i <<" ";
        cout <<endl;
        if(v[str.size() - 1] >= ans && v[str.size() - 1] != 0) {
            ans = v[str.size() - 1];
            cities.push_back({s, v[str.size() - 1]});
        }
    }
    vector<string> v;
    for(auto i : cities) {
        if(i.num == ans) {
            v.push_back(i.s);
        } 
    }
    cout << v.size()<<endl;
    for(auto i : v) cout << i <<endl;
}