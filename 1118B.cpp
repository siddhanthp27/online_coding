#include<bits/stdc++.h>

using namespace std;

int main(){

  ios_base::sync_with_stdio(false);

  long long int n, odd_sum = 0, even_sum = 0, temp_odd_sum = 0, temp_even_sum=0, ans = 0;
  cin >> n;

  vector<int> arr(n);
  vector<int> even_sum_array(n, 0), odd_sum_array(n, 0);

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  for(int i = 0; i < n; i+=2){
    odd_sum += arr[i];
  }

  for(int i = 1; i < n; i+=2){
    even_sum += arr[i];
  }

  for(int i = 0; i < n; i++){
    if (i % 2 == 0){
      temp_odd_sum += arr[i];
      odd_sum_array[i] = odd_sum - temp_odd_sum;
      even_sum_array[i] = even_sum - temp_even_sum;
    }
    else{
      temp_even_sum += arr[i];
      odd_sum_array[i] = odd_sum - temp_odd_sum;
      even_sum_array[i] = even_sum - temp_even_sum;
    }
  }

  temp_odd_sum = 0, temp_even_sum = 0;

  // cout << "Even Sum Array:" << endl;
  // for(int i = 0; i < n; i++){
  //   cout << even_sum_array[i] << " ";
  // }
  // cout << endl;
  //
  // cout << "Odd Sum Array:" << endl;
  // for(int i = 0; i < n; i++){
  //   cout << odd_sum_array[i] << " ";
  // }
  // cout << endl;

  temp_odd_sum = 0, temp_even_sum = 0;
  for(int i = 0; i < n; i++){

    // cout << temp_odd_sum + even_sum_array[i] << " ";
    // cout << temp_even_sum + odd_sum_array[i] << endl;

    if ((temp_even_sum + odd_sum_array[i]) == (temp_odd_sum + even_sum_array[i])){
      ans += 1;
    }

    if (i%2==0){
      temp_odd_sum += arr[i];
    }
    else{
      temp_even_sum += arr[i];
    }

  }

  cout << ans << endl;

  return 0;
}
