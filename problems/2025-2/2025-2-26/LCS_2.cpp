// 9252 LCS 2
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// lcs 의 길이 출력 -> dp
// lcs의 문자 출력 ?
// 오토마타?

string str1, str2;
vector<vector<string>> strr;

void make_table()
{

}

int main(void) 
{


    cin >> str1 >> str2;

    strr = vector<vector<string>>(str1.size() + 1, vector<string>(str2.size() + 1, ""));
    for (int i = 1; i <= str1.size(); i++)
    {
        char c1 = str1[i-1];
        for (int j = 1; j <= str2.size(); j++)
        {
            char c2 = str2[j-1];

            if(c1 == c2)
            {
                strr[i][j] = strr[i - 1][j - 1] + c2;
            }
            else
            {
                if(strr[i - 1][j].size() > strr[i][j-1].size())
                {
                    strr[i][j] = strr[i - 1][j];
                }
                else
                {
                    strr[i][j] = strr[i][j - 1];
                }
            }
        }
    }

    int big_size = 0;
    int big_index = 0;
    for (int i = 1; i <= str2.size(); i++)
    {
        string s = strr[str1.size()][i];
        if(s.size() > big_size)
        {
            big_size = s.size();
            big_index = i;
        }
    }

    cout << big_size << "\n"
         << strr[str1.size()][big_index];

    return 0;
}