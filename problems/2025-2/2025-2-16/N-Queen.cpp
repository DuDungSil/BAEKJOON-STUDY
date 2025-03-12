// 9663 N-Queen
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 완전 탐색

// 과거 기록은 어떻게 남길꺼? 각 행의 열정보
// 대각선 체크는?       1. 함수적 체크 (x - y) == (arr[i] - i) || (x + y) == (arr[i] + i)
//                     2. 거리적 체크 abs(arr[i] - x) == abs(i - y)

int N;
int _count = 0;
int arr[17] = {
    0,
};

bool check(int x, int y)
{
    // y의 x 에 놨을때 arr[y-1] 까지 체크
    for (int i = 1; i < y; i++)
    {
        if(x == arr[i] || (x - y) == (arr[i] - i) || (x + y) == (arr[i] + i))
            return false;
    }
    return true;
}

void nQueen(int n)
{

    if( n == N+1)
    {
        _count++;
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if(check(i, n))
        {
            arr[n] = i;
            nQueen(n + 1);
        }
    }

}

int main(void) 
{

    cin >> N;

    nQueen(1);

    cout << _count;

    system("\npause");
    return 0;
}