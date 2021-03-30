#include <bits/stdc++.h>

using namespace std;

int n;
int mf[250001];
int mb[250001];
int of[250001];
int ob[250001];

bool card[100001];
vector <int> mc;

int main()
{
    ifstream in("cardgame.in");
    ofstream out("cardgame.out");
    
    in >> n;
    for(int i = 1; i <= n/2; i++)
    {
        in >> of[i];
        card[of[i]] = true;
    }
    for(int i = (n/2)+1; i <= n; i++)
    {
        in >> ob[i-(n/2)];
        card[ob[i-(n/2)]] = true;
    }

    for(int i = 1; i <= n*2; i++)
    {
        if(card[i] == false)
        {
            mc.push_back(i);
        }
    }
    sort(mc.begin(), mc.end());

    for(int i = 1; i <= n/2; i++)
    {
        mb[i] = mc[i-1];
    }
    for(int i = (n/2)+1; i <= n; i++)
    {
        mf[i-(n/2)] = mc[i-1];
    }

    sort(of+1, of+(n/2)+1);
    sort(ob+1, ob+(n/2)+1);

    int mi = n/2;
    int oi = n/2;
    int cnt = 0;

    for(int i = 1; i <= n/2; i++)
    {
        if(mf[mi] > of[oi])
        {
            mi--;
            oi--;
            cnt++;
        }
        else
        {
            oi--;
        }
    }

    mi = 1;
    oi = 1;

    for(int i = 1; i <= n/2; i++)
    {
        if(mb[mi] < ob[oi])
        {
            mi++;
            oi++;
            cnt++;
        }
        else
        {
            oi++;
        }
    }

    out << cnt << endl;
}