#include<bits/stdc++.h>
#define M 100001
#define N 1000001
using namespace std;

vector<vector<pair<int, int> > > adj_list(M);
vector<int> dfs_num(M, 0), dfs_low(M, 0), isbridge(N, 0), dfs_parent(M, 0), vis(M, 0);
int dfsComp;

void dfs(int u){
  vis[u] = 1;
  dfs_num[u] = dfs_low[u] = ++dfsComp;
  for(int i = 0; i < adj_list[u].size(); i++){
    if (!vis[adj_list[u][i].first]){
      dfs_parent[adj_list[u][i].first] = u;
      dfs(adj_list[u][i].first);
      dfs_low[u] = min(dfs_low[u], dfs_low[adj_list[u][i].first]);
      if (dfs_low[adj_list[u][i].first] > dfs_num[u]){
        isbridge[adj_list[u][i].second] = 1;
      }
    }
    else if (adj_list[u][i].first != dfs_parent[u]){
      dfs_low[u] = min(dfs_low[u], dfs_low[adj_list[u][i].first]);
    }
  }
}

int main(){
  long n, m, q, u, v, z;
  scanf("%ld %ld %ld", &n, &m, &q);
  for(long i = 0; i < m; i++){
    scanf("%ld %ld %ld", &u, &v, &z);
    adj_list[u-1].push_back(make_pair(v-1, z));
    adj_list[v-1].push_back(make_pair(u-1, z));
  }
  dfsComp = 0;
  for(long i = 0; i < n; i++){
    if (vis[i] == 0){
      dfs(i);
    }
  }
  for(long i = 0; i < q; i++){
    scanf("%ld", &z);
    if (isbridge[z]){
      printf("YES\n");
    }
    else{
      printf("no\n");
    }
  }
  return 0;
}
