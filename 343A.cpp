#include<bits/stdc++.h>
#include<iostream>

using namespace std;

long long count_res(long long a, long long b){
  if (a == 0)
    return b;
  long long diff = b - a;
  long long sum = 0;
  while (b > 1 && a > 1){
    // cout << "diff = " << diff << endl;
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;
    if (a < b){
      long long l = b / a;
      sum += l;
      diff = b - l*a;
      b = diff;
      // cout << "diff = " << diff << endl;
      // cout << "a = " << a << endl;
      // cout << "b = " << b << endl;
      // cout << "sum = " << sum << endl;
      // diff = abs(a - b);
    }
    else{
      long long l = a /b;
      sum += l;
      diff = a - l * b;
      a = b;
      b = diff;
      // cout << "diff = " << diff << endl;
      // cout << "a = " << a << endl;
      // cout << "b = " << b << endl;
      // cout << "sum = " << sum << endl;
      // diff = abs(a-b);
    }
  }
  if (b <= 1)
    return sum + a;
  else
    return sum + b;
}

int main(){
  long long a, b;
  cin >> a >> b ;
  if (b == 1){
    cout << a << endl;
    return 0;
  }
  if (a == 1){
    cout << b << endl;
    return 0;
  }
  long long ser = (a/b);
  long long rem = a - ser * b;
  cout << ser + count_res(rem, b) << endl;
  return 0;
}
