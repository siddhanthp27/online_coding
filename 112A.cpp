#include<bits/stdc++.h>
#define long long int int

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  string a, b;
  int n, a_char, b_char;
  cin >> a >> b;
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  transform(b.begin(), b.end(), b.begin(), ::tolower);

  n = a.length();

  for(int i = 0; i < n; i++){
    a_char = (int)a[i];
    b_char = (int)b[i];
    if (a_char != b_char){
      if (a_char < b_char){
        cout << -1 << endl;
        return 0;
      }
      else{
        cout << 1 << endl;
        return 0;
      }
    }
  }

  cout << 0 << endl;
  return 0;
}
