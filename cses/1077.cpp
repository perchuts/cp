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
 
ll sum[maxn];
vector<pair<ll,int>>cmp;
int pos[maxn];
pair<ll,ll> seg[4*maxn];
ll v[maxn];
 
void update(int i,int l,int r,int x,bool add){
    if(l>x||r<x)return;
    if(l==r){
        if(add)seg[i] = {cmp[l-1].first,1};
        else seg[i] = {0,0};
        return;
    }
    int md = (l+r)/2;
    update(2*i,l,md,x,add), update(2*i+1,md+1,r,x,add);
    seg[i].first = seg[2*i].first + seg[2*i+1].first;
    seg[i].second = seg[2*i].second + seg[2*i+1].second;
}
 
pair<ll,ll> query(int i,int l,int r,int p){
    if(l==r)return {0, cmp[l-1].first};
    int md = (l+r)/2;
    if(seg[2*i].second>=p)return query(2*i,l,md,p);
    pair<ll,ll> ret = query(2*i+1,md+1,r,p-seg[2*i].second);
    return {ret.first+seg[2*i].first,ret.second};
}
 
int32_t main(){_
    ll n,k;cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>v[i], cmp.pb({v[i],i});
    sort(all(cmp));
    for(int i=0;i<n;++i)pos[cmp[i].second] = i+1;
    
    for(int i=1;i<=k;++i)sum[k] += v[i], update(1,1,n,pos[i],1);
    for(int i=k+1;i<=n;++i)sum[i] = sum[i-1] + v[i] - v[i-k];//sum[i] = soma terminando em i
 
    ll md = (k+1ll)/2, sobra = k - md;
 
    for(int i=k;i<=n;++i){
        if(i!=k){
            update(1,1,n,pos[i-k],0);
            update(1,1,n,pos[i],1);
        }
        pair<ll,ll>resp = query(1,1,n,md);
        cout<<((md-1ll)*resp.second - resp.first) +//esq
        (sum[i]-resp.first-resp.second-sobra*resp.second)<<" ";//dir
    }
}
