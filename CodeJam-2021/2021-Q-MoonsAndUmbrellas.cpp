/*
	Solution to 2021 Qualifications Problem: "Moons and Umbrellas"
	Copyright (c) Michal Maksymow. All rights reserved. No warranty.

    Submited 26.03.2021 with 2:13:58 penalty time
    Scored 15 / 16 points
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef long long ll;

int main()
{
    ui cases, caseno{1};
    cin >> cases;
    while (cases--)
    {
        ui x, y;
        cin >> x >> y;
        string str;
        cin >> str;
        ui cost{};

        str.erase(std::remove(str.begin(), str.end(), '?'), str.end());
        if (str.length() == 0)
        {
            cout << "Case #" << caseno << ": " << cost << endl;
            caseno++;
            continue;
        }
        for (size_t i = 0; i < str.length() - 1; i++)
        {
            if (str[i] == 'C' && str[i + 1] == 'J')
                cost += x;
            else if (str[i] == 'J' && str[i + 1] == 'C')
                cost += y;
        }
        cout << "Case #" << caseno << ": " << cost << endl;
        caseno++;
    }
    return 0;
}
