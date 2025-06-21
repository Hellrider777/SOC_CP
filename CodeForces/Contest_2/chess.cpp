#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{

    string s;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> s;
        for (int i = 0; i < 8; i++)
        {
            if (s[i] == 'Q')
                sum1 += 9;
            if (s[i] == 'q')
                sum2 += 9;
            if (s[i] == 'R')
                sum1 += 5;
            if (s[i] == 'r')
                sum2 += 5;
            if (s[i] == 'B')
                sum1 += 3;
            if (s[i] == 'b')
                sum2 += 3;
            if (s[i] == 'N')
                sum1 += 3;
            if (s[i] == 'n')
                sum2 += 3;
            if (s[i] == 'P')
                sum1 += 1;
            if (s[i] == 'p')
                sum2 += 1;
        }
    }

    if (sum1 > sum2)
        cout << "White";
    else if (sum1 < sum2)
        cout << "Black";
    else if (sum1 == sum2)
        cout << "Draw";
}