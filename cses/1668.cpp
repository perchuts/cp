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
const int maxn = 2e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
vector<int>g[maxn];
 
bool vis[maxn], color[maxn];
 
bool dfs(int u, bool c){
    color[u] = c, vis[u] = 1;
    for(auto v:g[u]){
        if(vis[v]&&color[v]==c)return 0;
        if(!vis[v]&&!dfs(v,c^1))return 0;
    }
    return 1;
}
 
int main(){_
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        g[u].pb(v);g[v].pb(u);
    }    
    bool ok = 1;
    for(int i=1;i<=n;++i){
        if(!vis[i])ok&=dfs(i,1);
    }
    if(!ok)cout<<"IMPOSSIBLE"<<endl;
    else{ 
        for(int i=1;i<=n;++i)cout<<color[i]+1<<" \n"[i==n];
    }
}
