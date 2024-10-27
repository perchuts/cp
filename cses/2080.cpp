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
ll ans = 0;
bool vis[maxn];
int subt[maxn];
 
int dfs(int u,int p){
    subt[u] = 1;
    for(auto v:g[u]){
        if(!vis[v]&&v!=p)subt[u] += dfs(v,u);
    }
    return subt[u];
}
 
int find_centroid(int u,int p,int n){
    for(auto v:g[u]){
        if(v==p||vis[v]||subt[v]<=n/2)continue;
        return find_centroid(v,u,n);
    }
    return u;
}
 
ll current[maxn], dist[maxn];
 
int process(int u,int p,int lvl){
    current[lvl]++;
    int depth = lvl;
    for(auto v:g[u]){
        if(vis[v]||v==p)continue;
        ckmax(depth,process(v,u,lvl+1));
    }
    return depth;
}
 
int n,k;
 
void decomposition(int x=1){
    dfs(x,x);
    for(int i=1;i<=subt[x];++i)dist[i] = 0;
    int centroid = find_centroid(x,x,subt[x]);
    vis[centroid] = 1;
    for(auto v:g[centroid]){
        if(vis[v])continue;
        int depth = process(v,v,1);
        for(int i=0;i<=min(depth,k);++i)
            if(k-i<=subt[x])ans += current[i]*dist[k-i];
 
        for(int i=1;i<=depth;++i)dist[i]+=current[i],current[i] = 0;
        
    }
    for(auto v:g[centroid]){
        if(!vis[v])decomposition(v);
    }
}
 
int main(){_
    cin>>n>>k;
    dist[0] = 1ll;
    for(int i=1;i<n;++i){
        int a,b;cin>>a>>b;
        g[a].pb(b);g[b].pb(a);
    }    
    decomposition();
    cout<<ans<<endl;
}
