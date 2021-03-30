#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pa;

vector <pa> graph[500];
bool visited [500];
int mn[500];

int n, m, ans = 0;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(pa(b,c));
        graph[b].push_back(pa(a,c));
    }

    for(int i = 0; i < 500; i++)
    {
        mn[i] = 0x7fffffff;
    }

    priority_queue<pa, vector<pa>, greater<pa>> pq;

    for(int i = 0; i < graph[1].size(); i++)
    {
        pq.push(pa(graph[1][i].second,graph[1][i].first));
        mn[graph[1][i].first] = graph[1][i].second;
    }
    visited[1] = true;

    while(!pq.empty())
    {
        pa temp = pq.top();
        pq.pop();
        if(visited[temp.second])
            continue;
        visited[temp.second] = true;
        ans += temp.first;
        for(int i = 0; i < graph[temp.second].size(); i++)
        {
            int ver = graph[temp.second][i].first;
            int w = graph[temp.second][i].second; 
            if(mn[ver] > w)
            {
                mn[ver] = w;
                pq.push(pa(w, ver));
            }
        }
    }

    cout << ans << endl;
}