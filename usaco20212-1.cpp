#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 2e6+1;
int N, P[MAX];
int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int t;
        cin >> t;
        P[t]++;
    }
 
    for (int i=1; i<MAX; i++)
        P[i] += P[i-1];
 
 
    long long ans = 0;
    // 처음 시작하는 돌을 i개 사용하는 경우
    // i개를 가져가겠다고 선언하면 그냥 모든 무더기를 [a_x / i]개 이고 이 중에서 하나를 빼는 것이라 생각할 수 있음
    // 돌을 1개만 가져가는 상황으로 환원 후, 실제로 1개를 가져온 다음에 크기가 같은 돌무더기끼리 묶었을 때 전부 짝수개씩 묶인다면 필승, 이외의 경우에는 필패
 
    for (int i=1; i<=1e6; i++) {
        // i개를 마치 한개의 덩어리로 봐야 하므로 i로 나눈 개수 구함
        
        // 크기가 같은 돌무더기 끼리 묶었을 때 개수가 홀수개인 덩어리의 수
        vector<int> when;   // 그떄가 언제였는지
        vector<int> num;    // 그런 덩어리에 무더기가 몇개 있는지 
        // 
        for (int j=i; j<=1e6; j+=i) {
            // [j, j+i) 사이 구간의 개수
            if ((P[j+i-1] - P[j-1])%2 == 1) {
                when.push_back(j);
                num.push_back(P[j+i-1] - P[j-1]);
            }
        }
        
        // 개수가 홀수개 있는게 딱 하나고 그게 1개짜리 덩어리인경우
        if (when.size() == 1 && when[0] == i) {
            ans += num[0];
        } else if (when.size() == 2 && when[0] == when[1]-i) {
            // 개수가 홀수개 있는게 딱 두개고 그게 붙어있는 덩어리인 경우
            ans += num[1];
        }
    }
    cout << ans;
 
}