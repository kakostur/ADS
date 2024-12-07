#include <bits/stdc++.h>

using namespace std;

int visit[10000] = {false};
map<int,int> mp;
queue <int> q;
vector<int> res;

void bfs(int a, int b) {
    visit[a] = true;
    mp[a] = -1;
    q.push(a);

    while(!q.empty()) {
        int t = q.front();
        q.pop();
        if(t == b) 
            break;
        if(t * 2 < 10000 && visit[t * 2] == false) {
            mp[t * 2] = t;
            q.push(t * 2);
            visit[t * 2] = true;
        }
        if(visit[t - 1] == false) {
            mp[t - 1] = t;
            q.push(t - 1);
            visit[t - 1] = true;
        }
    }
    res.push_back(b);
    while(mp[res[res.size() - 1]] != a) {
        res.push_back(mp[res[res.size() - 1]]);
    }
}

int main() {
    int a, b; cin >> a >> b;
    if(a == b) {
        cout << 0;
        return 0;
    }
    bfs(a,b);
    cout << res.size()<<endl;
    reverse(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] <<" ";
    }
} 