#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair <int, int> pa;

int n;
pa exam[5001];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> exam[i].first >> exam[i].second;
    }

    sort(exam, exam + n);

    int t = 0;
    for(int i = 0; i < n; i++)
    {
        if(exam[i].second >= t)
        {
            t = exam[i].second;
        }
        else
        {
            t = exam[i].first;
        }
    }

    cout << t << endl;

    return 0;
}