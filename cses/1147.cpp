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
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
char grid[1001][1001];
int prefix[1001][1001];
int le[1001],ri[1001];
int main(){_
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>grid[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]=='*')prefix[i][j]=0;
            else prefix[i][j] = prefix[i-1][j]+1;
        }
    }   
    int ans=0;
    for(int i=1;i<=n;i++){
        stack<ii>st;
        st.push({-1,0});
        for(int j=1;j<=m;j++){
            while(!st.empty()&&st.top().first>=prefix[i][j])st.pop();
            le[j] = st.top().second;
            st.push({prefix[i][j],j});
        }
        while(!st.empty())st.pop();
        st.push({-1,m+1});
        for(int j=m;j>=1;j--){
            while(!st.empty()&&st.top().first>=prefix[i][j])st.pop();
            ri[j] = st.top().second;
            st.push({prefix[i][j],j});
        }
        for(int j=1;j<=m;j++){
            ckmax(ans,(ri[j]-le[j]-1)*prefix[i][j]);
        }
    }
    
    cout<<ans<<endl;
}
