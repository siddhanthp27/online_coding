#include<bits/stdc++.h>
#include<iostream>

using namespace std;

bool is_prime(double srt){
  long long no = (int)srt;
  int lim = (int)sqrt(no);
  if (no <= 1){
    return false;
  }
  if (no <= 3){
    return true;
  }
  if ((no%2 == 0) || (no%3==0)){
    return false;
  }
  for (int i = 5 ; i <= lim; i+=6){
    if (no % i == 0){
      return false;
    }
    if (no % (i+2) == 0){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  while (n--){
    long long num;
    cin >> num;
    if (num == 1){
      cout << "NO" << endl;
      continue;
    }
    double srt;
    srt = sqrt(num);
    // printf("%f", srt - (int)srt);
    if ((srt - (int)srt) == 0){
      if (is_prime(srt)){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
    else{
      cout << "NO" << endl;
    }
  }
  return 0;
}
