#include <bits/stdc++.h>

using namespace std;

vector<int> g[1000000];
vector<bool> used;
vector<int> col, ans;
int n,m;

bool cycle(int x) {
    col[x] = 1;
    for(auto i : g[x]) {
        if(col[i] == 0) {
            if(cycle(i)) {
                return true;
            }
        } else if(col[i] == 1) {
            return true;
        }
    }
    col[x] = 2;
    return false;
}

bool iscycle() {
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            if(cycle(i)){
                return true;
            }
        }
    }
    return false;
}

void dfs(int x) {
    used[x] = true;
    for(auto i : g[x]) {
        if(!used[i]) {
            dfs(i);
        }
    }
    ans.push_back(x + 1);
}

int main() {
    cin >> n >> m;
    used.resize(n, false);
    col.resize(n, 0);
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    if(iscycle()) {
        cout << "Impossible";
    } else {
        for(int i = 0; i < n; i++) {
            if(!used[i]) {
                dfs(i);
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "Possible"<<endl;
        for(auto i : ans) cout << i << " ";
    }

}