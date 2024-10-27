#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
  double N;
  cin>>N;
  set<int>primeiro;
  set<int>segundo;
  for(int i=1;i<=N;i++)primeiro.insert(i);
  if(int(ceil(N/2))%2){
    cout<<"NO";
    return 0;
  }
  cout<<"YES"<<endl;
  long long int soma = N*(N+1)/4;
  int maior = N;
  while(true){
    primeiro.erase(maior);
    segundo.insert(maior);
    soma-=maior;
    maior--;
    if(soma<maior){
      if(soma==0)break;
      primeiro.erase(soma);
      segundo.insert(soma);
      break;
    }
  }
  cout<<primeiro.size()<<endl;
  for(set<int>::iterator it=primeiro.begin();it!=primeiro.end();++it){
    cout<< *it << " ";
  }
  cout<<endl<<segundo.size()<<endl;
  for(set<int>::iterator it=segundo.begin();it!=segundo.end();++it){
    cout<< *it << " ";
  }
  return 0;
}
