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
 
 
void solve(){
    int n,k;cin>>n>>k;
    int sq = (int)sqrt(n) + ((int)sqrt(n)*(int)sqrt(n)!=n);
    if(k<sq)cout<<"IMPOSSIBLE"<<endl;
    else{
        k = n-k;
        int blocos = k/sq;
        k += blocos;
        if(k/sq>blocos)blocos = k/sq, ++k;
        if(k/sq>blocos)blocos = k/sq, ++k;
        vector<int>ans;
        for(int i=1;i<=blocos;++i){
            for(int j=i*sq;j>(i-1)*sq;--j)ans.pb(j);
        }        
        k %= sq;
        for(int j=min((blocos+1)*sq,n);j>min((blocos+1)*sq,n)-k;--j)ans.pb(j);
        for(int j=blocos*sq+1;j<=min((blocos+1)*sq,n)-k;++j)ans.pb(j);
        for(int j=(blocos+1)*sq+1;j<=n;++j)ans.pb(j);
        for(auto x:ans)cout<<x<<" ";
        cout<<endl;
    }
}
 
 
int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int t;cin>>t;
    while(t--)solve();
}
