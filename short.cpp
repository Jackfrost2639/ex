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
        cin >> n >> d >> w;
        a[n].push_back(pa(w, d));
    }

    priority_queue<pa, vector<pa>, greater<pa>> b;

    int cnt = 0;
    b.push(pa(0, k));

    for(int i = 0; i <= v; i++)
    {
        shortest[i] = 0x7fffffff;
    }
    shortest[k] = 0;

    while(cnt != v && !b.empty())
    {
        pa temp = b.top();
        int dist = temp.first;
        int ind = temp.second;
        b.pop();

        if(dist != shortest[ind])
        {
            continue;
        }
        //cout << ind <<' ' << dist << endl;    
        cnt++;

        for(int i = 0; i < a[ind].size(); i++)
        {
            if(shortest[ind] + a[ind][i].first < shortest[a[ind][i].second])
            {   
                //cout <<"       " << shortest[ind] + a[ind][i].first << ' ' << a[ind][i].second << "    " << a[ind][i].first << ' ' << a[ind][i].second <<endl;
                shortest[a[ind][i].second] = shortest[ind] + a[ind][i].first;
                b.push(pa(shortest[a[ind][i].second], a[ind][i].second));
            }
        }
    }

    for(int i = 1; i <= v; i++)
    {
        cout << shortest[i] << endl;
    }

}