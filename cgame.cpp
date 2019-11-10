#include <bits/stdc++.h>

using namespace std;

int n;
int a[2001];
int b[2001];
int ans[2001][2001];

int calc(int i, int j)
{
    if(i==0 || j == 0)
    {
        return 0;
    }

    int score = max(calc(i-1, j), calc(i-1, j-1));
    
    if(a[i] > b[j])
    {
        score = max(score, calc(i, j-1) + b[j]);
    }

    return score;
}

int main()
{
    cin >> n;
    for(int i = n; i > 0; i--)
    {
        cin >> a[i];
    }
    for(int i = n; i > 0; i--)
    {
        cin >> b[i];
    }

    for(int i = 0; i <= n; i++)
    {
        ans[0][i] = 0;
        ans[i][0] = 0;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int score = max(ans[i-1][j], ans[i=1][j-1]);
            if(a[i] > b[j])
            {
                score = max(score, ans[i][j-1]+b[j]);
            }
            ans[i][j] = score;
        }
    }

    cout << ans[n][n] << endl;
}