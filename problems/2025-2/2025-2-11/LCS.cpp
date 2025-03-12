// 9251 LCS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ACAYKP
// 011111
// 112222
// 112223
// 122223
// 123333
// 123344
// CAPCAK


int main(void) 
{

    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>> dp(str2.size() + 1, vector<int>(str1.size() + 1, 0));

    for (int i = 1; i <= str2.size(); i++)
    {
        char c = str2[i - 1];

        for (int j = 1; j <= str1.size(); j++)
        {
            char now = str1[j - 1];

            if(now == c)
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    cout << dp[str2.size()][str1.size()];

    return 0;
}