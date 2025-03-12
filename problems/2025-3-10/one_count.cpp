// 9527 1의 개수 세기
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// 10 ^ 16  long long

// 0 0            0

// 1 1            1   1

// 2 10           1
// 3 11           2   1 + 2

// 4 100          1
// 5 101          2
// 6 110          2
// 7 111          3   1 + 2 + 4

// 8 1000         1
// 9 1001         2
// 10 1010        2
// 11 1011        3
// 12 1100        2
// 13 1101        3
// 14 1110        3
// 15 1111        4   1 + 2 + 4 + 8

// dp?

// 점화식 구하기 

// 12 -> 4
// 12 - 8 + 1 + 7 = 12
// 4 - 4 + 1 + 3 = 4

// 5 +  ( 7 + 3 + 1 )  1 + ( 3 + 1 )

vector<long long> dp;

long long get_one(long long num)
{
    if(num == 0) return 0;
    if (num == 1) return 1;

    long long temp = num;

    int digit = 0;
    while(temp != 1)
    {
        temp /= 2;
        digit++;
    }

    long long rest = num - (1LL << digit);

    return rest + 1 + dp[digit] + get_one(rest);
}

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    long long A, B;
    cin >> A >> B;

    long long temp = B;
    int digit = 0;
    while(temp != 1)
    {
        temp /= 2;
        digit++;
    }

    dp = vector<long long>(digit + 1);
    dp[0] = 0;

    // 2의 배수 dp 
    for (int i = 1; i <= digit; i++)
    {
        // 이전 구간 반복 2배 + 맨앞 1의 개수 2^(i-1) 개
        dp[i] = (1LL << (i - 1)) + 2 * dp[i - 1];
    }

    cout << get_one(B) - get_one(A - 1);



    return 0;
}