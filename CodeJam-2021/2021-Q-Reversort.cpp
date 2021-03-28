/*
	Solution to 2021 Qualifications Problem: "Reversort"
	Copyright (c) Michal Maksymow. All rights reserved. No warranty.

    Submited 26.03.2021 with 28:30 penalty time
    Scored 7 / 7 points
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef long long ll;

int main()
{
    ui cases, caseno{1}, read;
    cin >> cases;
    vector<ui> list;
    while (cases--)
    {
        ui len, cost{};
        cin >> len;
        for (size_t i = 0; i < len; i++)
        {
            cin >> read;
            list.push_back(read);
        }

        for (size_t i = 0; i < len-1; i++)
        {
            int minElementIndex = std::min_element(list.begin() + i, list.end()) - list.begin();
            std::reverse(list.begin() + i, list.begin() + minElementIndex + 1);
            cost += minElementIndex - i + 1;
        }
        cout << "Case #" << caseno << ": " << cost << endl;
        caseno++;
        list.clear();
    }

    return 0;
}
