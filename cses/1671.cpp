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
const int maxn = 1e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
vector<pair<ll,int>> g[maxn];
ll dist[maxn];
int main(){_
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v,c;cin>>u>>v>>c;
        g[u].pb({c,v});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    for(int i=2;i<=n;++i)dist[i] = 1e18;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,u] = pq.top();pq.pop();
        if(d!=dist[u])continue;
        for(auto [d2,v]:g[u]){
            if(ckmin(dist[v],d+d2))pq.push({dist[v],v});    
        }
    }
    for(int i=1;i<=n;++i)cout<<dist[i]<<" \n"[i==n];
}
