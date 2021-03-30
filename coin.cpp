#include <bits/stdc++.h>

using namespace std;

int n, k;
int cv[101];
int ans[101][10001];

int main()
{
    cin >> n >> k;
    for(int i = 1; i < n; i++)
    {
        cin >> cv[i];
    }

    cv[0] = 0;
    for(int j = 1; j < n; j++)
    {
        for(int i = 0; i <= k; i++)
        {
            int r = k/cv[j];
            for(int h = 0; h < r; h++)
            {
                ans[j][i] += ans[j-1][i-(cv[j]*h)];
            }
        }
    }    

    cout << ans[n-1][k] << endl;
}