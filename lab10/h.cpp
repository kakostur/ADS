#include <bits/stdc++.h>

using namespace std;

char a[1000][1000];

void dfs(int i, int j, int n, int m) {
    if(i >= n || j >= m || i < 0 || j < 0)
        return;
    if(a[i][j] == '2' || a[i][j] == '0')
        return;
    a[i][j] = '2';

    dfs(i+1,j,n,m);
    dfs(i-1,j,n,m);
    dfs(i,j+1,n,m);
    dfs(i,j-1,n,m);
}

int main() {

    int n,m; cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '1') {
                dfs(i,j,n,m);
                cnt++;
            }
        }
    }
    cout << cnt;
}