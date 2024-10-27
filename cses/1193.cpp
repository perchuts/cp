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
 
string grid[1000];
bool vis[1000][1000];
int a[8] = {1,-1,0,0,0,0,-1,1}, n, m, where[1000][1000];
 
bool valid(int x,int y){return x>=0&&y>=0&&x<n&&y<m&&!vis[x][y]&&grid[x][y]!='#';}
 
int main(){_
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>grid[i];    
    ii start, target;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]=='A')start = {i,j};
            else if(grid[i][j]=='B')target = {i,j};
        }
    }
    queue<ii>q;
    q.push(start);
    vis[start.first][start.second] = 1;
    while(!q.empty()){
        auto [x,y] = q.front();q.pop();
        for(int i=0;i<4;++i){
            int x2 = x + a[i], y2 = y + a[i+4];
            if(valid(x2,y2)){
                vis[x2][y2] = 1, where[x2][y2] = i;
                q.push({x2,y2});
            }
        }
    }
    if(!vis[target.first][target.second])cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        string ans;
        ii cur = target;
        // for(int i=0;i<n;++i)for(int j=0;j<m;++j)cout<<where[i][j]<<" \n"[j==m-1];
        while(cur!=start){
            int w = where[cur.first][cur.second];
            if(w==0)ans += 'D';
            else if(w==1)ans += 'U';
            else if(w==2)ans += 'L';
            else if(w==3)ans += 'R';
            cur.first += -a[w], cur.second += -a[w+4];
        }
        reverse(all(ans));
        cout<<sz(ans)<<endl;
        cout<<ans<<endl;
    }
 
}


