// 27172 수 나누기 게임
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int const MAX_NUM = 1000001;

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> numbers(N + 1);
    vector<int> scores(MAX_NUM, 0) ;
    vector<bool> table(MAX_NUM, false);
    for (int i = 1; i <= N; i++)
    {
        cin >> numbers[i];
        table[numbers[i]] = true;
    }

    // 전처리 
    for (int i = 1; i <= N; i++)
    {
        int number = numbers[i];

        for(int j = number * 2; j < MAX_NUM; j += number)
        {
            if(table[j])
            {
                scores[number]++;
                scores[j]--;
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        cout << scores[numbers[i]] << " ";
    }


    return 0;
}