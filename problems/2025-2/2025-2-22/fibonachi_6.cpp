// 11444 피보나치수 6
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) 
{

    long long n;
    cin >> n;

    int dp[3];

    dp[0] = 0;
    dp[1] = 1;
    for (long long i = 2; i <= n; i++)
    {
        dp[2] = (dp[1] + dp[0]) % 1000000007;

        dp[0] = dp[1];
        dp[1] = dp[2];
    }

    cout << dp[1];

    return 0;
}