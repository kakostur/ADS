#include <bits/stdc++.h>

using namespace std;

int n,m;

bool bfs(vector<int> v[], int a, int b) {
    bool visit[n + 1] = {false};
    queue<int> q;
    q.push(a);
    visit[a] = true;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(int i = 0; i < v[t].size(); i++) {
            if(!visit[v[t][i]]) {
                visit[v[t][i]] = true;
                q.push(v[t][i]);
                if(v[t][i] == b) 
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    vector<int> v[n + 1];
    for(int i = 0; i < m; i++) {
        int x,y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int a,b; cin >> a >> b;
    if(bfs(v,a,b)) 
        cout << "YES";
    else cout << "NO";
}