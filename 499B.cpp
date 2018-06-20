#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
  int n, l;
  map<string, string> m;
  vector<string> ip, op;
  cin >> n >> l;
  for (int i = 0; i < l; i++){
    string a, b;
    cin >> a >> b;
    m.insert(pair<string, string> (a, b));
    m.insert(pair<string, string> (b, a));
  }
  while(n--){
    map<string, string>::iterator it;
    string s1, s2;
    cin >> s1;
    it = m.find(s1);
    s2 = it->second;
    if (s1.length() <= s2.length()){
      cout << s1 << " ";
    }
    else{
      cout << s2 << " ";
    }
  }
  cout << endl;
  return 0;
}
