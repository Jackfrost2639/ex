#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, long long> pa;
typedef pair<long long, pa> desc;

int n;
desc cow[100000];

int main()
{
    ifstream in("convention2.in");
    ofstream out("convention2.out");
    
    in >> n;
    for(int i = 0; i < n; i++)
    {
        long long a, b;
        in >> a >> b;
        cow[i] = desc(a, pa(i, b));
    }

    int ncow = 1;
    sort(cow, cow+n);

    priority_queue <pa> q;
    long long et = cow[0].first + cow[0].second.second;
    long long mx = 0;

    while(ncow < n || q.size() > 0)
    {
        while(ncow < n && cow[ncow].first <= et)
        {
            q.push(pa(cow[ncow].second.first * (-1), ncow));
            ncow++;
        }
        if(q.size() == 0 && ncow < n)
        {
            et = cow[ncow].first + cow[ncow].second.second;
            ncow++;
        }
        else if(q.size() > 0)
        {
            int tind = q.top().second;
            mx = max(mx, et - cow[tind].first);
            et += cow[tind].second.second;
            q.pop();
        }
        
    }

    out << mx << endl;
}