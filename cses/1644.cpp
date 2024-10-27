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
 
ll v[2*maxn],pr[2*maxn];
int main(){_
    int n,a,b;cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        pr[i] = pr[i-1] + v[i];
    }
    multiset<ll>s;
    ll ans = -1e18;
    for(int i=a;i<=n;i++){
        s.insert(pr[i-a]);
        ans = max({ans,pr[i]-*begin(s),pr[i]-*prev(end(s))});
         if(i>=b){
             s.erase(s.find(pr[i-b]));
         }
    }        
 
    cout<<ans<<endl;
}


