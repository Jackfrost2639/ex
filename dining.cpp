#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

int n, m, k;
vector<pa> graph[50001];
bool visited[50001];
int ori[50001];
int upd[50001];

void dkstra(int s, int ans[])
{
    for(int i = 0; i <= s; i++)
    {
        ans[i] = 1000000000;
        visited[i] = false;
    }
    priority_queue< pa, vector<pa>, greater<pa> > pq;
    ans[s] = 0;
    pq.push(pa(0, s));

    while(!pq.empty())
    {
        pa temp = pq.top();
        pq.pop();
        int w = temp.first;
        int vert = temp.second;
        if(visited[vert]) continue;

        visited[vert] = true;
        for(int i = 0; i < graph[vert].size(); i++)
        {
            int nw = w + graph[vert][i].second;
            int nv = graph[vert][i].first;
            if(!visited[nv] && ans[nv] > nw)
            {
                ans[nv] = nw;
                pq.push(pa(nw, nv));
            }
        }
    }
}

int main()
{
    ifstream in("dining.in");
    ofstream out("dining.out");
    
    in >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        in >> a >> b >> c;
        graph[a-1].push_back(pa(b-1, c));
        graph[b-1].push_back(pa(a-1, c));
    }

    dkstra(n-1, ori);

    for(int i = 0; i < k; i++)
    {
        int a, b;
        in >> a >> b;
        graph[n].push_back(pa(a-1, ori[a-1]-b));
    }

    dkstra(n, upd);

    for(int i = 0; i < n-1; i++)
    {
        //cout << ori[i] << ' ' << upd[i] << endl;
        if(ori[i] >= upd[i]) out << 1 << endl;
        else out << 0 << endl;
    }
}