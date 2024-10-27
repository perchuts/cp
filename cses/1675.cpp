#include <bits/stdc++.h>
#define maxn (int)(1e5+51)
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define ll long long
#define pb push_back
#define ull unsigned long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define inf 2000000001
#define mod 1000000007 //998244353
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
vector<pair<int,ll>>g[maxn];
int n,m;
 
ll prim(){
    vector<bool>visited(n+1,0);
    vector<int>mn(n+1,1LL*inf);
    set<pair<ll,int>>q;
    mn[1]=0;
    ll ans=0;
    q.insert({0,1});
    for(int it=1;it<=n;it++){
        if(q.empty())return -1;
        auto [w,v] = *begin(q);
        visited[v]=1;
        q.erase(begin(q));
        ans+=w;
        for(auto [u,weight] : g[v]){
            if(!visited[u]&&mn[u]>weight){
                q.erase({mn[u],u});
                mn[u] = weight;
                q.insert({weight,u});
            }
        }
    }
    return ans;
 
}
 
 
int main(){_
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }    
    ll ans = prim();
    if(ans==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<ans<<endl;
    }
 
}
