#include<bits/stdc++.h>
#define long long int int

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int count = 0;
  string s;
  cin >> s;
  set<char> chars;
  set<char>::iterator it;

  for(int i = 0; i < s.length(); i++){
    chars.insert(s[i]);
  }

  for(it=chars.begin(); it!=chars.end(); it++){
    count++;
  }
  if (!(count%2)){
    cout << "CHAT WITH HER!" << endl;
  }
  else{
    cout << "IGNORE HIM!" << endl;
  }
  return 0;
}
