#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair<int, int> pa;
typedef long long ll;
struct node{
    int idx;
    int ve;
    int he;
};

int a, b, n, m;
vector <int> v;
vector <int> h;
priority_queue <pa, vector<pa>, greater<pa>> q;
node graph[2001*2001];
bool visited[2001*2001];
ll sum = 0;

void add(int p, int dx, int dy) {
    int x = p % (n+1);
    int y = p / (n+1);
    x += dx;
    y += dy;
    if (x < 0 || x > n) return;
    if (y < 0 || y > m) return;
    if (dx) q.push({graph[p].he, y * (n+1) + x});
    if (dy) q.push({graph[p].ve, y * (n+1) + x});
}

int main() {
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    cin >> a >> b >> n >> m;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        h.push_back(t);
    }
    v.push_back(0);
    h.push_back(0);
    v.push_back(a);
    h.push_back(b);
    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    int ncnt = (n+1)*(m+1);
    int ind = 0;

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            graph[ind].idx = ind;
            graph[ind].ve = v[j+1] - v[j];
            graph[ind].he = h[i+1] - h[i];
            ind++;
        }
    }

    q.push(pa(0, 0));
    
    while(!q.empty()){
        pa t = q.top();
        q.pop();
        int c = t.second;
        if(visited[c]) continue;
        // cout << imie(t.first) imie(t.second) << endl;
        visited[c] = true;
        sum += t.first;
        add(c, 1, 0);
        add(c, -1, 0);
        add(c, 0, 1);
        add(c, 0, -1);
    }
    cout << sum << endl;
    return 0;
}