// 2096 내려가기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// dp?

int main(void) 
{

    int N;
    cin >> N;

    int arr[100001][3];
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    // dp
    int min_dp[2][3];
    int max_dp[2][3];
    min_dp[0][0] = arr[1][0];
    min_dp[0][1] = arr[1][1];
    min_dp[0][2] = arr[1][2];
    max_dp[0][0] = arr[1][0];
    max_dp[0][1] = arr[1][1];
    max_dp[0][2] = arr[1][2];
    for (int i = 2; i <= N; i++)
    {
        min_dp[1][0] = arr[i][0] + min(min_dp[0][0], min_dp[0][1]);
        min_dp[1][1] = arr[i][1] + min(min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]);
        min_dp[1][2] = arr[i][2] + min(min_dp[0][1], min_dp[0][2]);

        max_dp[1][0] = arr[i][0] + max(max_dp[0][0], max_dp[0][1]);
        max_dp[1][1] = arr[i][1] + max(max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]);
        max_dp[1][2] = arr[i][2] + max(max_dp[0][1], max_dp[0][2]);

        min_dp[0][0] = min_dp[1][0];
        min_dp[0][1] = min_dp[1][1];
        min_dp[0][2] = min_dp[1][2];

        max_dp[0][0] = max_dp[1][0];
        max_dp[0][1] = max_dp[1][1];
        max_dp[0][2] = max_dp[1][2];
    }

    int min_num = min(min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]);
    int max_num = max(max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]);
    cout << max_num << " " << min_num << "\n";



    return 0;
}