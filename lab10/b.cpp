#include <bits/stdc++.h>

using namespace std;

int a[100][100];
bool used[100] = {false};
int d[100];
queue <int> q;
int n;

int bfs(int v, int tar){
    q.push(v-1);
    used[v-1] = 1;
    d[v-1] = 0;
    while(!q.empty()){
        int x = q.front();
        for(int i=0; i<n; i++){
            int y = a[x][i];
            if(y == 1){
                if(used[i] == false){
                    used[i] = true;
                    q.push(i);
                    d[i] = d[x] + 1;
                    if(i == (tar-1)){
                        return d[i];
                    }
                }
            }
        }
        q.pop();
    }
    
    return -1;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    
    int x, y; cin >> x >> y;
    cout << bfs(x, y);
    return 0;
}