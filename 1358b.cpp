#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, m;
int gran[100001];
bool flag = true;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        for(int j = 1; j <= m; j++)
        {
            cin >> gran[j];
        }
        sort(gran+1, gran + m+1);

        for(int j = m; j >= 0; j--)
        {
            if(j >= gran[j])
            {
                cout << j+1 << endl;
                break;
            }
        }
    }
    return 0;
}