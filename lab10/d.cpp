#include <bits/stdc++.h>

using namespace std;

bool w[5000];
int n, m, que;

int bfs(vector <int> v[], int x){
    if(w[x]){    
        return 0;
    }
    int d[n + 1] = {-1};
    bool visit[n + 1] = {false};
    queue <int> q;
    q.push(x);
    d[x] = 0;
    visit[x] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = 0; i < v[t].size(); i++){
            if(!visit[v[t][i]]) {
                visit[v[t][i]] = true;
                d[v[t][i]] = d[t] + 1;
                q.push(v[t][i]);
                if(w[v[t][i]]){
                    return d[v[t][i]];
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m >> que;
    vector<int> v[n + 1];
    for(int i = 0; i < m; i++) {
        int x,y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 0; i < que; i++) {
        int x,y; cin >> x >> y;
        if(x == 1) {
            w[y] = true;
        } else {
            cout << bfs(v, y)<<endl;
        }
    }
}