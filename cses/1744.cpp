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
const int maxn = 505;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
int dp[maxn][maxn];
int main(){_
    int n, m;cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(i==j)dp[i][j] = 0;
            else{
                int best = inf;
                for(int k=1;k<=i/2;++k)ckmin(best,dp[k][j]+dp[i-k][j]);
                for(int k=1;k<=j/2;++k)ckmin(best,dp[i][k]+dp[i][j-k]);
                dp[i][j] = best+1;
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
