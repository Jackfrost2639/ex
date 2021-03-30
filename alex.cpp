#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pa;

int n;
pa comp[100001];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        comp[i] = pa(a, b);
    }
    int mx = 0;
    sort(comp, comp+n);

    for(int i = 0; i < n; i++)
    {
        if(comp[i].second < mx)
        {
            cout << "Happy Alex" << endl;
            return 0;
        }
        mx = max(comp[i].second, mx);
    }

    cout << "Poor Alex" << endl;
}