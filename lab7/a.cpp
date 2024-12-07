#include <bits/stdc++.h>

using namespace std;

// struct Words{
//     string word;
//     int size;
// };

bool cmp(string a, string b) {
    if(a.size() == b.size()) return true;
    return a.size() < b.size();
}


void merge(vector<string> &a, int l, int m, int r){
    int i1 = m - l + 1;
    int i2 = r - m;
    vector<string> L(i1);
    vector<string> R(i2);

    for(int k = 0; k < i1; k++) {
        L[k] = a[l + k];
    }
    for(int k = 0; k < i2; k++) {
        R[k] = a[m + 1 + k];
    }
    int j = 0, i = 0, k = l;

    while(i < i1 && j < i2){
        if(cmp(L[i], R[j])) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < i1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < i2) {
        a[k] = R[j];
        j++;
        k++;
    }

}

void msort(vector<string> &a, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n; cin >> n;
    string h; getline(cin,h);
    while(n--) {
        string s; 
        getline(cin, s);
        vector<string> v;
        int k = 0;
        string word = "";
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == ' ') {
                v.push_back(word);
                word = "";
            } else {
                word += s[j];
            }
        }
        v.push_back(word);

        msort(v, 0, v.size() - 1);

        for(auto j : v)
            cout << j <<" ";

        cout <<endl;
    }
    
    
}