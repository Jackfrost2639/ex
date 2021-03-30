#include <bits/stdc++.h>

using namespace std;

int n, m;
int spicy[100000];
int flav[100000];
int s, e;
map <int, int> bst;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> flav[i] >> spicy[i];
    }

    int mspicy = 1000000001;
    int sum = 0;
    s = 0;
    e = 0;
    for(int i = 0; i < n; i++)
    {
        if(e == n && sum < m) break;
        
        while(sum < m)
        {
            sum += flav[e];
            bst[e] = spicy[e];
            e++;
        }
        auto pr = max_element(
        begin(bst), end(bst), [] (const pair<int, int>  & p1, const pair<int, int> & p2) {
        return p1.second < p2.second;});

        mspicy = min(mspicy, pr->second);
        //cout << bst.size() << endl;

        bst.erase(i);
        sum -= flav[i];
    }

    cout << mspicy << endl;
}