#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

vector <pa> graph[500];
int ans[500];
bool visited [500];

int n, m;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(pa(b, c));
    }

    ans[0] = 0;
    visited[0] = true;

    for(int i=0; i<graph[0].size(); i++)
    {
        ans[graph[0][i].first] = graph[0][i].second;
        visited[graph[0][i].first] = true;
    }
    
    for(int k = 0; k < n; k++)
    {
        for(int e = 1; e < n; e++)
        {
            if(!visited[e])
            {
                continue;
            }
            for(int s = 0; s < graph[e].size(); s++)
            {
                int dest = graph[e][s].first;
                int w = graph[e][s].second;
                
                if(!visited[dest])
                {
                    visited[dest] = true;
                    ans[dest] = ans[e] + w;
                }
                else
                {
                    if(ans[dest] > ans[e] + w)
                    {
                        ans[dest] = ans[e] + w;
                    }
                }
                
            }
        }
    }

    for(int i = 1; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}