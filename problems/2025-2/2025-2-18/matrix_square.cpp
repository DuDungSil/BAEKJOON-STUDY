// 10830 행렬 제곱
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// A 행렬 B 제곱

long long N, B;
long long A[6][6];
long long answer[6][6];

void mult(long long _A[6][6], long long _B[6][6])
{
    long long temp[6][6];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int sum = 0;
            for (int k = 0; k < N; k++)
            {
                sum += ( _A[i][k] * _B[k][j] ) % 1000;
            }
            temp[i][j] = sum % 1000;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            _A[i][j] = temp[i][j];
        }
    }
}

int main(void) 
{

    cin >> N >> B;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
        answer[i][i] = 1;
    }

    long long num = B;
    while (num > 0)
    {
        if(num % 2 == 1)
        {
            mult(answer, A);
        }
        mult(A, A);

        num = num / 2;

    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << answer[i][j] << " ";
        }
        cout <<  "\n";
    }

    return 0;
}