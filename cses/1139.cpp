#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
 
const int inf = 2e9+1;
const int mod = 1e9+7;
const int maxn = 3e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
int n, color[maxn], resp[maxn];
vector<int>g[maxn];
set<int>s[maxn];
 
void dfs(int u,int p){
    int idx, big = -1;
    for(auto v:g[u]){
        if(v==p)continue;
        dfs(v,u);
        if(ckmax(big,resp[v]))idx = v;
    }
    if(big!=-1)swap(s[u],s[idx]);
    for(auto v:g[u]){
        if(v==idx||v==p)continue;
        for(auto x:s[v])s[u].insert(x);
    }
    s[u].insert(color[u]);
    resp[u] = sz(s[u]);
}
 
int main(){_
    int n;cin>>n;
    for(int i=1;i<=n;++i)cin>>color[i];
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1,1);
    for(int i=1;i<=n;++i)cout<<resp[i]<<" \n"[i==n];
}
