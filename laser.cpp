#include <bits/stdc++.h>

using namespace std;

int n;
int coord[100002][2]; //x, y
bool visited[100002];
int d[100002];
map <int, vector<int>> mx;
map <int, vector<int>> my;

int main()
{
    cin >> n;
   
    int tx, ty;
    cin >> tx >> ty;
    coord[0][0] = tx;
    coord[0][1] = ty;
    cin >> tx >> ty;
    coord[n+1][0] = tx;
    coord[n+1][1] = ty;
    mx[tx].push_back(n+1);
    my[ty].push_back(n+1);

    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        coord[i][0] = x;
        coord[i][1] = y;
        mx[x].push_back(i);
        my[y].push_back(i);
    }
    
    queue <int> q;
    q.push(0);
    visited[0] = true;
    
    while(!q.empty())
    {
        int mir = q.front();
        int cx = coord[mir][0];
        int cy = coord[mir][1];
        q.pop();
        
        for(int i = 0; i < mx[cx].size(); i++)
        {
            if(mx[cx][i] != mir && !visited[mx[cx][i]])
            {
                q.push(mx[cx][i]);
                visited[mx[cx][i]] = true;
                d[mx[cx][i]] = d[mir] + 1;
            } 
        }
        for(int i = 0; i < my[cy].size(); i++)
        {
            if(my[cy][i] != mir && !visited[my[cy][i]])
            {
                q.push(my[cy][i]);
                visited[my[cy][i]] = true;
                d[my[cy][i]] = d[mir] + 1;
            } 
        }
    }

    cout << d[n+1]-1 << endl;
}