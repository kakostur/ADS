#include <bits/stdc++.h>

using namespace std;

typedef long long ll; 
int q = 1e9 + 7; 

class HashMap{ 
    vector<bool>  ar; 
    vector<ll> v; 
    ll size; 
public: 
    HashMap(){ 
        size = q/1000; 
        ar.resize(size); 
    } 
    bool find(ll h){ 
        h = h%size; 
        return ar[h]; 
    } 
    void set_false(){ 
        for(ll i : v) ar[i] = false; 
        v.clear(); 
    } 
    void add(ll x, ll h){ 
        h = h%size; 
        v.push_back(h); 
        ar[h] = true; 
    } 
}; 
 
int k; 
string s[11]; 
 
string sub(ll m){ 
    for(int i = 0; i < k; i++) if (m >= s[i].size()) return ""; 
    static HashMap hm[10]; 
    ll D = 27, H = 1; 
    for(int i = 0; i < m-1; i++) H = (H*D)%q; 
    for(int j = 0; j < k-1; j++){ 
        ll t = 0; 
        for(int i = 0; i < m-1; i++) t = (D*t + s[j][i])%q; 
        for(int i = 0; i < s[j].size()-m+1; i++){ 
            t = ((D * (t - (i ? s[j][i-1] : 0)*H) + s[j][i+m-1])%q + q)%q; 
            hm[j].add(i+m, t); 
        } 
    } 
    string ans = ""; 
    ll t = 0; 
    for(int i = 0; i < m-1; i++) t = (D*t + s[k-1][i])%q; 
    for(int i = 0; i < s[k-1].size()-m+1; i++){ 
        bool flag = true; 
        t = ((D * (t - (i ? s[k-1][i-1] : 0)*H) + s[k-1][i+m-1])%q + q)%q;

        for(int j = 0; j < k-1; j++) if (!hm[j].find(t)) flag = false; 
        if (flag) {ans = s[k-1].substr(i, m); break; } 
    } 
    for(int i = 0; i < k; i++) hm[i].set_false(); 
    return ans; 
 
}

string bin(){
    long long l = -1, r = 5001;
    while(l+1 < r){
        long long m = (r+l)/2;
        (sub(m) == "" ? r : l) = m;
    }

    return sub(l);
}

int main(){
    cin >> k;
    
    for(int i = 0; i < k; i++){
        cin >> s[i];
    }

    for(int i = 0; i < k; i++){
        for(int j = 0; j < s[i].size(); j++){
            s[i][j] -= 'a'-1;
        }
    }
    string ans = bin();
    for(int i = 0; i < ans.size(); i++)ans[i] += 'a'-1;
    
    cout << ans;
}