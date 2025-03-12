// 1644 소수의 연속합
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 소수, 연속합
// 슬라이딩 윈도우
// 왼쪽 포인터 : 빼는 역할
// 오른쪽 포인터 : 더하는 역할할

int _count = 0;
vector<bool> primes;
vector<int> prime_nums;

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int N;
    cin >> N;

    primes = vector<bool>(N + 1, true);
    prime_nums = vector<int>();
    primes[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if(primes[i])
            prime_nums.push_back(i);

        for (int j = i * 2; j <= N; j += i)
        {
            primes[j] = false;
        }
    }

    if(N==1)
    {
        cout << 0;
        exit(0);
    }

    // 나머지 경우 확인
    int l_ptr = 0;
    int r_ptr = 0;
    int total_sum = prime_nums[r_ptr];
    while(r_ptr < prime_nums.size())
    {
        if(total_sum > N)
        {
            total_sum -= prime_nums[l_ptr];
            l_ptr++;
        }
        else if(total_sum < N)
        {
            r_ptr++;
            total_sum += prime_nums[r_ptr];
        }
        else
        {
            _count++;
            r_ptr++;
            total_sum += prime_nums[r_ptr];
        }
    }

    cout << _count;
    return 0;
}