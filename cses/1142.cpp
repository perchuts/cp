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
 
ll v[2*maxn],le[2*maxn],ri[2*maxn];
int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    stack<ii>l,r;
    l.push({0,0});
    for(int i=1;i<=n;i++){
        while(l.top().first>=v[i])l.pop();
        le[i] = 1LL*l.top().second;
        l.push({v[i],i});
    }
    r.push({0,n+1});
    for(int i=n;i>=1;i--){
        while(r.top().first>v[i])r.pop();
        ri[i] = 1LL*r.top().second;
        r.push({v[i],i});     
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ckmax(ans,(ri[i]-le[i]-1LL)*v[i]);
    }
    cout<<ans<<endl;
}
