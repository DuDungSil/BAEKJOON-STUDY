// 7579 앱
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 앱 비활성화

// 총합 M을 넘는 값중 가장 비용이 적게드는 방법
// 목표 1. 메모리 M이상 확보
//      2. 최소비용

// 배낭 알고리즘?
// 필요한 메모리 확보 => 메모리 초과
// 

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> memorys(N + 1);
    vector<int> cost(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        memorys[i] = a;
    }

    int max_cost = 0;
    for (int i = 1; i <= N; i++)
    {
        int c;
        cin >> c;
        cost[i] = c;
        max_cost += c;
    }

    // 배낭 알고리즘
    vector<int> dp(max_cost + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        for (int j = max_cost; j >= cost[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - cost[i]] + memorys[i]);
        }
    }


    for (int j = 0; j <= max_cost; j++)
    {
        if(dp[j] >= M)
        {
            cout << j;
            break;
        }
    }

    return 0;
}