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
const int maxn = 5001;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
ll v[maxn], dp[maxn][maxn][2];
bool mark[maxn][maxn][2];
 
ll solve(int l,int r,bool turn){
    if(mark[l][r][turn])return dp[l][r][turn];
    if(l==r)return turn?-v[l]:v[l];
    mark[l][r][turn] = 1;
    if(turn){
        return dp[l][r][turn] = min(solve(l+1,r,0)-v[l],solve(l,r-1,0)-v[r]);
    }else{
        return dp[l][r][turn] = max(solve(l+1,r,1)+v[l],solve(l,r-1,1)+v[r]);
    }
}
 
int main(){_
    int n;cin>>n;
    ll tot = 0;
    for(int i=1;i<=n;++i)cin>>v[i], tot += v[i];
    cout<<(tot+solve(1,n,0))/2<<endl;
}
