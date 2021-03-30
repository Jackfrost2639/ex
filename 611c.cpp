#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int h, w;
char rec[501][501];
int dpr[502][502];
int dpc[502][502];
int dp[502][502];


int main() {
    cin >> h >> w;
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            cin >> rec[i][j];
        }
    }

    for(int i = 1; i <= h; i++)
    {
        int sum = 0;
        for(int j = 1; j <= w; j++)
        {
            sum += rec[i][j] == '.' && rec[i][j+1] == '.';
            dpr[i][j] = dpr[i-1][j] + sum;
        }
    }

    for(int i = 1; i <= w; i++) {
        int sum = 0;
        for(int j = 1; j <= h; j++) {
            sum += rec[j][i] == '.' && rec[j+1][i] == '.';
            dpc[j][i] = dpc[j][i-1] + sum;
        }
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans;
        ans =
            dpr[x2][y2-1] - dpr[x1-1][y2-1] - dpr[x2][y1-1] + dpr[x1-1][y1-1] +
            dpc[x2-1][y2] - dpc[x1-1][y2] - dpc[x2-1][y1-1] + dpc[x1-1][y1-1];
        cout << ans << endl;
    }

    return 0;
}