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
 
int best[maxn];
 
int main(){_
    int n;cin>>n;
    vector<ii>v;
    for(int i=1;i<=n;++i){
        int x,y;cin>>x>>y;
        v.pb({y,x});
    }    
    sort(all(v));
    best[0] = 1;
 
    for(int i=1;i<n;++i){
        int melhor = lower_bound(all(v),make_pair(v[i].second+1,0)) - begin(v);
        best[i] = best[i-1]; 
        if(melhor>0)ckmax(best[i], best[melhor-1]+1);
    }
 
    cout<<best[n-1]<<endl;
        
}
