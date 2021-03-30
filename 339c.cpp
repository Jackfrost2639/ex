#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int ex[11];
int m;
int dp[1001][11][11];
stack <int> s;

int main() {
    for(int i = 1; i <= 10; i++) scanf("%1d", &ex[i]);
    cin >> m;

    dp[0][1][0] = -1;
    dp[0][2][0] = -1;
    
    for(int i = 1; i <= m; i++) {
        for(int y = 0; y <= 10; y++) {
            for(int x = 0; x <= y; x++) {
                for (int a = x+1; a <= 10; a++) {
                    if (ex[a] && a != y && dp[i-1][y][x]) {
                        dp[i][a][a-x] = y;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            if(dp[m][i][j] != 0)
            {
                cout << "YES" << endl;
                int t = m;
                int x = i;
                int y = j;
                s.push(i);
                while(t > 1)
                {
                    s.push(dp[t][x][y]);
                    int x1 = x;
                    x = dp[t][x][y];
                    y = x1-y;
                    t--;
                }
                while(!s.empty())
                {
                    cout << s.top() << ' ';
                    s.pop();
                }
                return 0;
            }         
        }
    }

    // for (int i=1; i<=10; i++) {
    //     for (int j=1; j<=9; j++) {
    //         cout << dp[2][i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "NO" << endl;
    return 0;
}