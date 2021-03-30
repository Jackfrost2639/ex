#include <bits/stdc++.h>
using namespace std;
 
long long base[3][3] = {
    1, 0, 1,
    0, 2, 0,
    1, 0, 3};
 
map<tuple<long long, long long, long long>, long long > dp;
 
// sz * sz 사각형의 맨 위에서 y, x까지 연결한 선의 합
long long f(long long sz, long long y, long long x) {
    if (y < 0 || x < 0) return 0;   // 범위를 넘어가면 0
    if (y > x) return f(sz, x, y);  // 사각형의 오른쪽 윗부분만 신경쓰자
    if (sz == 3) return base[y][x]; // 크기가 3보다 작아지면 미리 계산해두기
 
    // dp에 값을 저장해둔다
    if (dp.count({sz, y, x}) != 0) return dp[{sz, y, x}];
    long long &ret = dp[{sz, y, x}];    
 
    // printf("%lld %lld %lld\n", sz, y, x);
 
    long long s = sz/3;
    long long diagonal = x-y;
    if (x < s) ret = f(s, y, x);   // 1
    else if (x < 2*s) {
        if (diagonal < s && y < s) ret = f(s, y-(x-s+1), x-(x-s+1)); // 2
        else if (y < s) ret = 0;    // 3
        else ret = f(s, y-s, x-s) + f(s, y-(x-s+1), x-(x-s+1)); //4
    } else {
        if (y < s) ret = f(s, y, x-2*s);    //5
        else if (y < 2*s && diagonal >= s) ret = f(s, y-(y-s+1), x-(y-s+1)-2*s); //6
        else if (y < 2*s) ret = 2*f(s, y-(x-s+1), x-(x-s+1)); //7
        else ret = f(s, y-2*s, x-2*s) + 2*f(s, y-(x-s+1), x-(x-s+1));
    }
 
    // printf("f(%lld, %lld, %lld) = %lld\n", sz, y, x, ret);
    return ret;
}
 
int main() {
    int Q;
    cin >> Q;
 
    long long pow3 = 1;
    for (int i=1; i<=39; i++)
        pow3 *= 3;
 
    for (long long i=0; i<Q; i++) {
        long long d, a, b;
        cin >> d >> a >> b;
        cout << f(pow3, a+d, b+d) - f(pow3, a-1, b-1)<< "\n";
    }
 
}