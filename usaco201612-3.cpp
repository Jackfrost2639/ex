#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
int x[100005];
int y[100005];
bool visited[100005];
int ans[100005];
map <int, vector<int>> xc;
map <int, vector<int>> yc;

void setup(string s){
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setup("lasers");
  cin >> n;
  cin >> x[0] >> y[0] >> x[n+1] >> y[n+1];
  
  xc[x[0]].push_back(0);
  yc[y[0]].push_back(0);
  xc[x[n+1]].push_back(n+1);
  yc[y[n+1]].push_back(n+1);

  for(int i = 1; i <= n; i++){
    cin >> x[i] >> y[i];
    xc[x[i]].push_back(i);
    yc[y[i]].push_back(i);
  } 

  queue <int> q;
  q.push(0);
  int cnt = 0;
  while(!q.empty()){
    int t = q.front();
    q.pop();
    visited[t] = true;;
    

    for(int e: xc[x[t]]){
      if(!visited[e]){
        ans[e] = ans[t] + 1;
        q.push(e);
        visited[e] = true;
      }
    }
    xc[x[t]] = {};

    for(int e: yc[y[t]]){
      if(!visited[e]){
        ans[e] = ans[t] + 1;
        q.push(e);
        visited[e] = true;
      }
    }
    yc[y[t]] = {};
  }

  //for(int i = 0; i <= n+1; i++) cout << ans[i] << ' ';
  //cout << endl;

  cout << ans[n+1]-1 << endl;
  return 0;
}