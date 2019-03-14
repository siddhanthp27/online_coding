#include<bits/stdc++.h>

using namespace std;

int main(){

  ios_base::sync_with_stdio(false);

  int cnt1, cnt2, cnt3, cnt4;
  cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;

  if (cnt1 == cnt4){
    if (cnt1 == 0 && cnt3 != 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  else{
    cout << 0 << endl;
  }
}
