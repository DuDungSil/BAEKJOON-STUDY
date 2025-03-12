// 12865 평범한 배낭
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 각 물건 W , V
// 최대 K만큼의 무게 배낭
// 가치의 최대값

// 그리디?    보장이안됨
// 탐색?     가능한 무게의 모든 조합을 해봐야하지 않는가? -> 오래걸림 ( 조합 )
// DP?       1 의 무게당 가능한 조합의 최대를 구하자 
//            ㄴ 각 무게의 가능한 조합의 가치의 최댓값은 하나임
//            ㄴ 물품이 중복으로는 안들어가는 문제
//                 ㄴ 점화식이 있는가?
//            ㄴ 물품의 수가 100개밖에안됨
//           1 의 무게당 각 물품을 넣을지 말지 정하기 - 배낭 알고리즘

int main(void) 
{

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> v(N+1);
    for (int i = 1; i <= N; i++)
    {
        int W, V;
        cin >> W >> V;
        v[i] = {W, V};
    }

    // dp
    vector<vector<int>> dp(K+1, vector<int>(N+1));
    for(int j = 1; j <= N; j++)
    {
        dp[0][j] = 0;
    }

    for(int i = 1; i <= K; i++) // 무게
    {   
        for(int j = 1; j <= N; j++) // 물건 인덱스
        {
            int weight = v[j].first;
            int value = v[j].second;

            if(i < weight)
            {
                dp[i][j] = dp[i][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], value + dp[i-weight][j-1]);
            }
        }
    }

    cout << dp[K][N];


    return 0;
}