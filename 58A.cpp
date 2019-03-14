#include<bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.length();
  int a[5];
  for(int i = 0; i < 5; i++){
    a[i] = -1;
  }
  for(int i = 0; i < n; i++){
    if (s[i] == 'h'){
      if (a[0] == -1)
        a[0] = i;
    }
    else if (s[i] == 'e'){
      if (a[1] == -1 && i > a[0])
        a[1] = i;
    }
    else if (s[i] == 'l'){
      if (a[2] == -1 && i > a[1])
        a[2] = i;
      else{
        if (a[3] == -1)
          a[3] = i;
      }
    }
    else if (s[i] == 'o'){
      if (a[4] == -1)
        a[4] = i;
    }
  }
  bool is_there = false;
  for(int i = 0; i < 5; i++){
    if (a[i] == -1)
      is_there = true;
  }
  if (is_there){
    cout << "NO" << endl;
    return 0;
  }
  for(int i = 0; i < 4; i++){
    if (a[i] > a[i+1]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
