#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
int main() {
    cin >> n;
    int t;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        int test = t/2;
        if(test%2 == 0)
        {
            cout << "YES" << endl;
            for(int j = 1; j <= t/2; j++)
            {
                cout << j * 2 << ' ';
            }
            for(int j = 1; j <= (t-1)/2; j++)
            {
                cout << (j*2) - 1 << ' ';
            }
            cout << t + t/2 - 1 << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
    return 0;
}