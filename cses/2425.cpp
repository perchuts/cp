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
 
pair<ii,int> seg[4*maxn];
 
void update(int i,int l,int r,int x,int d){
    if(l==r){
        seg[i] = {{d,d},d};        
        return;
    }
    int md = (l+r)/2;
    if(x<=md)update(2*i,l,md,x,d);
    else update(2*i+1,md+1,r,x,d);
    seg[i].second = seg[2*i+1].second + seg[2*i].second;
    seg[i].first.first = max(seg[2*i+1].first.first,seg[2*i+1].second+seg[2*i].first.first);
    seg[i].first.second = min(seg[2*i+1].first.second,seg[2*i+1].second+seg[2*i].first.second);
}
 
int main(){_
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        int w,t;cin>>w>>t;
        update(1,1,n,w,t==1?1:-1);
        if(seg[1].first.first<=0)cout << "<" << endl;
        else if(seg[1].first.second>=0) cout << ">" << endl;
        else cout << "?" << endl;
    }    
}
