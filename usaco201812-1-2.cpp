#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair <int, int> pa;
typedef pair <int, pa> tri;

int n, m, k;
int taste[50005];
vector <pa> tree[50005];
int ans[50005][2];
bool visited[50005][2];

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setup("dining");

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;

      tree[a].push_back(pa(b, c));
      tree[b].push_back(pa(a, c));
  }
  for(int i = 0; i < k; i++){
      int a, b;
      cin >> a >> b;
      taste[a] = b;
  }

  priority_queue <tri, vector<tri>, greater<tri>> q;
  q.push(tri(0, pa(n,0)));

  while(!q.empty()){
      tri t = q.top();
      q.pop();

      int dis = t.first;
      int loc = t.second.first;
      int hay = t.second.second;

      if(visited[loc][hay]) continue;

      visited[loc][hay] = true;
      ans[loc][hay] = dis;

      if(hay){
          for(int i = 0; i < tree[loc].size(); i++){
              if(!visited[tree[loc][i].first][1]){
                  q.push(tri(dis + tree[loc][i].second, pa(tree[loc][i].first, 1)));
              }
          }
      }
      else{
          for(int i = 0; i < tree[loc].size(); i++){
              if(!visited[tree[loc][i].first][0]){
                  q.push(tri(dis + tree[loc][i].second, pa(tree[loc][i].first, 0)));
              }
              if(!visited[tree[loc][i].first][1] && taste[loc] != 0){
                  q.push(tri(dis + tree[loc][i].second - taste[loc], pa(tree[loc][i].first, 1)));
              }
          }
      }
  }

  for(int i = 1; i < n; i++){
      if(ans[i][1] <= ans[i][0]) cout << 1;
      else cout << 0;

      if(i != n-1) cout << endl;
  }

  return 0;
}