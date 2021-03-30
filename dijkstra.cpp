#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pa;

vector <pa> graph[500];
bool visited [500];
int mn[500];

int n, m, s, ans = 0;

int main()
{
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1].push_back(pa(b-1,c));
    }

    priority_queue <pa, vector<pa>, greater<pa>> pq;

    for(int i = 0; i < n; i++)
    {
        mn[i] = 0x7fffffff;
    }

    pq.push(pa(0,0));

    while(!pq.empty())
    {
        pa temp = pq.top();
        pq.pop();
        int w = temp.first, vert = temp.second;

        if(!visited[vert])
        {
            visited[vert] = true;
            mn[vert] = w;
        }
        else
        {
            continue;
        }
        
        for(int i = 0; i < graph[vert].size(); i++)
        {
            int nw = w + graph[vert][i].second;
            int nv = graph[vert][i].first;

            if(mn[nv] == 0x7fffffff || mn[vert] > nw)
            {
                mn[nv] = nw;
                pq.push(pa(nw, nv));
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << mn[i] << endl;
    }
}