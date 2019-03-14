#include<bits/stdc++.h>

using namespace std;

int main(){

  ios_base::sync_with_stdio(false);

  int q;
  cin >> q;
  while(q--){

    long long int n, a, b, cost1, cost2;
    cin >> n >> a >> b;

    cost1 = n * a;
    cost2 = (b*(n/2)) + (n%2?a:0);
    // cout << cost1 << " " << cost2 << endl;
    if (n == 1){
      cout << a << endl;
    }
    else if (cost1 < cost2){
      cout << cost1 << endl;
    }
    else{
      cout << cost2 << endl;
    }
  }

}
