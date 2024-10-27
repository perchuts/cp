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
int w[1001],v[1001],dp[1001][100001];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,x;cin>>n>>x;   
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(w[i]>j)dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout<<dp[n][x]<<endl;
}
