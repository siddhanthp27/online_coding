#include<bits/stdc++.h>
#define long long int int

using namespace std;

int gcd(int a, int b){
  if (a == 0)
    return b;
  return gcd(b%a, a);
}

int main(){
  ios_base::sync_with_stdio(false);

  int y, w, m, a, b, g;
  cin >> y >> w;
  m = 6 - max(y, w) + 1;
  a = m;
  // cout << "a = " << a << endl;
  b = 6;

  g = gcd(a, b);
  // cout << "gcd = " << g << endl;
  a = a / g;
  b = b / g;
  cout << a << "/" << b << endl;
  return 0;
}
