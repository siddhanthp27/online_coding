#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair <int,int>
#define int long long

const int N = 100002;

vector<pii> adj_list[N];
set<pii> nodes;
map<pair<pii, int> > dfs_parent, visited, lookup, dist;
queue<pii> q;

void bfs(pair<int, int> p){
  q.push(p);
  map<pair<pii, int> > :: iterator it;
  pair<int, int> current;
  while(!q.empty()){
    current = q.front();
    q.pop();
    printf("Visiting %d,%d \n", current.first, current.second);
    for(int i = 0; i < adj_list[lookup[current]].size(); i++){
      if (visited[adj_list[lookup[current]][i]] == 0){
        dist[adj_list[lookup[current]][i]] =  dist[current] + 1;
        q.push(adj_list[lookup[current]][i]);
      }
    }
  }
}

int MOD = 1e9+7;

int gcd(int a, int b)
{
	while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int mexp(int a, int b) {
    if (b == 0) return 1;
    int t = mexp(a, b / 2);
    if (b % 2 == 0) return mod(t * t);
    else return mod(mod(t * t) * a);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int sx, sy, dx, dy, row, colmin, colmax;
    scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
    int t;
    int no = 0;
    pair<int, int> p;
    scanf("%d", &t);
    while(t--){
      scanf("%d %d %d", &row, &colmin, &colmax);
      for(int i = colmin, i <= colmax; i++){
        set.insert(make_pair(row, i));
        lookup.insert(make_pair(make_pair(row, i), no));
        visited.insert(make_pair(make_pair(row, i), 0));
        dist.insert(make_pair(make_pair(row, i), 0));
      }
    }
    set<pii> :: iterator it;
    for(it = nodes.begin(); it != nodes.end(); it++){
      
    }
 	return 0;
}
