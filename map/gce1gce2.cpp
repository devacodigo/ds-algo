// 1. You are given a number n1, representing the size of array a1.
// 2. You are given n1 numbers, representing elements of array a1.
// 3. You are given a number n2, representing the size of array a2.
// 4. You are given n2 numbers, representing elements of array a2.
// 5. You are required to print all elements of a2 which are also present in a1 (in order of their occurence in a2). Make sure to not print duplicates (a2 may have same value present many times).

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n1,n2;
  cin>>n1;
  vector<int>a(n1);
  for(int i=0;i<n1;i++){
    cin>>a[i];

  }
  cin>>n2;
  vector<int>b(n2);
  for(int i=0;i<n2;i++){
    cin>>b[i];

  }

  map<int,int>q;
  map<int,int>w;

  for(int i:a){
    q[i]++;
  }
  

  for(int m :b){
    if(q.find(m)!=q.end()){
      cout<<m<<endl;
      q.erase(m);

    }
  }

  
}