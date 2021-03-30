#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair <int, int> pa;

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int n, m;

int main() {
  cin >> n >> m;
  int a[3][n][m] = {0,};
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < m; k++){
        cin >> a[i][j][k];
      }
    }
  }

  vector <pa> path;
  path.push_back(pa(0, 0));
  int r = 0, c = 0;

  while(r < n-1 && c < m-1){
    vector <int> val;
    int mx = 0;
    for(int i = 0; i < 3; i++){
      val.push_back(a[i][r+1][c]);
      val.push_back(a[i][r][c+1]);

      mx = max(mx, max(a[i][r+1][c], a[i][r][c+1]));
    }

    int cnt = 0;
    int flag = 2;
    for(int i = 0; i < val.size(); i++){
      if(val[i] == mx){
        cnt++;
        flag = i%2;
      }

      if(cnt > 1){
        r++;
        c++;
        flag = 2;
        break;
      }
    }

    if(flag < 2){
      if(flag) c++;
      else r++;
    }

    path.push_back(pa(r, c));
  }

  int sum = 0;
  for(auto e: path){
    sum += min(a[0][e.first][e.second], min(a[1][e.first][e.second], a[2][e.first][e.second]));
  }  

  cout << sum << endl;
  return 0;
}