#include <bits/stdc++.h>

using namespace std;

int n, m;
int tree[10000001];
int ind = 1;

void upd(int i, int a)
{
    int id = ind + i - 1;
    tree[id] = a;
    bool op = true;

    while(id > 0)
    {
        id /= 2;
        tree[id] = op ? tree[id*2] | tree[id*2+1] : tree[id*2] ^ tree[id*2+1];
        op = !op;
    }
}

int main()
{
    cin >> n >> m;
    ind = ind << n;
    
    for(int i = 0; i < ind; i++)
    {
        int a;
        cin >> a;
        upd(i + 1, a);
    }

    for(int i = 0; i < m; i++)
    {
        int p, b;
        cin >> p >> b;

        upd(p, b);

        cout << tree[1] << endl;
    }
}