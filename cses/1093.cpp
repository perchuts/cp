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
const int maxn = 1e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
int dp[501][500*500+1];
int main(){_
    int n;cin>>n;  
    dp[0][0] = 1;  
    for(int i=1;i<=n;++i){
        for(int j=1;j<=(i*(i+1))/2;++j){
            dp[i][j] = dp[i-1][j];
            if(j>=i)dp[i][j] = (dp[i][j]+dp[i-1][j-i])%mod;
        }
    }
    if(n%4==3||n%4==0)cout<<dp[n][(n*(n+1))/4]<<endl;
    else cout<<0<<endl;
}
