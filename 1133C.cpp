#include<bits/stdc++.h>
#define long long int int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int n, start, end, max_gap = 0;
  cin >> n;
  vector<int> arr(n);
  REP(i, n){
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  // REP(i, n){
  //   cout << arr[i] << " ";
  // }
  cout << endl;
  start = 0;
  end = 0;
  do{

    if (arr[end]-arr[start] <= 5 && end < n){
      max_gap = max(max_gap, end-start+1);
      // cout << "start = " << start << endl;
      // cout << "end = " << end << endl;
    }

    if (arr[end] - arr[start] <= 5 && end < n){
      end++;
    }
    else{
      start++;
    }

  }while(start < n);
  cout << max_gap << endl;
  return 0;
}
