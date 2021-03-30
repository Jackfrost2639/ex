#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

vector <pa> graph[500];
int ans[500];
bool visited [500];
vector <int> topo;

int n, m;

void dfs(int e)
{
    visited[e] = true;

    for(int i = 0; i < graph[e].size(); i++)
    {
        if(!visited[graph[e][i].first])
        {
            dfs(graph[e][i].first);
        }
    }
    topo.push_back(e);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(pa(b, c));
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    for(int i = 0; i < n; i++)
    {
        ans[i] = 0x7fffffff;
    }

    ans[0] = 0;

    for(int i = 0; i < n; i++)
    {
        int vert = topo[n-i-1];
        for(int j = 0; j < graph[vert].size(); j++)
        {
            if(ans[vert] != 0x7fffffff && ans[graph[vert][j].first] > ans[vert] + graph[vert][j].second)
            {
                ans[graph[vert][j].first] = ans[vert] + graph[vert][j].second;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}