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

  int n, freq = 0;
  cin >> n;
  vector<int> a(n), b(n);
  map<double, int> m;
  REP(i, n){
    cin >> a[i];
  }
  REP(i, n){
    cin >> b[i];
  }
  REP(i, n){
    m[-1.0*b[i]/a[i]]++;
  }
  map<double,int>::iterator it;
  for(it=m.begin(); it!=m.end(); it++){
    freq = max(freq, it->second);
  }
  cout << freq << endl;
  return 0;
}
