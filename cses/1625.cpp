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
 
int a[8] = {1,-1,0,0,0,0,1,-1};
char c[4] = {'D','U','R','L'};
 
bool valid(int x,int y){return x>=1&&y>=1&&x<=7&&y<=7;}
 
bool mark[10][10];
 
string s;
 
int solve(int i,int j,int step){
    if(step==48&&i==7&j==1)return 1;
    if(i==7&&j==1)return 0;
    if((mark[i-1][j]&&mark[i+1][j])&&(!mark[i][j+1]&&!mark[i][j-1])||
    (!mark[i-1][j]&&!mark[i+1][j])&&(mark[i][j+1]&&mark[i][j-1]))return 0;
    int ans = 0;
    for(int k=0;k<4;++k){
        int x2 = i + a[k], y2 = j + a[k+4];
        if((s[step]=='?'||s[step]==c[k])&&valid(x2,y2)&&!mark[x2][y2]){
            mark[x2][y2] = 1;
            ans += solve(x2,y2,step+1);
            mark[x2][y2] = 0;
        }
    }
    return ans;
}
 
int main(){_
    cin>>s;
    for(int i=0;i<=8;++i)mark[i][0] = mark[0][i] = mark[8][i] = mark[i][8] = 1;
    mark[1][1] = 1;
    cout<<solve(1,1,0)<<endl;
}
