#include<bits/stdc++.h>
#define long long int int

using namespace std;

int char_to_int(char s){
  return s - '0';
}

int main(){
  ios_base::sync_with_stdio(false);

  string start, end;
  cin >> start;
  cin >> end;
  int h1, h2, m1, m2, net_diff = 0, ans_h, ans_m;
  string h, m;

  h1 = char_to_int(start[0])*10 + char_to_int(start[1]);
  m1 = char_to_int(start[3])*10 + char_to_int(start[4]);
  h2 = char_to_int(end[0])*10 + char_to_int(end[1]);
  m2 = char_to_int(end[3])*10 + char_to_int(end[4]);

  net_diff = (h2*60+m2)-(h1*60+m1);
  net_diff /= 2;

  ans_h = (h1*60+m1+net_diff)/60;
  ans_m = (h1*60+m1+net_diff)%60;

  if (ans_h < 10){
    h = "0" + to_string(ans_h);
  }
  else{
    h = to_string(ans_h);
  }

  if (ans_m < 10){
    m = "0" + to_string(ans_m);
  }
  else{
    m = to_string(ans_m);
  }

  cout << h << ":" << m << endl;
  return 0;

}
