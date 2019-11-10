#include <bits/stdc++.h>

using namespace std;

int s[1001];
int fans[1001];
int bans[1001];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(s[j] < s[i])
            {
                fans[i] = max(fans[i], fans[j]);
            }
        }
        fans[i]++;
    }

    for(int i = n; i >= 1; i--)
    {
        for(int j = n; j > i; j--)
        {
            if(s[j] < s[i])
            {
                bans[i] = max(bans[i], bans[j]);
            }
        }
        bans[i]++;
    }

    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
        mx = max(mx, fans[i] + bans[i]);
    }

    cout << mx-1 << endl;
}