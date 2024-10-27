#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
  int N,nambe[300000];
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>nambe[i];
  }
  long long int ans=0;
  for(int i=1;i<N;i++){
    if(nambe[i-1]>nambe[i]){
      ans+=nambe[i-1]-nambe[i];
      nambe[i] = nambe[i-1];
    }
  }
  cout<<ans;
}
