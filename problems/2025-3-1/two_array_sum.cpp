// 2143 두 배열의 합
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// 배열 합 T로 만들기 경우의 수
// n, m <= 1000

// 크게보면 A + B 합이 T

// 한 배열에서 가능한 부분합 조합 
// 2 ^ 1000

// 각 부분배열의 합의 모든 조합 구해서 A + B ?


int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int T;
    cin >> T;

    int n;
    cin >> n;

    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    
    int m;
    cin >> m;

    vector<int> B;
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        B.push_back(b);
    }

    // 부 배열의 합 완전탐색
    map<int, long long> A_sum;

    for (int i = 0; i < n; i++)
    {
        int sum = A[i];
        A_sum[sum]++;
        for (int j = i + 1; j < n; j++)
        {
            sum += A[j];
            A_sum[sum]++;
        }
    }

    // 계산
    long long count = 0;
    for (int i = 0; i < m; i++)
    {
        int sum = B[i];
        if(A_sum[T - sum] > 0)
            count += A_sum[T - sum];
        for (int j = i + 1; j < m; j++)
        {
            sum += B[j];
            if(A_sum[T - sum] > 0)
                count += A_sum[T - sum];
        }
    }

    cout << count;
    
    return 0;
}