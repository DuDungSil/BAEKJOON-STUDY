#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

deque<int> parse(string arr_string)
{
    deque<int> dq;
    int num = 0;
    for (int i = 1; i < arr_string.size(); i++)
    {
        char c = arr_string[i];
        if(c == ',')
        {
            dq.push_back(num);
            num = 0;
        }
        else if(c == ']')
        {
            if(num == 0) return dq;
            dq.push_back(num);
            return dq;
        }
        else
        {
            num = num * 10 + int(c - '0');
        }
    }
    return dq;
}

int main(void) 
{

    // R : 뒤집기
    // D : 첫 번째 수를 버리기 ( 비어있을시 에러 )

    // 시간초과 ?


    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string funtions;
        int arr_num;
        string arr_string;

        cin >> funtions >> arr_num >> arr_string;

        deque<int> dq = parse(arr_string);

        bool error = false;
        bool reverse = false;
        for (int index = 0; index < funtions.size(); index++)
        {
            char funtion = funtions[index];
            if(funtion == 'R')
            {
                reverse = !reverse;
            }
            else if(funtion == 'D')
            {
                if(dq.size() == 0)
                {
                    error = true;
                    break;
                }
                if(reverse)
                {
                    dq.pop_back();
                }
                else
                {
                    dq.pop_front();
                }
            }
        }

        if(error)
        {
            cout << "error" << '\n';
        }
        else
        {
            if(reverse)
            {
                cout << '[';
                while(!dq.empty())
                {
                    cout << dq.back();
                    dq.pop_back();
                    if(!dq.empty()) cout << ',';
                }
                cout << ']' << '\n';
            }
            else
            {
                cout << '[';
                while(!dq.empty())
                {
                    cout << dq.front();
                    dq.pop_front();
                    if(!dq.empty()) cout << ',';
                }
                cout << ']' << '\n';
            }

        }

    
    }
    return 0;
}