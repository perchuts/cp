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
  long long int ans = 0;
  cin>>N;
  while(1){
    ans+= N/5;
    N/=5;
    if(N<5)break;
  }
  cout<<ans;
 
 
  return 0;
}
