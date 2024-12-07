#include <bits/stdc++.h>

using namespace std;

struct Sum{
    long long sum;
    vector<int> v;
};

bool cmp(Sum &a, Sum &b) {
    if(a.sum == b.sum) {
        for(int i = 0; i < a.v.size(); i++) {
            if(a.v[i] > b.v[i]) 
                return false;
            else if (a.v[i] < b.v[i])
                return true;
        }
    }
    return a.sum > b.sum;
}

// void merge(string * a, int l, int m, int r){
//     int i1 = m - l + 1;
//     int i2 = r - m;
//     string L[i1], R[i2];

//     for(int k = 0; k < i1; k++) {
//         L[k] = a[l + k];
//     }
//     for(int k = 0; k < i2; k++) {
//         R[k] = a[m + 1 + k];
//     }
//     int j = 0, i = 0, k = l;

//     while(i < i1 && j < i2){
//         if(L[i] <= R[j]) {
//             a[k] = L[i];
//             i++;
//         } else {
//             a[k] = R[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < i1) {
//         a[k] = L[i];
//         i++;
//         k++;
//     }
//     while (j < i2) {
//         a[k] = R[j];
//         j++;
//         k++;
//     }

// }

// void msort(string * a, int l, int r) {
//     if(l < r) {
//         int m = l + (r - l) / 2;
//         msort(a, l, m);
//         msort(a, m + 1, r);
//         merge(a, l, m, r);
//     }
// }

int main() {
    int n,m; cin >> n >> m;

    vector<Sum> res;

    for(int i = 0; i < n; i++) {
        long long sum = 0;
        vector<int> v;
        for(int j = 0; j < m; j++) {
            int x; cin >> x;
            sum += x;
            v.push_back(x);
        }
        res.push_back({sum, v});
    }

    sort(res.begin(), res.end(), cmp);
    
    for(auto i : res) {
        for(auto j : i.v) {
            cout << j << " ";
        }
        cout <<endl;
    }
    
}