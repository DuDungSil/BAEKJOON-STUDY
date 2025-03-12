// 10942 팰린드롬?
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 각 범위마다 중앙이 달라지면 ?


int N, M;
vector<int> numbers;
vector<vector<bool>> dp;

void palindrome()
{
    dp = vector<vector<bool>>(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        dp[i][i] = true;
    }

    for (int i = 0; i < N; i++)
    {
        dp[i][i+1] = ( numbers[i] == numbers[i+1] );
    }

    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j + i < N; j++)
        {
            dp[j][j + i] = dp[j + 1][j + i - 1] && (numbers[j] == numbers[j + i]);
        }
    }
}

int main(void) 
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    palindrome();

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int S, E;
        cin >> S >> E;
        if(dp[S - 1][E - 1])
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }

    return 0;
}