#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;
typedef pair<int, pa> tri;

int n, t;
int field[100][100];
int dx[12] = {-3, -2, -1, 0, 1, 2, 3, 2, 1, 0, -1, -2};
int dy[12] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1};
int ans[100][100];

int main()
{
    cin >> n >> t;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> field[i][j];
            ans[i][j] = 100000001;
        }
    }

    priority_queue <tri, vector<tri>, greater<tri>> pq;
    pq.push(tri(0, pa(0, 0)));

    while(!pq.empty())
    {
        tri a = pq.top();
        pq.pop();

        int d = a.first;
        int x = a.second.first;
        int y = a.second.second;

        if(d > ans[x][y]) continue;

        if(x == n-1 && y == n-1) break;

        if((2*n-2-x-y)<= 2)
        {
            int nd = (2*n-2-x-y) * t;
            if(ans[n-1][n-1] > nd)
            {
                ans[n-1][n-1] = nd;
                pq.push(tri(nd, pa(n-1, n-1)));
            }
        }

        for(int i = 0; i < 12; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            int nd = d + 3*t + field[nx][ny];

            if(ans[nx][ny] > nd)
            {
                ans[nx][ny] = nd;
                pq.push(tri(nd, pa(nx, ny)));
            }
        }
    }
}