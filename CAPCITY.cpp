#include<bits/stdc++.h>
#include<iostream>
#define M 200001

using namespace std;

vector<vector<long> > g(M), gt(M), scc(M), comp_graph(M);
stack<long> dfs_scc;
set<long> in_stack;
vector<long> vis(M, 0), inci_g(M, 0), inci_gt(M, 0), dfs_num(M, 0), dfs_low(M, 0), inci_comp(M, 0);
int no_scc = 0;
int dfscount = 0;

void tarjanSCC(long u){
  vis[u] = 1;
  dfs_num[u] = dfs_low[u] = ++dfscount;
  dfs_scc.push(u);
  in_stack.insert(u);
  for(long i = 0; i < g[u].size(); i++){
    if (!vis[g[u][i]]){
      tarjanSCC(g[u][i]);
    }
    if (in_stack.find(g[u][i]) != in_stack.end()){
      dfs_low[u] = min(dfs_low[u], dfs_low[g[u][i]]);
    }
  }
  if (dfs_low[u] == dfs_num[u]){
    while(!dfs_scc.empty() && dfs_scc.top() != u){
      scc[no_scc].push_back(dfs_scc.top());
      in_stack.erase(dfs_scc.top());
      dfs_scc.pop();
    }
    scc[no_scc].push_back(dfs_scc.top());
    in_stack.erase(dfs_scc.top());
    dfs_scc.pop();
    no_scc = no_scc + 1;
  }
}

int main(){
  long n, m, u, v, count, it1, it2;
  set<int> capcity;
  set<int> :: iterator s;
  vector<int> lookup(M, 0);
  // map<int, int> :: iterator it1, it2;
  scanf("%ld %ld", &n, &m);
  for(int i = 0; i < n; i++){
    inci_g[i] = inci_gt[i] = 0;
  }
  for(long i = 0; i < m; i++){
    scanf("%ld %ld", &u, &v);
    g[u].push_back(v);
    gt[v].push_back(u);
    inci_g[v] = inci_g[v] + 1;
    inci_gt[u] = inci_gt[u] + 1;
  }
  for(int i = 1; i <= n; i++){
    vis[i] = inci_comp[i] = 0;
  }
  no_scc = dfscount = 0;
  for(int i = 1; i <= n; i++){
    if (vis[i] == 0){
      tarjanSCC(i);
    }
  }
  // printf("SCC:\n");
  for(int i = 0; i < no_scc; i++){
    for(int j = 0; j < scc[i].size(); j++){
      // printf("%ld ", scc[i][j]);
      lookup[scc[i][j]] = i;
    }
    // printf("\n");
  }
  // printf("gt:\n");
  // for(int i = 1; i <= n; i++){
  //   for(int j = 0; j < gt[i].size(); j++){
  //     printf("%ld:%ld\n", i, gt[i][j]);
  //   }
  // }
  // printf("lookup:\n");
  // for(int i = 1; i <= n; i++){
  //   printf("%d:%d\n", i, lookup[i]);
  // }
  count = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < gt[i].size(); j++){
      it1 = lookup[i];
      it2 = lookup[gt[i][j]];
      // printf("%ld %ld\n", it1, it2);
      if (it1 != it2)
        comp_graph[it1].push_back(it2);
    }
  }
  // printf("Component Graph:\n");
  // for(int i = 0; i < no_scc; i++){
  //   printf("%d: ", i);
  //   for(int j = 0; j < comp_graph[i].size(); j++){
  //     printf("%ld ", comp_graph[i][j]);
  //   }
  // }
  for(int i = 0; i < no_scc; i++){
    for(int j = 0; j < comp_graph[i].size(); j++){
      inci_comp[comp_graph[i][j]] = inci_comp[comp_graph[i][j]] + 1;
    }
  }
  // for(int i = 0; i < no_scc; i++){
  //   printf("%ld:%d\n", i, inci_comp[i]);
  // }
  for(int i = 0; i < no_scc; i++){
    if (inci_comp[i] == 0){
      for(int j = 0; j < scc[i].size(); j++){
        // printf("%ld ", scc[i][j]);
        capcity.insert(scc[i][j]);
      }
    }
  }
  printf("%d\n", capcity.size());
  for(s = capcity.begin(); s != capcity.end(); s++){
    printf("%d ", *s);
  }
  printf("\n");
  return 0;
}
