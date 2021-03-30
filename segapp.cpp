#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

int n;
pa coord[10001];
pa order[10001];
int y_order[10001];
int tree[10001];
int ind = 1;
int ans[10001];

void upd(int i)
{
    int id = ind + i - 1;

    while(id > 0)
    {
        tree[id] ++;
        id /= 2;
    }
}

int sm(int s, int f)
{
    int sum = 0;
    int st = s + ind - 1;
    int fi = f + ind - 1;

    while(st < fi)
    {
        if(st%2 == 1)
        {
            sum += tree[st];
            st++;
        }
        if(fi%2 == 0)
        {
            sum += tree[fi];
            fi--;
        }

        st /= 2;
        fi /= 2;        
    }

    if(st == fi)
    {
        sum += tree[st];
    }

    return sum;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        coord[i] = pa(y, i); 
        order[i] = pa(x, i);
    }

    while(ind < n) ind *= 2;

    sort(coord, coord + n);
    sort(order, order + n);
    
    for(int i=0; i < n; i++) {
        y_order[coord[i].second] = i;
    }

    for(int i = 0; i < n; i++)
    {
        int id = order[i].second;
        upd(ind + y_order[id]);
        ans[id] = sm(ind, y_order[id]) - 1;
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}