#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
double dp[301][301][301];
bool visited[301][301][301];
int sushc[3];

double dynp(int x, int y, int z)
{
    if(x < 0 || y < 0 || z < 0 || x > n || y > sushc[1]+sushc[2] || z > sushc[2])
    {
        return 0;
    }

    if(visited[x][y][z]) return dp[x][y][z];
    visited[x][y][z] = true;

    double r = (n - x - y - z - 1)/n;
    double a = dynp(x+1, y, z);

    if (a) dp[x][y][z] += (a + 1/(1-r)) * (x+1) / (x+1+y+z);
    r = (n - x - y - z)/n;

    a = dynp(x-1, y+1, z);
    if (a) dp[x][y][z] += (a + 1/(1-r)) * (y+1) / (x+y+z);
    a = dynp(x, y-1, z+1);
    if (a) dp[x][y][z] += (a + 1/(1-r)) * (z+1) / (x+y+z);

    return dp[x][y][z];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        sushc[t-1]++;
    }

    visited[sushc[0]][sushc[1]][sushc[2]] = 1;
    dp[sushc[0]][sushc[1]][sushc[2]] = 1;

    cout << setprecision(9) << dynp(0, 0, 0) - 1 << endl;
    return 0;
}