#include<bits/stdc++.h>
#include<iostream>
#define M 100001

using namespace std;
vector<vector<int> > adj_list(M);
vector<int> dfs_low(M, 0), dfs_num(M, 0), dfs_parent(M, 0), vis(M, 0);
bool ap[M];
int rootChildren = 0, dfscomp = 0;

void articulationPoints(int u){
  vis[u] = 1;
  // printf("At vertex %d\n", u);
  dfs_low[u] = dfs_num[u] = ++dfscomp;
  int child = 0;
  for(int i = 0; i < adj_list[u].size(); i++){
    if (!vis[adj_list[u][i]]){
      if (u == 0){
        rootChildren++;
      }
      child++;
      dfs_parent[adj_list[u][i]] = u;
      articulationPoints(adj_list[u][i]);
      dfs_low[u] = min(dfs_low[u], dfs_low[adj_list[u][i]]);
      if (dfs_parent[u] == -1 && child > 1){
          ap[true];
      }
      if (dfs_parent[u]!=-1 && dfs_low[adj_list[u][i]] >= dfs_num[u]){
        ap[u] = true;
      }
    }
    else if (adj_list[u][i] != dfs_parent[u]){
      dfs_low[u] = min(dfs_low[u], dfs_num[adj_list[u][i]]);
    }
  }
}

int main(){
  long n, m;
  scanf("%ld %ld", &n, &m);
  while(!(n==0 && m==0)){
    long u, v, ans=0;
    for(long i = 0; i < m; i++){
      scanf("%ld %ld", &u, &v);
      adj_list[u-1].push_back(v-1);
      adj_list[v-1].push_back(u-1);
    }
    for(int i = 0; i < n; i++){
      dfs_low[i] = dfs_num[i] = vis[i] = 0;
      dfs_parent[i] = -1;
      ap[i] = false;
    }
    // ap[0] = (rootChildren > 1)?1:0;
    for(int i = 0; i < n; i++){
      if (vis[i] == 0){
        rootChildren = dfscomp = 0;
        // dfs_parent[i] == -1;
        articulationPoints(i);
      }
    }
    // printf("Articulation Points\n");
    for(long i = 0; i < n; i++){
      // printf("%d\n", ap[i]);
      if (ap[i]){
        ans++;
      }
    }
    // printf("dfs_num\n");
    // for(long i = 0; i < n; i++){
    //   printf("%d\n", dfs_num[i]);
    // }
    // printf("dfs_low\n");
    // for(long i = 0; i < n; i++){
    //   printf("%d\n", dfs_low[i]);
    // }
    // bool cond = true;
    // for(int i = 1; i < adj_list[0].size(); i++){
    //   if (dfs_low[0] == dfs_low[adj_list[0][i]]){
    //     cond = cond && true;
    //   }
    //   else{
    //     cond = false;
    //   }
    // }
    // if (cond)
    //   printf("0\n");
    // else
    printf("%ld\n", ans);
    for(long i = 0; i < n; i++){
      adj_list[i].clear();
    }
    scanf("%ld %ld", &n, &m);
  }
  return 0;
}
