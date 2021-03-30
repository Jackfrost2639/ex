#include <iostream>

using namespace std;

int n;
int rob[100001];
int bio[100001];
long long scnt = 0;
long long rcnt = 0;
long long bcnt = 0;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> rob[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> bio[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(rob[i] == 1 && bio[i] == 0) rcnt++;
        if(rob[i] == 0 && bio[i] == 1) bcnt++;
        if(rob[i] == bio[i]) scnt++;
    }

    if(scnt == n)
    {
        cout << -1 << endl;
    }
    else if(rcnt == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (bcnt/rcnt) + 1 << endl;
    }
    
}