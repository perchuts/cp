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
 
int v[maxn], table[maxn][20];
int main(){_
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>v[i];
 
    for(int j=0;j<20;++j){
        for(int i=1;i+(1<<j)<=n+1;++i){
            if(j==0)table[i][j] = v[i];
            else table[i][j] = min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
        }
    }
    
    auto query = [&](int l,int r){
        int ans = inf, current = l;
        for(int i=19;~i;--i){
            if(current+(1<<i)<=r+1)ckmin(ans,table[current][i]), current += (1<<i);
        }
        return ans;
    };
 
    for(int i=1;i<=q;++i){
        int l,r;cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
}
