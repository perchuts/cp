#include <bits/stdc++.h>
 
using namespace std;
int n,m,ans=0;
vector<int>vizinhos[105000];
int visited[105000];
vector<int>componentes;
void dfs(int x){
  visited[x]=1;
  for(auto v:vizinhos[x]){
    if(!visited[v]){
      dfs(v);
    }
  }
}
int main(int argc, char const *argv[]) {
  cin>>n>>m;
  while(m--){
    int a,b;
    cin>>a>>b;
    vizinhos[a].push_back(b);
    vizinhos[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      ans++;
      componentes.push_back(i);
      dfs(i);
    }
  }
  cout<<ans-1<<endl;
  if(ans-1){
    for(int i=0;i<ans-1;i++){
      cout<<componentes[0]<<" "<<componentes[i+1]<<endl;
    }
  }
 
 
  return 0;
}
