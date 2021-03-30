#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

int n, ed;
vector<pa> g[100];
bool visited[100];

bool cmp(pa a, pa b)
{
    return a.second > b.second;
}

int main()
{
    cin >> n >> ed;
    for(int i = 0; i < ed; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(pa(b, c));
        g[b].push_back(pa(a, c));
    }

    priority_queue <pa, vector<pa>, greater<pa>> q;
    q.push(pa(0, 1));

    while(!q.empty())
    {

        int des = q.top().second;
        int dis = q.top().first;
        q.pop();
        if(!visited[des])
        {
            visited[des] = true;
            cout << des << ' ' << dis << endl;
            for(pa e : g[des])
            {
                q.push(pa(e.second + dis, e.first));
            }
        }
    }
}