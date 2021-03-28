/*
	Solution to 2021 Qualifications Problem: "Reversort Engineering"
	Copyright (c) Michal Maksymow. All rights reserved. No warranty.

    Submited 26.03.2021 with 4:31:09 penalty time
    Scored 18 / 18 points
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef long long ll;

int weakens(int n)
{
    int res{};
    for (size_t i = 2; i <= n; ++i)
        res += i;
    return res;
}

void printVec(int caseno, vector<ui> &vec)
{
    cout << "Case #" << caseno << ": ";
    for (auto e : vec)
        cout << e << " ";
    cout << '\n';
}

int main()
{
    ui cases, caseno{1};
    cin >> cases;

    while (cases--)
    {
        ui t, c;
        cin >> t >> c;

        if (c < t - 1 || c > weakens(t))
        {
            cout << "Case #" << caseno << ": IMPOSSIBLE" << endl;
            caseno++;
            continue;
        }

        vector<ui> list;
        for (size_t i = 1; i <= t; ++i)
            list.push_back(i);

        for (size_t turn = 1; turn < t; turn++)
        {
            ui turnsLeft = t - turn - 1;
            if (c == turnsLeft + 1)
                break;

            if (turn + 1 <= c - turnsLeft)
            {
                std::reverse(list.begin() + list.size() - (turn + 1), list.begin() + list.size());
                c -= turn + 1;

                // printVec(caseno, list);
                // cout << "c1: " << c << endl;
            }
            else
            {
                std::reverse(list.begin() + list.size() - (turn + 1), list.begin() + list.size() - (turn + 1) + c - turnsLeft);
                c -= c - turnsLeft;

                // printVec(caseno, list);
                // cout << "c2: " << c << endl;
            }
        }
        printVec(caseno, list);
        caseno++;
    }

    return 0;
}
