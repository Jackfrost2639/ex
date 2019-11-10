#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pa;

bool becmp(pa a, pa b)
{
    return a.second < b.second;
}
bool ecmp(pa a, pa b)
{
    return a.first < b.first;
}

int main()
{
    int n, d;
    pa bessie[100000];
    pa elsie[100000];
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        bessie[i] = pa(a, b);
    }
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        elsie[i] = pa(a, b);
    }
    sort(bessie, bessie+n, becmp);
    sort(elsie, elsie+n, ecmp);

    int queue[200000] = {0,};
    int bot = 0;
    int top = 0;
    int dis[200000] = {0,};

    for(int i = 0; i < n; i++)
    {
        if(bessie[i].second == 0)
        {
            queue[top] = i;
            top++;
            dis[i] = 1;
        }
        else
        {
            break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(elsie[i].first == 0)
        {
            queue[top] = i+n;
            top++;
            dis[i+n] = 1;
        }
        else
        {
            break;
        }
        
    }

    int cnt = 2;

    while(top != bot)
    {
        int tpie = queue[bot++];
        if(tpie >= n)
        {
            int i = 0;
            while(bessie[i].second <= elsie[tpie-n].second)
            {
                if(elsie[tpie-n].second - d > bessie[i].second)
                {
                    i++;
                    continue;
                }
                if(dis[i] == 0)
                {
                    queue[top++] = i;
                    dis[i] = cnt;
                }
                i++;
                if(i>=n)
                {
                    break;
                }
            }
        }
        else
        {
            int i = 0;
            while(bessie[tpie].first >= elsie[i].first)
            {
                if(elsie[i].first < bessie[tpie].first - d)
                {
                    i++;
                    continue;
                }
                if(dis[i+n] == 0)
                {
                    queue[top++] = i+n;
                    dis[i+n] = cnt;
                }
                i++;
                if(i>=n)
                {
                    break;
                }
            }
        }
        cnt++;
    }
    
    for(int i = 0; i < n; i++)
    {
        cout << dis[i] << endl;
    }
}