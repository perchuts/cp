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
#define inf 2000000001
#define mod 1000000007 //998244353
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

bool v[501];
int prefix[501];
int dp[501][501];
void solve(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        prefix[i]=prefix[i-1]+v[i];
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp[i][j]=inf;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            for(int l=i;l>=j;l--){
                int um=prefix[i]-prefix[l-1];
                dp[i][j]=min(dp[i][j],dp[l-1][j-1]+um*(i-l+1-um));
            }
        }
    }
    cout<<dp[n][k]<<endl;
    
}


int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int t=1;//cin>>t;
    while(t--)solve();
}   