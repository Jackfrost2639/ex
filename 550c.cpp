#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

char inp[101];
int seq[101];
int m[126];

int main() {
    cin >> inp;
    int n = strlen(inp);

    for(int i = 0; i < n; i++) seq[i] = inp[i] - '0';

    for(int i = 0; i < 1000; i += 8)
    {
        int tmp = i;
        vector<int> T;

        while (tmp) {
            T.push_back(tmp%10);
            tmp /= 10;
        }

        if(i == 0) T.push_back(0);
        
        int idx=0;
        for (int j=n-1; j>=0; j--) {
            if (idx < T.size() && seq[j] == T[idx]) idx ++;
        }

        if (idx == T.size()) {
            cout << "YES\n";
            cout << i << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}