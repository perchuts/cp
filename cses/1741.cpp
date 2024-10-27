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
const int maxn = 2e6+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
struct Event{
    bool type;
    int x, l, r;
    Event(bool type,int x,int l,int r): type(type), x(x), l(l), r(r) {}
    bool operator < (const Event &k) const {return x<k.x;}
};
 
ii seg[4*maxn], lazy[4*maxn];
 
void push(int i,int l,int r){
    if(!lazy[i].second||!lazy[i].first)return;
    int k = lazy[i].first;
    seg[i].first += k;
    if(l!=r)lazy[2*i].second = lazy[2*i+1].second = 1, lazy[2*i].first +=  k, lazy[2*i+1].first += k;
    lazy[i] = {0,0};
}
 
void update(int i,int l,int r,int x,int y,int d){
    push(i,l,r);
    if(y<l||r<x)return;
    if(x<=l&&r<=y){
        lazy[i].second = 1, lazy[i].first += d;
        push(i,l,r);
        return;
    }
    int md = (l+r)/2;
    update(2*i,l,md,x,y,d), update(2*i+1,md+1,r,x,y,d);
    if(seg[2*i].first==seg[2*i+1].first)seg[i] = {seg[2*i].first,seg[2*i].second+seg[2*i+1].second};
    else seg[i] = min(seg[2*i],seg[2*i+1]);
} 
 
void build(int i,int l,int r){
    if(l==r){
        seg[i] = {0,1};
        return;
    }
    int md = (l+r)/2;
    build(2*i,l,md), build(2*i+1,md+1,r);
    seg[i] = {0,r-l+1};
}
 
int main(){_
    int n;cin>>n;
 
    vector<Event>sweep;
 
    for(int i=1;i<=n;++i){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        //all y coordinates should be shifted by 1e6+1 (ensures that all coordinates are positives)
        sweep.pb(Event(1,x1,y1+1e6+1,y2+1e6));
        sweep.pb(Event(0,x2,y1+1e6+1,y2+1e6));
    }
 
    sort(all(sweep));
 
    const int N = 2*1e6+1;
 
    build(1,1,N);
 
    ll ans = 0;
 
    for(int i=0;i<2*n;++i){
        // cout<<sweep[i].type<<" "<<sweep[i].x<<" "<<sweep[i].l<<" "<<sweep[i].r<<endl;
        if(sweep[i].type){
            update(1,1,N,sweep[i].l,sweep[i].r,1);
        }else{
            update(1,1,N,sweep[i].l,sweep[i].r,-1);
        }
        if(i!=2*n-1&&sweep[i].x!=sweep[i+1].x){
            auto [mn, qnt] = seg[1];
            // cout<<mn<<" "<<qnt<<endl;
            ans += ll(sweep[i+1].x-sweep[i].x)*ll(N-(mn==0?qnt:0));
            // cout<<ans<<endl;
        }
    }
    // cout<<seg[1].first<<" "<<seg[1].second<<endl;
    cout<<ans<<endl;
}
