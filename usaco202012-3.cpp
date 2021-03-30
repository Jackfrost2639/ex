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

int n;
int cow[201][2];
vector <pa> sx;
vector <pa> sy;

int main() {  
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> cow[i][0] >> cow[i][1];
    sx.push_back(pa(cow[i][0], i));
    sy.push_back(pa(cow[i][1], i));
  }

  sort(sx.begin(), sx.end());
  sort(sy.begin(), sy.end());

  for(int i = 0; i < n; i++){
    
  }
  return 0;
}