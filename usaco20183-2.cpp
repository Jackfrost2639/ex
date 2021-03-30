#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, m;
bool flag;
vector <int> ans;
vector <int> order[100005];
bool visited[100005];
bool path[100005];


// true if cycle : false if not
bool dfs(int x, vector <int> tree[]) {
  visited[x] = true;
  path[x] = true;
  for (auto e : tree[x]) {
    if (path[e]) return true;
    if (visited[e]) continue;
    if (dfs(e, tree)) return true;
  }
  path[x] = false;
  return false;
}

int b_search() {
  int s = 0;
  int e = m;
  int best = 0;
  while (s < e) {
    int mi = (s+e)/2;

    for (int i=1; i<=n; i++) {
      visited[i] = 0;
      path[i] = 0;
    }
    vector <int> tree[100005];
    for(int i = 0; i <= mi; i++){
      int len = order[i].size();
      for(int j = 0; j < len-1; j++){
        tree[order[i][j]].push_back(order[i][j+1]);
      }
    }

    bool ans = false;
    
    for (int i=1; i<=n; i++) {
      if (!visited[i]) {
        ans = ans || dfs(i, tree);
      }
    }

    if(ans == false){
      s = mi + 1;
      best = max(best, mi);
    }
    else{
      e = mi;
    }
  }
  return best;
}

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {  
  setup("milkorder");
  
  cin >> n >> m;
  for (int i=0; i<m; i++) {
    int x;
    cin >> x;
    for (int j=0; j<x; j++) {
      int v;
      cin >> v;
      order[i].push_back(v);
    }
  }

  int good_n = b_search();

  vector <int> tree[100005];
  int degree[100005];

  for(int i = 0; i <= good_n; i++){
    int len = order[i].size();
    for(int j = 0; j < len-1; j++){
      tree[order[i][j]].push_back(order[i][j+1]);
      degree[order[i][j+1]]++;
    }
  }

  priority_queue <int> q;
  for(int i = 1; i <= n; i++){
    if(degree[i] == 0) q.push(-i);
  }

  while(!q.empty()){
    int t = -q.top();
    q.pop();
    ans.push_back(t);

    for(auto e: tree[t]){
      degree[e]--;
      if(degree[e] == 0) q.push(-e);
    }
  }

  for(int i = 0; i < ans.size(); i++){
    cout << ans[i];
    if(i != ans.size()-1) cout << ' ';
  }
  cout << endl;
  return 0;
}