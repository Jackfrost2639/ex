#include <bits/stdc++.h>

using namespace std;

vector<int> graph[100001];
int ccoord[100001][2] = {0,};
bool visited[100001] = {0,};
int n, m;
int minx, miny, maxx, maxy;

void dfs(int start)
{
    visited[start] = true;

 
    if(ccoord[start][0] < minx)
    {
        minx = ccoord[start][0];
    }
    if(ccoord[start][0] > maxx)
    {
        maxx = ccoord[start][0];
    }
    if(ccoord[start][1] < miny)
    {
        miny = ccoord[start][1];
    }
    if(ccoord[start][1] > maxy)
    {
        maxy = ccoord[start][1];
    }

    for(int i = 0; i < graph[start].size(); i++)
    {
        if(!visited[graph[start][i]])
        {
            dfs(graph[start][i]);
        }
    }
}

int main()
{
    ifstream in("fenceplan.in");
    ofstream out("fenceplan.out");

    in >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        in >> ccoord[i][0] >> ccoord[i][1];
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        in >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int pmin = 0x7fffffff;

    for(int i = 1; i <= n; i++)
    {
        minx = 0x7fffffff;
        maxx = 0;
        miny = 0x7fffffff;
        maxy = 0;

        if(visited[i])
        {
            continue;
        }

        dfs(i);

        int per = 2*(maxx - minx + maxy - miny);

        if(per < pmin)
        {
            pmin = per;
        }
    }

    out << pmin << endl;
}