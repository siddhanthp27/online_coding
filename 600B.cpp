#include<bits/stdc++.h>

using namespace std;

int findIndex(vector<int>& a, int key, int low, int high){
  if (key < a[low])
    return -1;
  if (key >= a[high])
    return high;
  int mid, n = a.size();
  while(low <= high){
    mid = (low + high) / 2;
    if (a[mid] == key){
      int temp_mid = findIndex(a, key, mid+1, high);
      mid = max(mid, temp_mid);

      // while(mid<n && a[mid]==key)
      //   mid++;
      break;
    }
    if (a[mid] > key){
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }
  // printf("%d, %d, %d\n", low, mid, high);
  if (mid < n && a[mid] < key)
    return mid+1;
  return mid;
}

int main(){

  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < m; i++){
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  // sort(b.begin(), b.end());

  for(int i = 0; i < m; i++){
    if (b[i] < a[0]){
      cout << 0 << " ";
    }
    else if (b[i] >= a[a.size()-1]){
      cout << n << endl;
    }
    else{
      int mid = findIndex(a, b[i], 0, a.size()-1);
      cout << mid << " ";
    }
  }
  cout << endl;

  return 0;
}
