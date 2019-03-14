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

  int n, k,ans=0;
  cin >> n >> k;
  int arr[n], rem[k];
  REP(i, k){
    rem[i] = 0;
  }
  REP(i, n){
    cin >> arr[i];
  }
  sort(arr, arr+n);
  REP(i, n){
    rem[arr[i]%k]++;
  }
  ans += (rem[0] / 2);
  if (k%2){
    FOR(i, 1, k/2){
      ans += min(rem[i], rem[k-i]);
    }
  }
  else{
    FOR(i, 1, k/2-1){
      ans += min(rem[i], rem[k-i]);
    }
    ans += rem[k/2]/2;
  }
  cout << ans*2 << endl;
  return 0;
}
