#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair <int, int> pa;

struct qstruct{
  int x;
  int y;
  int r;
};

int n, d;
int fld[1001][1001];
int ans[1001][1001];
int xdir[4] = {1, -1, -1, 1};
int ydir[4] = {1, 1, -1, -1};
int visited[1001][1001];
vector <pa> s;

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {  
  cin >> n >> d;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      visited[i][j] = -1;
      
      char t;
      cin >> t;
      
      if(t == '#'){
        ans[i][j] = 0;
        fld[i][j] = 0;
      }
      
      else if(t == '.') fld[i][j] = 1;
      
      else if(t == 'S'){
        fld[i][j] = 1;
        s.push_back(pa(i, j));
      }
    }
  }

  queue <qstruct> q;

  for(auto e: s){
    qstruct t;
    t.x = e.first;
    t.y = e.second;
    t.r = 0;
    q.push(t);
  }

  while(!q.empty()){
    qstruct a = q.front();
    q.pop();

    if(visited[a.x][a.y] >= a.r) continue;
    visited[a.x][a.y] = a.r;

    bool flag = false;
    for(int i = 0; i <= a.r; i++){
      int px = a.x + a.r;
      int nx = a.x - a.r;

      if((px-i) >= 0 && !fld[px-i][a.y+i]) flag = true;
      if((px-i) >= 0 && (a.y-i) >= 0 && !fld[px-i][a.y-i]) flag = true;
      if((nx-i) >= 0 && !fld[nx-i][a.y+i]) flag = true;
      if((nx-i) >= 0 && (a.y-i) >= 0 && !fld[nx-i][a.y-i]) flag = true;

      if(flag) break;
      cout << "xandy" << px-i << " " << nx-i << " " << a.y+i << " " << a.r << endl;
    }

    if(flag) continue;

    else{
      ans[a.x][a.y] = 1;
      for(int i = 0; i < a.r; i++){
        int px = a.x + a.r;
        int nx = a.x - a.r;

        if((px-i) >= 0 && !fld[px-i][a.y+i]) ans[px-i][a.y+i] = 1;
        if((px-i) >= 0 && (a.y-i) >= 0 && !fld[px-i][a.y-i]) ans[px-i][a.y-i] = 1;
        if((nx-i) >= 0 && !fld[nx-i][a.y+i]) ans[nx-i][a.y+i] = 1;
        if((nx-i) >= 0 && (a.y-i) >= 0 && !fld[nx-i][a.y-i]) ans[nx-i][a.y-i] = 1;
      }
    }

    for(int i = 0; i <= d; i++){
      for(int j = 0; j <= d-i; j++){
        if(i == 0 && j == 0){
          continue;
        }
        
        for(int k = 0; k < 4; k++){
          qstruct t;
          t.x = a.x + (i * xdir[k]);
          t.y = a.y + (j * ydir[k]);
          t.r = a.r;

          cout << "rem " << t.x << ' ' << t.y << ' ' << t.r << endl;

          if(t.x >= 0 && t.y >= 0 && fld[t.x][t.y] && visited[t.x][t.y] < t.r) {
            q.push(t);
            cout << "add queue " << t.x << ' ' << t.y << ' ' << t.r << endl;
          }
        }
      }
    }

    for(int i = 0; i <= d; i++){
      for(int j = 0; j < 2; j++){
        qstruct t;
        t.x = a.x + (i * xdir[j]);
        t.y = a.y + ((d-i) * ydir[j]);
        t.r = a.r + 1;

        cout << "inc "<< t.x << ' ' << t.y << ' ' << t.r << endl;

        if(t.x >= 0 && t.y >= 0 && fld[t.x][t.y] && visited[t.x][t.y] < t.r) q.push(t);
      }
    }
  }

  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(ans[i][j] == 1) cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}