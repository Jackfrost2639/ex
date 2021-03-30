#include <bits/stdc++.h>

using namespace std;

int n;
int l[2001], r[2001];
int a[2002][2002];
int ans;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> r[i];
    }

    for(int i = 0; i <= n; i++)
    {
        a[i][0] = 0;
    }
    for(int j = 1; j <= n; j++)
    {
        if(l[0] > r[j-1])
        {
            a[0][j] = a[0][j-1] + r[j-1];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(l[i] > r[j-1])
            {
                a[i][j] = max(a[i][j-1] + r[j-1], max(a[i-1][j-1], a[i-1][j]));
            }
            else
            {
                a[i][j] = max(a[i-1][j-1], a[i-1][j]);
            }
            
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, max(a[i][n], a[n][i]));
    }

    cout << ans << endl;
}