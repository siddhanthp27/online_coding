#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  string seed[6];
  seed[0] = "RGB";
  seed[1] = "RBG";
  seed[2] = "GBR";
  seed[3] = "GRB";
  seed[4] = "BGR";
  seed[5] = "BRG";
  string ans = "", temp;
  int min_dist = n, dist;
  for(int i = 0; i < 6; i++){

    temp = "";
    for(int j = 0; j < n/3; j++){
      temp += seed[i];
    }
    for(int j = 0; j < n%3; j++){
      temp += seed[i][j];
    }

    dist = 0;
    for(int j = 0; j < n; j++){
      if (temp[j] != s[j])
        dist++;
    }

    if (dist < min_dist){
      min_dist = dist;
      ans = temp;
    }

  }

  cout << min_dist << endl;
  cout << ans << endl;
  return 0;
}
