#include<bits/stdc++.h>

using namespace std;

int binary_search(vector<long long int>& arr, int key){
  int low, mid, high;
  low = 0, high = arr.size()-1;
  while(low < high){
    mid = (low + high) / 2;
    if (arr[mid] == key){
      return mid;
    }
    if (arr[mid] < key){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  if (arr[high] > key)
    return high-1;
  else
    return high;
}

int main(){
  ios_base::sync_with_stdio(false);
  long long int n, d, temp;
  cin >> n >> d;
  vector<long long int> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  long long int sum = 0, diff_index = 0;
  for(int i = 0; i < n; i++){
    long long int key = arr[i] + d;
    int index = binary_search(arr, key);
    diff_index = index - i;
    sum += ((diff_index)*(diff_index-1)) / 2;
    // printf("%d: %d: %d: %d\n", arr[i], key, index, diff_index);
  }
  cout << sum << endl;
  return 0;
}
