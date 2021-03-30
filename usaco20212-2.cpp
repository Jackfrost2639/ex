#include <bits/stdc++.h>
using namespace std;
 
int N, dp[305][305];
vector<int> A;
 
// Solve(a, b) -> a부터 b까지를 칠하는 최소 시간
int Solve(int a, int b) {
    if (a > b) return 0;
    if (a == b) return 1;
 
    int &ret = dp[a][b];
    if (ret != -1) return ret;
 
    ret = 1e9;
   
    // Case2. A[a]의 색을 중간에 재활용 하지 않는 경우
    ret = min(ret, Solve(a+1, b) + 1);
 
    for (int i=a; i<=b; i++) {
        // Case2. A[a]의 색을 중간에 재활용 하는 경우 ex. 1 2 1 3 1 같은 경우에서 가운데 1
        // 시작점을 제외하고 만약 A[a]와 같은 색을 만난다면
        // 1 . . . . 1 . . . . . 이런상황에서
        // a         i
        // i번째 색까지 1로 칠하고 i번째 위치에서 그 색을 재활용해서 이어나갈 수 있음(추가적으로 안칠하고)
        // 그 경우는 a+1, i-1을 칠하는 횟수 + i부터 끝까지 칠하는 횟수
        if (i != a && A[i] == A[a])
            ret = min(ret, Solve(a+1, i-1) + Solve(i, b));
 
    }
    return ret;
}
 
int main() {
    cin >> N;
 
    for (int i=0; i<N; i++) {
        int t;
        cin >> t;
        A.push_back(t);
    }
 
    memset(dp, -1, sizeof(dp));
    cout << Solve(0, A.size()-1);
}