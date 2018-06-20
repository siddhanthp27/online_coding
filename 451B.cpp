#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> diff(n-1);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if (i!=0){
      diff[i-1] = a[i] - a[i-1];
    }
  }
  // cout << "Diff array:" << endl;
  // for(int i = 0; i < n-1; i++){
  //   cout << diff[i] << " ";
  // }
  // cout << endl;
  bool all_pos = true;
  for(int i = 0; i < n-1; i++){
    if (diff[i] < 0){
      all_pos = false;
    }
  }
  if (all_pos){
    cout << "yes" << endl;
    cout << "1 1" << endl;
    return 0;
  }
  int begin = 0, end = n-1, count_seg = 0;
  bool is_there = false;
  for(int i = 0; i < n-1; i++){
    if (diff[i] <= -1 && !is_there){
      count_seg++;
      is_there = true;
      begin = i;
    }
    if (diff[i] > -1 && is_there){
      is_there = false;
      end = i;
    }
  }
  if (count_seg == 0 || count_seg > 1){
    cout << "no" << endl;
  }
  else{
    bool is_proper = true;
    // cout << "a[begin] = " << a[begin] << endl;
    // cout << "a[end+1] = " << a[end+1] << endl;
    if (begin != 0){
      if(a[end] - a[begin-1] < 0){
        is_proper = false;
      }
    }
    if (end != n - 1){
      if (a[end+1] - a[begin] < 0){
        is_proper = false;
      }
    }
    if (is_proper){
      cout << "yes" << endl;
      cout << begin+1 << " " << end+1 << endl;
    }
    else{
      cout << "no" << endl;
    }
  }
  return 0;
}
