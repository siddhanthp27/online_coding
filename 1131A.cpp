#include<bits/stdc++.h>

using namespace std;

int main(){

  ios_base::sync_with_stdio(false);

  long long int w1, w2, h1, h2;
  cin >> w1 >> h1 >> w2 >> h2;

  cout << 2*(h1+h2+2) + 2*w2 + 2*(w1-w2) << endl;
  return 0;
}
