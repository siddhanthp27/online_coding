#include<bits/stdc++.h>

using namespace std;

int main(){

  ios_base::sync_with_stdio(false);

  long long int n, ans = 0, s1, s2, min_index, max_index;
  cin >> n;
  vector< pair<int, int> > scores;

  for(int i = 0; i < n; i++){
    cin >> s1 >> s2;
    scores.push_back(make_pair(s1, s2));
  }

  // for(int i = 0; i < n; i++){
  //   cout << scores[i].first << " " << scores[i].second << endl;
  // }

  ans += (min(scores[0].first, scores[0].second) + 1);
  // cout << ans << endl;

  for(int i = 1; i < n; i++){

    if (scores[i-1].first > scores[i].second){
      // cout << "scores[i-1].first: " << scores[i-1].first << endl;
      // cout << "scores[i].second: " << scores[i].second << endl;
      // cout << "----" << endl;
      continue;
    }
    else if (scores[i-1].second > scores[i].first){
      // cout << "scores[i-1].second: " << scores[i-1].second << endl;
      // cout << "scores[i].first: " << scores[i].first << endl;
      // cout << "----" << endl;
      continue;
    }

    if (scores[i].first > scores[i-1].second){
      ans += (scores[i].first - scores[i-1].second);
      // cout << "scores[i-1].second: " << scores[i-1].second << endl;
      // cout << "scores[i].first: " << scores[i].first << endl;
      // cout << ans << endl;
      // cout << "----" << endl;

    }
    else if (scores[i-1].first < scores[i].second){
      ans += (scores[i].second - scores[i-1].first);
      // cout << "scores[i-1].first: " << scores[i-1].first << endl;
      // cout << "scores[i].second: " << scores[i].second << endl;
      // cout << ans << endl;
      // cout << "----" << endl;
    }

  }

  cout << ans << endl;
  return 0;
}
