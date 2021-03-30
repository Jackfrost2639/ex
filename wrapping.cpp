#include <bits/stdc++.h>

using namespace std;

int n, k;
int ans[10001];
int prod[10001];

int main()
{
    ifstream  in("teamwork.in");
    ofstream out("teamwork.out");

    in >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        in >> prod[i];
    }

    ans[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        int m = prod[i];
        for(int j = 1; j <= k; j++)
        {
            if(i - j < 0) break;

            m = max(m, prod[i-j+1]);

            ans[i] = max(ans[i], ans[i-j] + m * j);
        }
    }

    out << ans[n] << endl;
}