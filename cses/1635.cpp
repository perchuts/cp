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
int v[100],dp[10*maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,x;cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>v[i];   
    dp[0]=1;
    for(int i=0;i<=x;i++)
        for(int j=0;j<n;j++){
            if(i+v[j]>=10*maxn)continue;
            dp[i+v[j]]=(dp[i+v[j]]+dp[i])%mod;
 
        }
    cout<<dp[x]<<endl;
    
}
