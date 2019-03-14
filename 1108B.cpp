#include<bits/stdc++.h>

using namespace std;

int main(){
  long long int n, num1, num2, index = 0;
  cin >> n;
  vector<int> arr(n), div1(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    div1[i] = arr[i];
  }
  sort(arr.begin(), arr.end());
  sort(div1.begin(), div1.end());
  num2 = arr[arr.size()-1];
  set<int> div2;
  for(int i = 0; i < n; i++){
    if (num2 % arr[i] == 0)
      div2.insert(arr[i]);
  }
  set<int>::iterator it;
  for(it=div2.begin(); it!=div2.end(); it++){
    // cout << *it << endl;
    while(div1[index] < *it)
      index++;
    if (div1[index] == *it)
      div1[index] = -1;
  }
  sort(div1.begin(), div1.end());
  cout << div1[n-1] << " " << num2 << endl;
  return 0;
}
