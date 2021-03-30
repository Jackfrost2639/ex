#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, x, ans;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        int t = 2;
        while(t*2 <= x+1)
        {
            t *= 2;
            if(x%(t-1) == 0)
            {
                cout << x/(t-1) << endl;
                break;
            }
        } 
    }
    return 0;
}