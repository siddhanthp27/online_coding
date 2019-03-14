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

  int n, k, ans = 0;
  cin >> n;
  vector<int> l(n), r(n);
  REP(i, n){
    cin >> l[i] >> r[i];
  }
  cin >> k;
  REP(i, n){
    if (k <= r[i])
      ans++;
  }
  cout << ans << endl;
  return 0;
}
