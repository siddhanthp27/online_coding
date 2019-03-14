#include<bits/stdc++.h>

using namespace std;
int m, n;
vector<int> cap;

bool can(int k){
  int temp_tot = 0;

  for(int i = 0; i < n; i++){
    temp_tot += max(0, cap[i] - (i/k));
  }

  return temp_tot >= m;
}

int main(){
  int tot_cap = 0, temp;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> temp;
    cap.push_back(temp);
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

  int l = 1, r = n;

  while(r - l > 1){
    int mid = (l + r) / 2;
    if (can(mid))
      r = mid;
    else l = mid;
  }

  if (can(l))
    cout << l << endl;
  else if (can(r))
    cout << r << endl;
  else
    cout << -1 << endl;

  return 0;
}
