#include <bits/stdc++.h>

using namespace std;

typedef struct sx
{
    int x1;
    int y1;
    int d1;
    int x2;
    int y2;
    int d2;
} sx;

int n;
int f[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans[21][21][4][21][21][4];

sx tr(sx a)
{
    sx r;
    r.x1 = a.x1;
    r.y1 = a.y1;
    r.d1 = (a.d1+1)%4;
    r.x2 = a.x2;
    r.y2 = a.y2;
    r.d2 = (a.d2+1)%4;
    return r;
}

sx tl(sx a)
{
    sx r;
    r.x1 = a.x1;
    r.y1 = a.y1;
    r.d1 = (a.d1+3)%4;
    r.x2 = a.x2;
    r.y2 = a.y2;
    r.d2 = (a.d2+3)%4;
    return r;
}

sx fw(sx a)
{
    sx r;
    
    r.x1 = a.x1 + dx[a.d1];
    r.y1 = a.y1 + dy[a.d1];
    r.d1 = a.d1;

    if(r.x1 <= 0 || r.x1 > n || r.y1 <=0 || r.y1 > n || f[r.x1][r.y1] == 1 || (a.x1 == 1 && a.y1 == n))
    {
        r.x1 = a.x1; r.y1 = a.y1;
    }

    r.x2 = a.x2 + dx[a.d2];
    r.y2 = a.y2 + dy[a.d2];
    r.d2 = a.d2;

    if(r.x2 <= 0 || r.x2 > n || r.y2 <=0 || r.y2 > n || f[r.x2][r.y2] == 1 || (a.x2 == 1 && a.y2 == n))
    {
        r.x2 = a.x2; r.y2 = a.y2;
    }

    return r;
}

int main()
{
    ifstream in("cownav.in");
    ofstream out("cownav.out");
    
    in >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char a;
            in >> a;
            if(a == 'E') f[i][j] = 0;
            else f[i][j] = 1;
        }
    }

    queue <sx> q;
    sx t;
    t.x1 = n;
    t.y1 = 1;
    t.d1 = 1;
    t.x2 = n;
    t.y2 = 1;
    t.d2 = 0;
    q.push(t);

    while(!q.empty())
    {
        sx temp = q.front();
        q.pop();

        printf("%d %d %d, %d %d %d\n", temp.x1, temp.y1, temp.d1, temp.x2, temp.y2, temp.d2);

        if(temp.x1 == 1 && temp.y1 == n && temp.x2 == 1 && temp.y2 == n)
        {
            out << ans[temp.x1][temp.y1][temp.d1][temp.x2][temp.y2][temp.d2] << endl;
            break;
        }

        sx r = tr(temp);
        sx l = tl(temp);
        sx fow = fw(temp);

        if(ans[r.x1][r.y1][r.d1][r.x2][r.y2][r.d2] == 0)
        {
            q.push(r);
            ans[r.x1][r.y1][r.d1][r.x2][r.y2][r.d2] = ans[temp.x1][temp.y1][temp.d1][temp.x2][temp.y2][temp.d2] + 1;
        }
        if(ans[l.x1][l.y1][l.d1][l.x2][l.y2][l.d2] == 0)
        {
            q.push(l);
            ans[l.x1][l.y1][l.d1][l.x2][l.y2][l.d2] = ans[temp.x1][temp.y1][temp.d1][temp.x2][temp.y2][temp.d2] + 1;
        }
        if(ans[fow.x1][fow.y1][fow.d1][fow.x2][fow.y2][fow.d2] == 0)
        {
            q.push(fow);
            ans[fow.x1][fow.y1][fow.d1][fow.x2][fow.y2][fow.d2] = ans[temp.x1][temp.y1][temp.d1][temp.x2][temp.y2][temp.d2] + 1;
        }
    }
}