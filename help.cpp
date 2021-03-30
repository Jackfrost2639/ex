#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pa;

int n;
vector <pa> st;
long long ans[100001];
long long tree[200001];

long long p(int x, int e)
{
    long long res = 1;
    while(e > 0){
        if(e&1) res = (res * x) % 1000000007;
        x = (x * x) % 1000000007;
        e  = e >> 1;
    }
    return res;
}

long long get(int i)
{
    long long s = 0;
    int ind = i;
    while (ind > 0)
    {
        s += tree[ind];
        ind -= (ind & -ind);
    }
    return s;
}

void upd(int i)
{
    int ind = i;
    while(ind <= 2 * n )
    {
        tree[ind]++;    
        ind += (ind & -ind);
    }
}

int main()
{
    ifstream in("help.in");
    ofstream out("help.out");
    
    in >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        in >> a >> b;
        st.push_back(pa(a, b));
    }

    sort(st.begin(), st.end());


    ans[0] = 1;
    upd(st[0].second);
    for(int i = 1 ; i < n ; i++)
    {
        int alpha = get(st[i].first-1);

        ans[i] = (2 * ans[i-1] % 1000000007 + p(2, alpha) % 1000000007 ) % 1000000007;

        upd(st[i].second);
    }

    //for(int i = 0; i<= n-1; i++) cout << ans[i] << endl;
    out << ans[n-1] << endl;



}