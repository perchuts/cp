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
  int maior=1,temp=1;
  string a;
  cin>>a;
  for(int i=1;i<a.size();i++){
    if(a[i]==a[i-1])temp++;
    else{
      temp=1;
    }
    if(temp>maior)maior=temp;
  }
  cout<<maior;
 
 
  return 0;
}
