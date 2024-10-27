#include <bits/stdc++.h>
 
using namespace std;
 
int contagem[200];
int main(int argc, char const *argv[]) {
  char ans[1000020];
  string a;
  cin>>a;
  set<char>letras;
  int N = int(a.size());
  for(int i=0;i<a.size();i++){
    letras.insert(a[i]);
    contagem[a[i]]++;
  }
  if(a.size()%2){
  int impar=0;
  char meio = '%';
  for(set<char>::iterator it = letras.begin();it!=letras.end();++it){
    if(contagem[*it]%2){
      impar++;
      meio = *it;
    }
    if(impar>1){
      cout<<"NO SOLUTION";
      return 0;
    }
  }
  int i=0;
  for(set<char>::iterator it = letras.begin();it!=letras.end();++it){
    if(meio==*it){
      ans[N/2] = *it;
      for(int k=1;k<=(contagem[*it]-1)/2;k++){
        ans[(N/2)+i+k] = *it;
        ans[(N/2)-i-k] = *it;
      }
      i+=(contagem[*it]-1)/2;
    }else{
    for(int k=1;k<=contagem[*it]/2;k++){
      ans[(N/2)+i+k] = *it;
      ans[(N/2)-i-k] = *it;
    }
    i+=contagem[*it]/2;
  }
}
}else{
  for(set<char>::iterator it = letras.begin();it!=letras.end();++it){
    if(contagem[*it]%2){
      cout<<"NO SOLUTION";
      return 0;
    }
  }
    int i=0;
    for(set<char>::iterator it = letras.begin();it!=letras.end();++it){
 
      for(int k=1;k<=contagem[*it]/2;k++){
        ans[i+k-1] = *it;
        ans[N-i-k] = *it;
      }
      i+=contagem[*it]/2;
    }
 
}
  for(int i=0;i<N;i++){
    cout<<ans[i];
  }
  return 0;
}
