#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m; cin >> n >> m;
    int a[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        int x,y,z; cin >> x >> y >> z;
        if(a[x-1][y-1] == 0 || a[x-1][z-1] == 0 || a[y-1][z-1] == 0) {
            cout << "NO"<<endl;
        } else cout << "YES"<<endl;
    }
}