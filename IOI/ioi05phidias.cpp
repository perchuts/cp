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
#define f first
#define s second
using namespace std;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

ii block[201];
int dp[1000][1000];
bool has[1000][1000],mark[1000][1000];

int solve(int w,int h){
    if(mark[w][h])return dp[w][h];
    mark[w][h] = 1;
    if(has[w][h])return dp[w][h] = 0;
    dp[w][h] = w*h;
    for(int i=1;i<w;i++)ckmin(dp[w][h],solve(i,h)+solve(w-i,h));
    for(int i=1;i<h;i++)ckmin(dp[w][h],solve(w,i)+solve(w,h-i));
    return dp[w][h];
}

int main(){_
    int n,w,h;cin>>w>>h>>n;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        has[x][y] = 1;
    }
    for(int i=1;i<=w;i++){ //iterative is waay faster (~7 times faster)
        for(int j=1;j<=h;j++){
            if(has[i][j]){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = i*j;
            for(int k=1;k<i;k++){
                ckmin(dp[i][j],dp[k][j]+dp[i-k][j]);
            }
            for(int k=1;k<j;k++){
                ckmin(dp[i][j],dp[i][k]+dp[i][j-k]);
            }
        }
    }
    cout<<dp[w][h]<<endl;

}