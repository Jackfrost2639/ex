#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair<int, int> pa;
struct qstruct
{
  int dis;
  int des;
  bool eat;

  bool operator<(const qstruct &other) const {
    if(eat != other.eat) return eat > other.eat;
    return dis > other.dis;
  }
};

int n, m, k;
vector <pa> graph[50001];
int hay[50001];
int dp[50001][2];
bool visited[50001][2];

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {  
  setup("dining");
  
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back(pa(c, b));
    graph[b].push_back(pa(c, a));
  }

  for(int i = 1; i <= n; i++) hay[i] = -1;

  for(int i = 0; i < k; i++){
    int idx;
    cin >> idx;
    cin >> hay[idx];
  }

  priority_queue <qstruct> q;
  q.push({
    0,
    n,
    false,
  });

  while(!q.empty()){
    qstruct sh = q.top();
    q.pop();

    if(!visited[sh.des][1] && sh.eat == true){
      visited[sh.des][1] = true;
      dp[sh.des][sh.eat] = sh.dis;
      for(auto e: graph[sh.des]){
        qstruct t;
        t.dis = sh.dis + e.first;
        t.des = e.second;
        t.eat = true;
        q.push(t);
        //cout << t.des << ' ' << sh.dis << '+' << e.first << '=' << t.dis << endl;
      }
    }

    if(!visited[sh.des][0] && sh.eat == false){
      visited[sh.des][0] = true;
      dp[sh.des][sh.eat] = sh.dis;
      for(auto e: graph[sh.des]){
        qstruct t;
        t.dis = sh.dis + e.first;
        t.des = e.second;
        t.eat = false;
        q.push(t);
        //cout << t.des << ' ' << sh.dis << '+' << e.first << '=' << t.dis << endl;
      }

      if(hay[sh.des] != -1){
        q.push({
        sh.dis - hay[sh.des],
        sh.des,
        true,
        });
      }
    }
  }

  // for(int i = 1; i <= n; i++){
  //   cout << dp[i][0] << ' ' << dp[i][1] << endl;
  // }

  for(int i = 1; i < n; i++){
    if(dp[i][1] <= dp[i][0]) cout << 1 << endl;
    else cout << 0 << endl;
  }

  return 0;
}