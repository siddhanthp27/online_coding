#include<bits/stdc++.h>

using namespace std;

int main(){

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> arr(n*n);
  map<int, int> m;
  map<int, int>::iterator it;

  for(int i = 0; i < n*n; i++){
    cin >> arr[i];
  }

  for(int i = 0; i < n*n; i++){
    m[arr[i]] = m[arr[i]] + 1;
  }

  // for(it=m.begin(); it!=m.end(); it++){
  //   cout << it->first << " " << it->second << endl;
  // }

  if (n % 2 == 0){

    int tot = (n*n)/4, count = 0;
    for(it=m.begin(); it!=m.end(); it++){
      // cout << it->first << " " << it->second << endl;
      count += (it->second) / 4;
      it->second /= 4;
    }
    if (count == tot){
      cout << "YES" << endl;
      int ans[n][n];
      it = m.begin();
      for(int i = 0; i < n / 2; i++){
        for(int j = 0; j < n / 2; j++){

          if (it->second == 0){
            it++;
          }

          ans[i][j] = ans[n-1-i][j] = ans[i][n-1-j] = ans[n-1-i][n-1-j] = it->first;
          it->second -= 1;

        }
      }

      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          cout << ans[i][j] << " ";
        }
        cout << endl;
      }
    }
    else
      cout << "NO" << endl;

  }
  else{

    int tot = ((n-1)*(n-1))/4, count_4 = 0, count_2=0, count_1=0, quot_4, quot_2;
    bool isPal = false;
    for(it=m.begin(); it!=m.end(); it++){

      quot_4 = (it->second) / 4;
      count_4 += quot_4;
      if (it->second - (quot_4*4)){
        quot_2 = (it->second - (quot_4*4)) / 2;
        count_2 += quot_2;
      }
      if (it->second % 2){
        count_1 += 1;
      }

    }

    if (count_4 >= tot){

      if (count_4 > tot){
        count_2 += (count_4 - tot)*2;
      }

      if (count_2 == 2*(n/2)){

        if (count_1 == 1){
          isPal = true;
          cout << "YES" << endl;

          int ans[n][n];
          it = m.begin();
          for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
              while( it->second / 4 == 0){
                it++;
              }
              ans[i][j] = ans[n-1-i][j] = ans[i][n-1-j] = ans[n-1-i][n-1-j] = it->first;
              it->second -= 4;
            }
          }

          it = m.begin();

          for(int i = 0; i < n/2; i++){

            while(it->second / 2 == 0){
              it++;
            }
            ans[i][n/2] = ans[n-1-i][n/2] = it->first;
            it->second -= 2;

          }

          for(int i = 0; i < n/2; i++){

            while(it->second / 2 == 0){
              it++;
            }
            ans[n/2][i] = ans[n/2][n-1-i] = it->first;
            it->second -= 2;

          }

          it = m.begin();

          while(it->second / 1 != 1){
            it++;
          }

          ans[n/2][n/2] = it->first;

          for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
              cout << ans[i][j] << " ";
            }
            cout << endl;
          }

        }

      }

    }

    if (!isPal)
      cout << "NO" << endl;

    // cout << tot << " " << count_4 << " " << count_2 << " " << count_1 << endl;
  }

  return 0;
}
