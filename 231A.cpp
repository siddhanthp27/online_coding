#include<bits/stdc++.h>
#define long long int int

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int t, sum=0, temp_sum, yes_no;
  cin >> t;
  while(t--){
    temp_sum = 0;
    for(int i = 0; i < 3; i++){
      cin >> yes_no;
      temp_sum += yes_no;
    }
    if (temp_sum >= 2){
      sum++;
    }
  }
  cout << sum << endl;
}
