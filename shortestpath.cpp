#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

int v, e,  k;
vector<pa> a[20001];
////bool visited[20001];
int shortest[20001];

int main()
{
    cin >> v >> e >> k;
    for(int i = 0; i < e; i++)
    {
        int n, w, d;
        cin >> n >> w >> d;
        a[n].push_back(pa(w, d));
    }

    memset(shortest, 0x7fffffff, sizeof shortest);
    shortest[k] = 0;
    priority_queue<pa, vector<pa>, greater<pa>> b;

    b.push(pa(0, k));
    int cnt = 0;

    while(cnt != v && !b.empty())
    {
        pa temp = b.top();
        int dist, to;
        dist = temp.first;
        to = temp.second;        
        b.pop();

        if(shortest[to] != dist)
            continue;
        
        cnt++; //permanent

        for(int i=0; i<a[to].size(); i++)
        {
            if(shortest[a[to][i].second]/*dv*/ > dist + a[to][i].first)
            {
                shortest[a[to][i].second] = dist + a[to][i].first;
                b.push(pa(shortest[a[to][i].second], a[to][i].second));
            }
        }

    }

    



}