#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

char a[3001];
char b[3001];
int dp[3001][3001];
int dir[3001][3001];
char add[3001][3001];
stack <char> ans;


int main() {
    cin >> a >> b;
    int alen = strlen(a);
    int blen = strlen(b);
    for(int i = 1; i <= alen; i++)
    {
        for(int j = 1; j <= blen; j++)
        {
            int x = dp[i-1][j-1];
            int y = dp[i-1][j];
            int z = dp[i][j-1];
            if(a[i-1] == b[j-1]) x++;

            dp[i][j] = max({x, y, z});
            if(dp[i][j] == x)
            {
                dir[i][j] = 1;
                if(a[i-1] == b[j-1])
                {
                    add[i][j] = a[i-1];
                }
            }
            else if(dp[i][j] == y)
            {
                dir[i][j] = 2;
            }
            else if(dp[i][j] == z)
            {
                dir[i][j] = 3;
            }
        }
    }

    int dx = alen;
    int dy = blen;
    while(dx > 0 && dy > 0)
    {
        if(add[dx][dy] != 0)
        {
            ans.push(add[dx][dy]);
        }
        if(dir[dx][dy] == 1)
        {
            dx--;
            dy--;
        }
        else if(dir[dx][dy] == 2)
        {
            dx--;
        }
        else if(dir[dx][dy] == 3)
        {
            dy--;
        }
    }

    while(!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
    return 0;
}