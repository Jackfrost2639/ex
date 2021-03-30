#include <bits/stdc++.h>

using namespace std;

long n, m, k, t;
vector <long> waste;

int main()
{
    cin >> n >> m >> k >> t;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> y >> x;
        x--;
        y--;
        waste.push_back(y*m + x);
    }

    sort(waste.begin(), waste.end());

    for(int i = 0; i < t; i++)
    {
        int x, y;
        cin >> y >> x;
        x--;
        y--;

        long tempi = lower_bound(waste.begin(), waste.end(), y*m + x) - waste.begin();
        long temp = waste[tempi];
        long cmp = y*m + x - tempi;

        if(temp == y*m + x) cout << "Waste" << endl;
        else if(cmp % 3 == 0) cout << "Carrots" << endl;
        else if(cmp % 3 == 1) cout << "Kiwis" << endl;
        else if(cmp % 3 == 2) cout << "Grapes" << endl;
    }
}