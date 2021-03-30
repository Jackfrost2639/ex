#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pa;

const int NUM = 110;
const int MOD = 1000000007;
const int INF = 1000000000;

void setup(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int n, k;
vector <int> cbreed[51];
int cow[50005];
vector <int> rel[51];
int dist[50005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> cow[i];
        cbreed[cow[i]].push_back(i);
    }
    for(int i = 1; i <= k; i++){
        string t;
        cin >> t;
        for(int j = 1; j <= k; j++){
            if(t[j-1] == '1') rel[i].push_back(j);
        }
    }
    memset(dist, 0x7F, sizeof(dist));
    priority_queue <pa, vector<pa>, greater<pa>> q;
    q.push(pa(0, 1));
    dist[1] = 0;

    while(!q.empty()){
        pa t = q.top();
        q.pop();
        int breed = cow[t.second];

        if(t.second == n){
            cout << t.first << endl;
            return 0;
        }

        for(auto e: rel[breed]){
            for(auto next: cbreed[e]){
                if(dist[next] > dist[t.second] + abs(next - t.second)){
                    dist[next] = dist[t.second] + abs(next - t.second);
                    q.push(pa(dist[next], next));
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}