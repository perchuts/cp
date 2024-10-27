#include <bits/stdc++.h>
 
using namespace std;
 
long long int power(long long int a,long long int b){
  if(!b)return 1;
  int c=a;
  for(long long int i=1;i<b;i++){
    a*=c;
  }
  return a;
}
 
int main(int argc, char const *argv[]) {
  long long int N;
  cin>>N;
  cout<<N<<" ";
  while(N!=1){
    if(N%2){
      N*=3;
      N++;
    }else{
      N/=2;
    }
    cout<<N<<" ";
  }
 
  return 0;
}
