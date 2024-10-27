#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
 
const int inf = 2e9+1;
const int mod = 1e9+7;
const int maxn = 1e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
char grid[8][8];
bool col[8], d[15], dr[15];
int ans = 0;
 
void solve(int i){
    if(i==8)++ans;
    for(int j=0;j<8;++j){
        if(!col[j]&&!d[i+j]&&!dr[i-j+7]&&grid[i][j]=='.'){
            col[j] = d[i+j] = dr[i-j+7] = 1;
            solve(i+1);
            col[j] = d[i+j] = dr[i-j+7] = 0;
        }
    }
}
 
int main(){_
    for(int i=0;i<8;++i)for(int j=0;j<8;++j)cin>>grid[i][j];
    solve(0);
    cout<<ans<<endl;
}
