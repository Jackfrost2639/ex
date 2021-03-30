#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

int n, m, x;
vector <pa> leti[26];
vector <pa> shift;
vector <int> dis[26];

int main()
{
    cin >> n >> m >> x;
    int d = x * x;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char t;
            cin >> t;

            if(t == 'S') shift.push_back(pa(i, j));
            else leti[t-'a'].push_back(pa(i, j));
        }
    }

    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < leti[i].size(); j++)
        {
            int mn = 0x7fffffff;
            for(int k = 0; k < shift.size(); k++)
            {
                int dx = shift[k].first - leti[i][j].first;
                int dy = shift[k].second - leti[i][j].second;

                mn = min(mn, dx*dx + dy*dy);
            }
            dis[i].push_back(mn);
        }
    }

    int q;
    cin >> q;
    int cnt = 0;
    for(int i = 0; i < q; i++)
    {
        char t;
        cin >> t;

        if(((t-'a') >= 0) && leti[t - 'a'].empty())
        {
            cout << -1 << endl;
            return 0;
        }
        if(((t-'a') < 0) && leti[t - 'A'].empty())
        {
            cout << -1 << endl;
            return 0;
        }
        if(((t-'a') < 0) && shift.empty())
        {
            cout << -1 << endl;
            return 0;
        }
        if((t-'a') < 0)
        {
            int flag = true;
            for(int j = 0; j < leti[t-'A'].size(); j++)
            {
                if(dis[t-'A'][j] <= d)
                {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
            else flag = true;
        }
    }

    cout << cnt << endl;
}