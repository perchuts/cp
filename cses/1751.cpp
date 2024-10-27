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
 
int f[maxn], par[maxn], lvl[maxn], vis[maxn], tam[maxn], dp[maxn];
 
int findp(int u){return par[u] = (u==par[u]?u:findp(par[u]));}
 
void merge(int u,int v){
    u = findp(u), v = findp(v);
    if(u==v)return;
    if(lvl[u]<lvl[v])swap(u,v);
    par[v] = u;
    if(lvl[u]==lvl[v])++lvl[u];
    ckmax(tam[u],tam[v]);
}
 
int compute(int i){
    if(vis[i])return vis[i]==2?0:dp[i];
    vis[i] = 1;
    return dp[i] = compute(f[i])+1;
}
 
int main(){_
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        par[i] = i;
        cin>>f[i];
    }
    set<int>s;
    for(int i=1;i<=n;++i){//find components
        if(vis[i])continue;
        s.clear();
        int cur = i;
        while(vis[cur]==0){
            s.insert(cur);
            merge(cur,f[cur]);
            vis[cur] = 1, cur = f[cur];
        }
        int cyclesize = 0;
        if(!s.count(cur))continue;
        while(vis[cur]==1){
            vis[cur] = 2, cyclesize++, cur = f[cur];
        }
        tam[findp(i)] = cyclesize;
    }
    
    for(int i=1;i<=n;++i)if(vis[i]==1)vis[i]=0;
    for(int i=1;i<=n;++i){
        if(!vis[i])compute(i);
        if(vis[i]==2)cout<<tam[findp(i)]<<" ";
        else cout<<dp[i]+tam[findp(i)]<<" ";
    }
}
