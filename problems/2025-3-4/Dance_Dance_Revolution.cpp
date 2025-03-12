// 2342 Dance Dance Revolution
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 두 발이 같은 지점이 허용 x

// 중앙 -> 지점 : 2
// 지점 -> 인접지점 : 3
// 지점 -> 먼 지점 : 4
// 같은지점 : 1

// 그리디 x  => 반대편을 밟을때 이득인 경우가 존재
// dfs ? 2경우 ^ N 너무큼
// dp

// 아이디어
// 한쪽 발이 가만히 있는 경우가 이득일때 찾기?

// 경우 1. 그대로 ( 대각선 ) : 1
//      2. 정반대 : 3
//      3. 대각선 : 4

int const INF = 999999999;
int dp[100001][5][5];

int get_cost(int prev, int next)
{
    if(prev == 0)
        return 2;
    else if(prev == next)
        return 1;
    else if(abs(next - prev) == 1 || abs(next - prev) == 3)
        return 3;
    else
        return 4;
}

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int num;
    vector<int> nums;
    while(cin >> num && num != 0)
    {
        nums.push_back(num);
    }

    for (int i = 0; i <= nums.size(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i = 1; i <= nums.size(); i++)
    {
        int next = nums[i-1];
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                dp[i][j][next] = min(dp[i][j][next], dp[i-1][j][k] + get_cost(k, next));
                dp[i][next][k] = min(dp[i][next][k], dp[i-1][j][k] + get_cost(j, next));
            }
        }
    }

    int low_cost = INF;
    for (int j = 0; j < 5; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            low_cost = min(low_cost, dp[nums.size()][j][k]);
        }
    }
    cout << low_cost;

    return 0;
}