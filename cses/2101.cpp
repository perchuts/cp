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
 
vector<ii> pl[maxn];
vector<int>comp[maxn];
int lvl[maxn], par[maxn];
 
int findp(int x){return par[x] = (par[x]==x?x:findp(par[x]));}
 
void merge(int x,int y,int t){
    x = findp(x), y = findp(y);
    if(x==y)return;
    if(lvl[x]<lvl[y])swap(x,y);
    par[y] = x;
    if(lvl[x]==lvl[y])++lvl[x];
    for(auto z:comp[y]){
        pl[z].pb({t,x});
        comp[x].pb(z);
    }
}
 
int main(){_
    int n,m,q;cin>>n>>m>>q;
    for(int i=1;i<=n;++i){
        par[i] = i;
        comp[i].pb(i), pl[i].pb({0,i});
    }
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        merge(u,v,i);       
    }    
    for(int i=1;i<=n;++i){
        reverse(all(pl[i]));
    }
    while(q--){
        int u,v;cin>>u>>v;
        if(findp(u)!=findp(v))cout<<-1<<endl;
        else{
            bool ok = 0;
            for(int i=0;i<min(sz(pl[u]),sz(pl[v]));++i){
                if(pl[u][i]!=pl[v][i]){
                    cout<<max(pl[u][i].first,pl[v][i].first)<<endl;
                    ok = 1;
                    break;
                }
            }
            if(!ok)cout<<0<<endl;
        }
    }
}
