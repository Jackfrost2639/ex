#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pa;

int n, m, c;
int st[100001];
vector <pa> con[100001];

int t[100001];
int ind = 1;
bool visited[100001];
int tsort(int i)
{
    visited[i] = true;
    for(int x = 0; x< con[i].size(); x++)
    {
        if(!visited[con[i][x].first]) tsort(con[i][x].first);
    }
    t[ind++] = i;
}

int main()
{
    ifstream in("timeline.in");
    ofstream out("timeline.out");
    
    in >> n >> m >> c;
    for(int i = 1; i <= n; i++)
    {
        in >> st[i];
    }
    for(int i = 1; i <= c; i++)
    {
        int x, y, z;
        in >> x >> y >> z;
        con[x].push_back(pa(y, z));
    }

    for(int i = 1 ; i <= n ; i++) {
        if(!visited[i]) tsort(i);
    }

    for(int x = 1; x <= n; x++)
    {

        int i = t[n+1-x];
        for(int j = 0; j < con[i].size(); j++)
        {
            st[con[i][j].first] = max(st[i] + con[i][j].second, st[con[i][j].first] );
        }
    }

    for(int i = 1; i <= n; i++)
    {
        out << st[i] << endl;
    }
}