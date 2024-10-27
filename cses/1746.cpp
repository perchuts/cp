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
 
void modsum(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}
 
using namespace std;
int v[maxn],dp[maxn][101];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    if(v[1]!=0){
        dp[1][v[1]]=1;
    }else{
        for(int i=1;i<=m;i++)
            dp[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        if(v[i]!=0){
            modsum(dp[i][v[i]],dp[i-1][v[i]]);
            if(v[i]!=m)modsum(dp[i][v[i]],dp[i-1][v[i]+1]);
            if(v[i]!=1)modsum(dp[i][v[i]],dp[i-1][v[i]-1]);
            continue;
        }
        if(v[i-1]==0){
            for(int j=1;j<=m;j++){
                if(j!=1)modsum(dp[i][j],dp[i-1][j-1]);
                if(j!=m)modsum(dp[i][j],dp[i-1][j+1]);
                modsum(dp[i][j],dp[i-1][j]);
            }
        }else{
            modsum(dp[i][v[i-1]],dp[i-1][v[i-1]]);
            if(v[i-1]!=m)
                modsum(dp[i][v[i-1]+1],dp[i-1][v[i-1]]);
            
            if(v[i-1]!=1)
                modsum(dp[i][v[i-1]-1],dp[i-1][v[i-1]]);
            
        }
        
    }
    int ans=0;
    for(int i=1;i<=m;i++)
        modsum(ans,dp[n][i]);
    cout<<ans<<endl;
}
