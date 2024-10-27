#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
  int N,a;
  set<int>numeros;
  cin>>N;
  for(int i=0;i<N-1;i++){
    cin>>a;
    numeros.insert(a);
  }
  for(int i=1;i<=N;i++){
    if(numeros.find(i)==numeros.end()){
      cout<<i;
      return 0;
    }
  }
  
}
