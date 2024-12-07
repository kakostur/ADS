#include <bits/stdc++.h>

using namespace std;


void merge(int * a, int l, int m, int r){
    int i1 = m - l + 1;
    int i2 = r - m;
    int L[i1], R[i2];

    for(int k = 0; k < i1; k++) {
        L[k] = a[l + k];
    }
    for(int k = 0; k < i2; k++) {
        R[k] = a[m + 1 + k];
    }
    int j = 0, i = 0, k = l;

    while(i < i1 && j < i2){
        if(L[i] <= R[j]) {
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

void msort(int * a, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n,m; cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    msort(b, 0, m - 1);
    msort(a, 0 , n - 1);

    int i = 0, j = 0;

    while(i < n && j < m) {
        if(a[i] == b[j]) {
            cout << a[i] << " ";
            i++; j++;
        } else if(a[i] > b[j]) {
            j++;
        } else i++;
    }
}