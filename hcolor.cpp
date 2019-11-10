#include <bits/stdc++.h>

using namespace std;

int n;
int h[1000][3];
int hc[1000][3];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> hc[i][0] >> hc[i][1] >> hc[i][2];
    }

    for(int i = 0; i < 3; i++)
    {
        h[0][i] = hc[0][i];
    }
    for(int i = 1; i < n; i++)
    {
        h[i][0] = max(h[i-1][1], h[i-1][2]) + hc[i][0];
        h[i][1] = max(h[i-1][0], h[i-1][2]) + hc[i][1];
        h[i][2] = max(h[i-1][1], h[i-1][0]) + hc[i][2];
    }

    cout << max(max(h[n-1][0], h[n-1][1]), h[n-1][2]) << endl;
}