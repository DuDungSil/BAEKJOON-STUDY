// 1806 부분합
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 10000 이하로 이루어진 N짜리 수열
// 연속된 수들의 부분합 중 그 합이 S이상이 되는 것중 가장 짧은 것

// 큐로 풀었지만 -> 투포인터가 더 메모리 효율적

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int sum = 0;
    int size = 0;
    int small_size = 100001;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        int num = arr[i];
        q.push(num);
        sum = sum + num;
        size++;

        if(sum >= S)
        {
            while(!q.empty())
            {
                int front = q.front();
                if(sum - front < S)
                {
                    break;
                }
                q.pop();
                size--;
                sum = sum - front;
            }
            small_size = min(small_size, size);
        }
    }

    if(small_size == 100001)
        cout << 0;
    else cout << small_size;

    return 0;
}