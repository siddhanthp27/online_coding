#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, m, tot_cap = 0;
  cin >> n >> m;
  vector<int> cap(n);
  for(int i = 0; i < n; i++){
    cin >> cap[i];
    tot_cap += cap[i];
  }

  sort(cap.rbegin(), cap.rend());
  // cout << "cap:" << endl;
  // for(int i = 0; i < n; i++){
  //   cout << cap[i] << " ";
  // }
  // cout << endl;

  if (tot_cap < m){
    cout << -1 << endl;
    return 0;
  }

  if (m < cap[0]){
    cout << 1 << endl;
    return 0;
  }

  int num_days = 0, temp_tot = 0;

  for(int k = 1; k <= n; k++){
    temp_tot = 0;

    for(int i = 0; i < n; i++){
      temp_tot += max(0, cap[i] - (i/k));
    }

    if (temp_tot >= m){
      num_days = k;
      break;
    }

  }

  cout << num_days << endl;

  return 0;
}
