#include<bits/stdc++.h>

// typedef long long int int;

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  long long int n, m, sum = 0, it_m;
  cin >> n;
  vector<long long int> arr(n);
  for(long long int i = 0; i < n; i++){
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr.begin(), arr.end());
  cin >> m;
  for(long long int i = 0; i < m; i++){
    cin >> it_m;
    cout << sum - arr[n-it_m] << endl;
  }
  return 0;
}
