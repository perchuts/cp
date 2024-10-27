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
const int maxn = 2501;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
vector<tuple<int,int,ll>>edges;
vector<int>g[maxn];
ll dist[maxn];
bool vis[maxn];
 
 
void dfs(int x){
    vis[x] = 1;
    for(auto v:g[x])if(!vis[v])dfs(v);
}
 
int main(){_
    int n,m;cin>>n>>m;
    edges.resize(m);
    for(auto& [a,b,c]:edges){
        cin>>a>>b>>c;
        g[b].pb(a);
    }   
    dfs(n);
    for(int i=2;i<=n;++i)dist[i] = 1e18;
    for(int i=2;i<=n;++i){
        for(int j=0;j<m;++j){
            int a,b;ll c;
            tie(a,b,c) = edges[j];
            if(!vis[b])continue;
            if(dist[a]!=1e18)ckmin(dist[b],dist[a]-c);
        }
    }
    ll ans = dist[n];
    for(int j=0;j<m;++j){
        int a,b;ll c;
        tie(a,b,c) = edges[j];
        if(!vis[b])continue;
        if(dist[a]!=1e18&&ckmin(dist[b],dist[a]-c))ans = 1;
    }
    cout<<-ans<<endl;
}
