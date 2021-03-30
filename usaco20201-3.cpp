#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int arr[6] = {5, 4, 3, 3, 3, 1};

int main() {  
  for(int i = 0; i < 6; i++) cout << arr[i] << endl;
  return 0;
}