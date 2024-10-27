#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
 
int n,m;
int visited[1050][1050];
char grid[1050][1050];
int A[8]={0,0,-1,1,1,-1,0,0};
int valido(int x,int y){return x>=1&&y>=1&&x<=n&&y<=m;}
 
void dfs(ii x){
  int a = x.first;
  int b = x.second;
  visited[a][b]=1;
  for(int k=0;k<4;k++){
    if(valido(a+A[k],b+A[k+4])&&!visited[a+A[k]][b+A[k+4]]&&grid[a+A[k]][b+A[k+4]]=='.'){
      dfs({a+A[k],b+A[k+4]});
    }
  }
}
int main(int argc, char const *argv[]) {
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>grid[i][j];
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(!visited[i][j]&&grid[i][j]=='.'){
        ans++;
        dfs({i,j});
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
