// 30805 사전 순 최대 공통 부분 수열
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1 9 7 3
// 1 8 7 5 3

// 1 7 5 9 3

// 1 7 3
// 7 3

// 높은 순서로

int A_size, B_size;
vector<int> A;
vector<int> B;
vector<int> lcs;

int main(void) 
{

    cin >> A_size;
    for (int i = 0; i < A_size; i++)
    {
        int num;
        cin >> num;
        A.push_back(num);
    }

    cin >> B_size;
    for (int i = 0; i < B_size; i++)
    {
        int num;
        cin >> num;
        B.push_back(num);
    }

    int _max = 0;
    for(auto& a : A)
    {
        _max = max(_max, a);
    }
    for(auto& a : B)
    {
        _max = max(_max, a);
    }

    int A_cur = 0;
    int B_cur = 0;
    vector<int> answer;

    while(A_cur < A_size && B_cur < B_size && _max > 0)
    {
        // A에서 확인
        int A_plag = false;
        int A_index = A_cur;
        for (int i = A_cur; i < A_size; i++)
        {
            if(A[i] == _max)
            {
                A_plag = true;
                A_index = i;
                break;
            }
        }

        if(!A_plag) 
        {
            _max--;
            continue;
        }

        // B에서 확인
        int B_plag = false;
        int B_index = B_cur;
        for (int i = B_cur; i < B_size; i++)
        {
            if(B[i] == _max)
            {
                B_plag = true;
                B_index = i;
                break;
            }
        }

        if(!B_plag) 
        {
            _max--;
            continue;
        }

        answer.push_back(_max);
        A_cur = A_index + 1;
        B_cur = B_index + 1;

    }

    cout << answer.size() << "\n";
    for(auto& a : answer)
    {
        cout << a << " ";
    }

    return 0;
}