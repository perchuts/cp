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
 
int v[2*maxn];
 
int main(){_
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>v[i];    
    ll r=0;
    ll ans=0;
    set<int>s;
    map<int,int>cnt;
    for(ll l=1;l<=n;l++){
        while(sz(s)<=k&&r<n)cnt[v[++r]]++,s.insert(v[r]);
        if(sz(s)>k)s.erase(v[r]),cnt[v[r]]--,r--;
        ans+=r-l+1LL;
        cnt[v[l]]--;
        if(cnt[v[l]]==0)s.erase(v[l]);
    }
    cout<<ans<<endl;
}
