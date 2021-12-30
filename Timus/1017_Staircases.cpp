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

ll dp[510][510];
//dp[i][j] = i blocks avaliable and j blocks in biggest step

void solve(){
    int n;cin>>n;

    dp[0][0]=1;
    for(int i=0;i<=n;i++)
        for(int j=1;i+j<=n;j++)
            for(int k=0;k<j;k++)
                dp[i+j][j]+=dp[i][k];
    ll ans=0;
    for(int i=0;i<=n;i++)
        ans+=dp[n][i];
    
    cout<<ans-1<<endl;    
}


int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int t=1;//cin>>t;
    while(t--)solve();
}