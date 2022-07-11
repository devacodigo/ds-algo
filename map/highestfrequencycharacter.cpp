#include <bits/stdc++.h>
using namespace std;
int main() {

  string str;
  cin >> str;

  unordered_map<char, int> fmap;
  for (int i = 0; i < str.size(); i++) {
    fmap[str[i]]++;
  }

  int maxcount = 0;
  char ch;

  for (pair<char, int>  m : fmap) {
    if (m.second > maxcount)
    {
      maxcount = m.second;
      ch = m.first;
    }
  }
  cout << ch;
}