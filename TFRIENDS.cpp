#include<bits/stdc++.h>
#include<iostream>
#define M 1000001

using namespace std;

vector<vector<int> > adj_list(M);
vector<int> dfs_num(M, 0), dfs_low(M, 0), vis(M, 0);
stack<int> dfs_scc;
set<int> in_stack;
int dfscomp;
int groups = 0;

void scc(int u){
  vis[u] = 1;
  dfs_low[u] = dfs_num[u] = ++dfscomp;
  dfs_scc.push(u);
  in_stack.insert(u);
  for(int i = 0; i < adj_list[u].size(); i++){
    if (!vis[adj_list[u][i]]){
      scc(adj_list[u][i]);
    }
    if (in_stack.find(adj_list[u][i]) != in_stack.end()){
      dfs_low[u] = min(dfs_low[u], dfs_low[adj_list[u][i]]);
    }
  }
  if (dfs_low[u] == dfs_num[u]){
    ++groups;
    while(!dfs_scc.empty() && dfs_scc.top() != u){
      in_stack.erase(dfs_scc.top());
      dfs_scc.pop();
    }
    in_stack.erase(dfs_scc.top());
    dfs_scc.pop();
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    groups = 0;
    scanf("%d", &n);
    string s[n];
    for(int i = 0; i < n; i++){
      // scanf("%s", s[i]);
      cin >> s[i];
    }
    // for(int i = 0; i < n; i++){
    //   // printf("%s\n", s[i]);
    //   cout << s[i] << endl;
    // }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if (s[i][j] == 'Y'){
          adj_list[j].push_back(i);
        }
      }
    }
    for(int i = 0; i < n; i++){
      dfs_num[i] = dfs_low[i] = vis[i] = 0;
    }
    for(int i = 0; i < n; i++){
      if (vis[i] == 0){
        scc(i);
      }
    }
    printf("%d\n", groups);
    for(int i = 0; i < n;i++){
      adj_list[i].clear();
    }
  }
  return 0;
}
