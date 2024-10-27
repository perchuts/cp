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
#define inf (int)(2e9+1)
#define mod (int)(1e9+7)
 
using namespace std;
char grid[1001][1001];
int dp[1001][1001];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>grid[i][j];
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j]=='*')continue;
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        }
    }
    cout<<(grid[1][1]=='.' ? dp[n][n] : 0)<<endl;
            
}
