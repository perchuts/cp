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
const int maxn = 1000;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
int d[maxn][maxn][2], n, m;
bool vis[maxn][maxn][3], grid2[maxn][maxn];
string grid[maxn];
 
bool valid(int x,int y,int k){return (x>=0&&y>=0&&x<n&&y<m&&!vis[x][y][k]&&grid[x][y]!='#');}
 
int a[8] = {1,-1,0,0,0,0,-1,1}, where[maxn][maxn];
 
vector<ii>monsters;
 
int main(){_
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>grid[i];
    ii me;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            d[i][j][1] = d[i][j][0] = inf;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]=='M')monsters.pb({i,j});
            if(grid[i][j]=='A')me = {i,j};
        }
    }
    auto bfs = [&](int mode){
        queue<ii>q;
        if(mode==1){
            for(auto p:monsters){
                q.push(p);
                d[p.first][p.second][mode] = 0, vis[p.first][p.second][mode] = 1;
            }
        }else{
            q.push(me);
            d[me.first][me.second][mode] = 0, vis[me.first][me.second][mode] = 1;
        } 
        while(!q.empty()){
            auto [x,y] = q.front();q.pop();
            for(int i=0;i<4;++i){
                int x2 = x + a[i], y2 = y + a[i+4];
                if(valid(x2,y2,mode)){
                    vis[x2][y2][mode] = 1, d[x2][y2][mode] = d[x][y][mode] + 1; 
                    q.push({x2,y2});
                }
            }
        }
    };
    bfs(1);
    bfs(0);
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)grid2[i][j] = (d[i][j][0]<d[i][j][1]);
    auto bfs2 = [&](){
        queue<ii>q;q.push(me);
        vis[me.first][me.second][2] = 1;
        while(!q.empty()){
            auto [x,y] = q.front();q.pop();
            if(x==0||y==0||x==n-1||y==m-1)return make_pair(x,y);
            for(int i=0;i<4;++i){
                int x2 = x + a[i], y2 = y + a[i+4];
                if(valid(x2,y2,2)&&grid2[x2][y2]){
                    vis[x2][y2][2] = 1, where[x2][y2] = i;
                    q.push({x2,y2});
                }
            }
        }
        return make_pair(-1,-1);
    };
    string ans;
    ii cur = bfs2();
    if(cur.first==-1)cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        while(cur!=me){
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
