#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;

int main() {
    cin >> n;
    int w, l;
    for(int i = 0; i < n; i++)
    {
        cin >> w >> l;
        int sq = w * l;
        if(sq%2 == 1)
        {
            cout << sq/2 + 1 << endl;
        }
        else
        {
            cout << sq/2 << endl;
        }
        
    }
    return 0;
}