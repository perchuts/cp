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
 
vector<pair<ll,int>>g[maxn];
vector<pair<ll,int>>gr[maxn];
pair<ll,ll> dist[maxn][2];
 
int n,m;
 
void dijkstra(int source){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    for(int i=1;i<=n;++i)dist[i][source==n] = {1e18,1e18};
    dist[source][source==n] = {0,0};
    pq.push({0,source});
    while(!pq.empty()){
        auto [d,u] = pq.top();pq.pop();
        if(dist[u][source==n].first!=d)continue;
        if(source!=n){
            for(auto [w2,v]:g[u]){
                if(ckmin(dist[v][source==n].first,d+w2)){
                    pq.push({dist[v][source==n].first,v});
                    dist[v][source==n].second = max(dist[u][source==n].second,w2);
                }            
            }
        }else{
            for(auto [w2,v]:gr[u]){
                if(ckmin(dist[v][source==n].first,d+w2)){
                    pq.push({dist[v][source==n].first,v});
                    dist[v][source==n].second = max(dist[u][source==n].second,w2);
                }            
            }
        }
    }
}
 
pair<ll,ii> edges[2*maxn];
 
int main(){_
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        ll c;
        int u,v;cin>>u>>v>>c;
        g[u].pb({c,v});
        gr[v].pb({c,u});
        edges[i] = {c,{u,v}};
    }    
    dijkstra(1), dijkstra(n);
    ll resp = 1e18;
    for(int i=1;i<=m;++i){
        auto [c,p] = edges[i];
        auto [u,v] = p;
        ll cost = dist[u][0].first + dist[v][1].first+max({dist[u][0].second,dist[v][1].second,c})/2;
        ckmin(resp,cost);
    }
    cout<<resp<<endl;
}       
