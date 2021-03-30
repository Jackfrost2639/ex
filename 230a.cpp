#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair<int, int> pa;

int n, s;
pa drag[1000];

int main() {
    cin >> s >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        drag[i] = pa(a, b);
    }

    sort(drag, drag + n);

    for(int i = 0; i < n; i++)
    {
        if(drag[i].first < s)
        {
            s += drag[i].second;
            continue;
        }
        if(drag[i].first >= s)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}