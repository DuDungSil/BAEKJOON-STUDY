// 13172 시그마
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 1000000007;

// 기댓값
// a/b 를 a x b ^-1 mod X 로 계산
// 모듈러 곱셈에 대한 역원 b^-1

long long moduler(long long a, long long b)
{
    int num = MOD - 2;
    long long result = 1;
    while(num > 0)
    {
        if(num % 2 == 1)
        {
            result = (result * b) % MOD;
        }
        b = (b * b) % MOD;
        num /= 2;
    }

    return (a * result) % MOD;
}

int main(void) 
{

    int M;
    cin >> M;

    long long sum = 0;
    for (int i = 0; i < M; i++)
    {
        int N, S;
        cin >> N >> S;
        sum = (sum + moduler(S, N)) % MOD;
    }

    cout << sum;

    return 0;
}