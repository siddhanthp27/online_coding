#include<bits/stdc++.h>
#include<stdint.h>
#include<iostream>

using namespace std;

int gcd(int a, int b){
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

int main(){
  uint64_t n, pro=1;
  cin >> n;
  if (n%2){
    if (n == 1){
      cout << 1 << endl;
      return 0;
    }
    pro = n * (n-1) * (n-2);
    cout << pro << endl;
  }
  else{
    if (n == 2){
      cout << 2 << endl;
      return 0;
    }
    uint64_t pro1, pro2, pro3;
    uint64_t gcd1 = gcd(n, n-2);
    uint64_t gcd2 = gcd(n, n-3);
    pro1 = (n * (n-1) * (n-2)) / gcd1;
    pro2 = n * (n-1) * (n-3) / gcd2;
    pro3 = (n-1) * (n-2) * (n-3);
    // cout << pro1 << endl;
    // cout << pro2 << endl;
    // cout << pro3 << endl;
    if (pro1 <= pro2 && pro3 <= pro2){
      cout << pro2 << endl;
    }
    else if (pro2 <= pro1 && pro3 <= pro1){
      cout << pro1 << endl;
    }
    else{
      cout << pro3 << endl;
    }
  }
  return 0;
}
