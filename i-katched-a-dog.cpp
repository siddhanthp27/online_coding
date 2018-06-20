#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int max_dist;
int col;

void dfs_for_max_dist(vector<vector<int > > &vii, int u, int dist, int dfs_num[], string s[]){
  // printf("Node = %d \n", u);
  dfs_num[u] = 1;
  // printf("Size = %d\n", vii[u].size());
  for(int i = 0; i < vii[u].size(); i++){
    // printf("dfs_num[vii[u][i]] = %d\n", dfs_num[vii[u][i]]);
    if (dfs_num[vii[u][i]] == 0){
      int r = vii[u][i] / col;
      int c = vii[u][i] % col;
      if (s[r][c] == 'O'){
        // printf("s[c][r] = %c\n", s[r][c]);
        max_dist = max(max_dist, dist+1);
      }
      dfs_for_max_dist(vii, vii[u][i], dist+1, dfs_num, s);
    }
  }
}

void dfs_for_coordinates(vector<vector<int> > &vii, int u, int dist, int dfs_num[], set<pair<int, int> > &coord, string s[]){
  dfs_num[u] = 1;
  int r = u / col;
  int c = u % col;
  if (s[r][c] == 'O' && dist == max_dist){
    coord.insert(make_pair(r, c));
  }
  for(int i = 0; i < vii[u].size(); i++){
    if (dfs_num[vii[u][i]] == 0){
      dfs_for_coordinates(vii,vii[u][i], dist+1, dfs_num, coord,s);
    }
  }
}

int main(){
  int t;
  cin >> t;
  while (t--){
    int r, c;
    cin >> c >> r;
    col = c;
    string s[r];
    for (int i = 0; i< r ; i++){
      cin >> s[i];
    }
    // for(int i = 0; i < r; i++){
    //   cout << s[i] << endl;
    // }
    vector<int> list;
    vector<vector<int> > vii(r*c);
    int dfs_num[r*c];
    vector<set<pair<int,int> > > coords(r*c);
    for (int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        if (s[i][j] == 'M'){
          list.push_back(c*i+j);
        }

        if (j - 1 >= 0){
          if ((s[i][j] == '.' || s[i][j] == 'O' || s[i][j] == 'M') && (s[i][j-1] == '.' || s[i][j-1] == 'O' || s[i][j-1] == 'M')){
            vii[c*i+j].push_back(c*i+j-1);
            vii[c*i+j-1].push_back(c*i+j);
          }
        }
        if (i - 1 >= 0){
          if ((s[i][j] == '.' || s[i][j] == 'O' || s[i][j] == 'M') && (s[i-1][j] == '.' || s[i-1][j] == 'O' || s[i-1][j] == 'M')){
            vii[c*i+j].push_back(c*(i-1)+j);
            vii[c*(i-1)+j].push_back(c*i+j);
          }
        }
      }

    }
    // printf("Graph formed:\n");
    // for(int i = 0; i < r*c; i++){
    //   printf("Adjacency list of vertex %d: ", i);
    //   for (int j = 0; j < vii[i].size(); j++){
    //     printf("%d ", vii[i][j]);
    //   }
    //   printf("\n");
    // }

    max_dist = 0;
    for(int i = 0; i < list.size(); i++){
      for(int k = 0; k < r*c; k++){
        dfs_num[k] = 0;
      }

      dfs_for_max_dist(vii, list[i], 0, dfs_num, s);

    }

    printf("Max Distance : %d.\n", max_dist);

    for(int i = 0; i < list.size(); i++){
      for(int k = 0; k < r*c; k++){
        dfs_num[k] = 0;
      }

      dfs_for_coordinates(vii, list[i], 0, dfs_num, coords[list[i]], s);

    }

    // printf("Coordinates obtained: \n");

    int ox = 100, oy = 100, mx = 100, my = 100;
    set<pair<int, int> > :: iterator it;
    for(int i = 0; i < list.size(); i++){
      // printf("%d: ", list[i]);

      for(it = coords[list[i]].begin(); it!= coords[list[i]].end(); it++){
        if (oy > it->second){
          oy = it->second;
          ox = it->first;
          mx = list[i] / col;
          my = list[i] % col;
        }
        else if (ox > it->first){
          oy = it->second;
          ox = it->first;
          mx = list[i] / col;
          my = list[i] % col;
        }
        else if (my > (list[i] % col)){
          oy = it->second;
          ox = it->first;
          mx = list[i] / col;
          my = list[i] % col;
        }
        else if (mx > (list[i] / col)){
          oy = it->second;
          ox = it->first;
          mx = list[i] / col;
          my = list[i] % col;
        }
      }

      // printf("\n");
    }

    printf("Co-ordinates of Ozil : %d %d.\n", ox+1, oy+1);
    printf("Co-ordinates of Minion : %d %d.\n", mx+1, my+1);
  }
  return 0;
}
