#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int rec;

void dfs(vector<vector<int> > &adj_list, int anc, int u, int dfs_num[], int sum, int dist, int deg[]){
  // printf("Present at node %d\n", u);
  // printf("Sum = %d\n", sum);
  dfs_num[u] = 1;
  if (dist == 2){
    for(int i = 0; i < adj_list[u].size(); i++){
      if (adj_list[u][i] == anc && dfs_num[anc] == 1){
        rec = min(rec, sum + deg[u]);
      }
    }
    return;
  }
  for(int i = 0; i < adj_list[u].size(); i++){
    if (dfs_num[adj_list[u][i]] == 0){
      dfs(adj_list, anc, adj_list[u][i], dfs_num, sum+deg[u], dist+1, deg);
    }
  }
}

int main(){
  int n, m, u, v;
  cin >> n >> m;
  int deg[n], dfs_num[n];
  vector<vector<int> > adj_list(n);
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    adj_list[u-1].push_back(v-1);
    adj_list[v-1].push_back(u-1);
  }
  for(int i = 0; i < n; i++){
    deg[i] = adj_list[i].size();
    dfs_num[i] = 0;
  }
  // printf("Degree list:\n");
  // for(int i = 0; i < n; i++){
  //   printf("%d:%d\n", i, deg[i]);
  // }
  rec = 100000;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      dfs_num[j] = 0;
    }
    dfs(adj_list, i, i, dfs_num, 0, 0, deg);
  }
  if (rec != 100000)
    printf("%d\n", rec-6);
  else
    printf("-1\n");
  return 0;
}
