#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

int h, g;
pa hcow[1001];
pa gcow[1001];
int hf[1001][1001];
int gf[1001][1001];

int fdis(pa i, pa j)
{
    int dx = i.first - j.first;
    int dy = i.second - j.second;;
    return dx*dx + dy*dy;
}

int main()
{
    cin >> h >> g;
    for(int i = 1; i <= h; i++)
    {
        int x, y;
        cin >> x >> y;
        hcow[i] = pa(x, y);
    }
    for(int i = 1; i <= g; i++)
    {
        int x, y;
        cin >> x >> y;
        gcow[i] = pa(x, y);
    }

    hf[0][0] = 100000;
    hf[0][1] = 100000;
    hf[1][0] = 100000;
    gf[0][0] = 100000;
    gf[0][1] = 100000;
    gf[1][0] = 100000;
    hf[1][1] = 100000;

    gf[1][1] = fdis(hcow[1], gcow[1]);

    for(int i = 0; i <= h; i++)
    {
        for(int j = 0; j <= g; j++)
        {
            if(i ==0 || j ==0){
                hf[i][j] = 100000;
                gf[i][j] = 100000;
                continue;
            }

            hf[i][j] = min(hf[i-1][j] + fdis(hcow[i], hcow[i-1]), gf[i-1][j] + fdis(gcow[j], hcow[i]));
            gf[i][j] = min(hf[i][j-1] + fdis(gcow[j], hcow[i]), gf[i][j-1] + fdis(gcow[j-1], gcow[j]));

            if(i == 1 && j == 1) {
                hf[1][1] = 100000;
                gf[1][1] = fdis(hcow[1], gcow[1]);
            } 
            //printf("%d %d : %d %d\n", i, j, hf[i][j], gf[i][j]);
        }
    }

    cout << hf[h][g] << endl;
}