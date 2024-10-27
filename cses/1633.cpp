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
int dp[maxn*10];
// int solve(int n){
//     if(n==0)return 1;
//     if(n<0)return 0;
//     if(dp[n]!=0)return dp[n];
//     for(int i=1;i<=6;i++)
//         dp[n]=(dp[n]+solve(n-i))%mod;
//     return dp[n];
// }
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;   
    dp[0]=1;
    for(int i=0;i<=n;i++)
        for(int j=1;j<=6;j++)
            dp[i+j]=(dp[i+j]+dp[i])%mod;
    cout<<dp[n]<<endl;
    // cout<<solve(n)<<endl;
}
