#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, long long> pa;

int n, m, t;
vector <pa> graph[10001];
bool vis[10001];
long long par[10001];
long long mdis[10001];
long long cow[10001];

vector <int> tree[10001];
long long num[10001];
bool visited[10001];

long long dfs(int ind)
{
    long long s = cow[ind];
    visited[ind] = true;
    for(int i = 0; i < tree[ind].size(); i++)
    {
        if(!visited[tree[ind][i]])
        {
            s += dfs(tree[ind][i]);
        }
    }

    num[ind] = s;
    return s;
}

int main()
{
    ifstream in("shortcut.in");
    ofstream out("shortcut.out");
    
    in >> n >> m >> t;
    for(int i = 1; i <= n; i++)
    {
        in >> cow[i];
        mdis[i] = 250000000;
        par[i] = -1;
    }
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        in >> a >> b >> c;
        graph[a].push_back(pa(b, c));
        graph[b].push_back(pa(a, c));
    }

    priority_queue <pa, vector<pa>, greater<pa> > pq;

    pq.push(pa(0, 1));
    mdis[1] = 0;
    while(!pq.empty())
    {
        pa temp = pq.top();
        pq.pop();
        long long w = temp.first;
        long long dest = temp.second;
        
        if(vis[dest]) continue;
        vis[dest] = true;

        for(int i = 0; i < graph[dest].size(); i++)
        {
            long long nw = graph[dest][i].second;
            long long nd = graph[dest][i].first;

            if(mdis[nd] > mdis[dest] + nw)
            {
                mdis[nd] = mdis[dest] + nw;
                pq.push(pa(mdis[nd], nd));
                par[nd] = dest;
            }
            else if(mdis[nd] == mdis[dest] + nw)
            {
                if(dest < par[nd])
                {
                    par[nd] = dest;
                }
            }
        }
    }

    for(int i = 2; i <= n; i++)
    {
        tree[par[i]].push_back(i);
    }
    dfs(1);

    long long mx = 0;
    for(int i = 2; i <= n; i++)
    {
        mx = max(mx, (mdis[i] - t) * num[i]);
    }

    out << mx << endl;
}