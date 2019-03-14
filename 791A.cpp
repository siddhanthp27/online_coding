#include<bits/stdc++.h>
#define long long int int

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

    int a, b, ans = 0;
    cin >> a >> b;
    while(a <= b){
      a *= 3;
      b *= 2;
      ans++;
    }
    cout << ans << endl;
    return 0;
}
