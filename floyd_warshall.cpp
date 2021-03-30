#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pa;

vector <pa> graph[500];
bool visited [500];
int mn[500][500];

int n, m, ans = 0;

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mn[i][j] = 0x7fffffff;
        }
    }

    for(int i = 0; i < n; i++)
    {
        mn[i][i] = 0;
    }

    for(int  i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mn[a-1][b-1] = min(c, mn[a-1][b-1]);
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mn[i][k] != 0x7fffffff && mn[k][j] != 0x7fffffff && mn[i][j] > mn[i][k] + mn[k][j])
                {
                    mn[i][j] = mn[i][k] + mn[k][j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mn[i][j] == 0x7fffffff)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << mn[i][j] << ' ';
            }
        }
        cout << endl;
    }
}