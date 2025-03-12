// 11049 행렬 곱셈 순서
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 행렬 곱셈 연산의 최소값

// 분할정복?
// dp => 완전탐색형태로 다 해봐야하기 때문

int const INF = 987654321;

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> matrixs;
    for (int i = 0; i < N; i++)
    {
        int r, c;
        cin >> r >> c;
        matrixs.push_back({r, c});
    }

    // dp
    vector<vector<int>> dp(N, vector<int>(N, INF));
    // i ~ j 까지 곱하는데 최소 연산 횟수

    for (int i = 0; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int k = 1; k < N; k++)
    {
        for (int i = 0; i < N - k; i++)
        {
            int j = i + k;

            for (int mid = i; mid < j; mid++)
            {
                int cost = dp[i][mid] + dp[mid+1][j] + matrixs[i].first * matrixs[mid].second * matrixs[j].second;
                dp[i][j] = min(cost, dp[i][j]);
            }
        }
    }

    cout << dp[0][N - 1];

    return 0;
}