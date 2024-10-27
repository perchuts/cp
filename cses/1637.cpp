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
int dp[10*maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        dp[i]=inf;
    for(int i=1;i<=n;i++){
        int cur=i;
        while(cur){
            int rem=cur%10;
            if(rem<=i)
                dp[i]=min(dp[i],dp[i-rem]+1);
            cur/=10;
        }
    }   
    cout<<dp[n]<<endl;
}
