// 12015 가장 긴 증가하는 부분 수열 2
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    vector<int> min_count(N);
    vector<int> max_count(N);
    vector<int> min_dp(N);
    vector<int> max_dp(N);

    min_count[0] = 1;
    max_count[0] = 1;
    min_dp[0] = numbers[0];
    max_dp[0] = numbers[0];
    for(int i = 1; i < N; i++)
    {
        int number = numbers[i];

        min_dp[i] = min_dp[i - 1];
        min_count[i] = min_count[i - 1];
        max_dp[i] = max_dp[i - 1];
        max_count[i] = max_count[i - 1];

        if(number < min_dp[i - 1])
        {
            min_dp[i] = number;
            min_count[i] = 1;
        }
        else if(number > max_dp[i - 1])
        {
            max_dp[i] = number;
            min_count[i] = min_count[i - 1] + 1;
            max_count[i] = max(max_count[i - 1], min_count[i - 1]) + 1;
        }
        else if (number > numbers[i-1])
        {
            min_count[i] = min_count[i-1] + 1;
        }

    }

    cout << max(min_count[N-1], max_count[N-1]);

    return 0;
}