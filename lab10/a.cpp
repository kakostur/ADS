#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool check_border(int i, int j, int n, int m) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}

int main(){
    int n,m; cin >> n >> m;
    int mario[n][m];
    int a[n][m];
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            mario[i][j] = 100000;
            if(a[i][j] == 2){
                q.push(make_pair(i,j));
                mario[i][j] = 0;
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(check_border(xx, yy, n, m) && a[xx][yy] == 1) {
                mario[xx][yy] = mario[x][y] + 1;
                a[xx][yy] = 2;
                q.push(make_pair(xx,yy));
            }
        }
    }

    int res = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 1) {
                cout << -1;
                return 0;
            } else if(a[i][j] == 0)
                continue;
            res = max(res, mario[i][j]);
        }
    }
    cout << res;

}