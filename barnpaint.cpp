#include <bits/stdc++.h>
// test
using namespace std;

int n, k;
long long met[100001][3];
bool visited[100001][3];
vector <int> graph[100001];

long long dfs(int i, int c, int p)
{
    if(visited[i][c])
    {
        return met[i][c];
    }
    
    long long s = 1;
    visited[i][c] = true;

    for(int j = 0; j < graph[i].size(); j++)
    {
        if(graph[i][j] == p) continue;

        long long temp = 0;
        for(int h = 0; h < 3; h++)
        {
            if(h != c)
            {
                long long x = dfs(graph[i][j], h, i);
                //printf("%d %d %d\n", graph[i][j], h, x); 
                 temp += x;
            }
        }

        s = s * temp % 1000000007;
    }

    met[i][c] = s;
    return s;
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        b--;
        for(int j = 0; j < 3; j++)
        {
            if(j != b)
            {
                met[a][j] = 0;
                visited[a][j] = true;
            }
        }
    }

    //cout << dfs(1, 0, 0) << ' ' << dfs(1, 1, 0) << ' ' << dfs(1, 2, 0) << endl;

    cout << (dfs(1, 0, 0) + dfs(1, 1, 0) + dfs(1, 2, 0)) % 1000000007 << endl;
}