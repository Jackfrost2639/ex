#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pa;

int n, m, k;
char maze[500][501];
bool visited[500][500];

void dfs(int x, int y)
{  
    if(x < 0 || y < 0 || x >= n || y >= m) return;
    if(maze[x][y] == '#') return;
    if(visited[x][y]) return;

    visited[x][y] = true;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y-1);
    dfs(x, y+1);

    if (k) {
        maze[x][y] = 'X';
        k--;
    }
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dfs(i, j);
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << maze[i] << endl;
    }
}