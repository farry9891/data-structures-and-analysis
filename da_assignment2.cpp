//Q1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct act {
    int s, f;
};

bool cmp(act a, act b) {
    return a.f < b.f;
}

int main() {
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    vector<act> v(n);
    for (int i = 0; i < n; i++) {
        v[i].s = start[i];
        v[i].f = finish[i];
    }

    sort(v.begin(), v.end(), cmp);

    vector<act> res;
    res.push_back(v[0]);
    int last_f = v[0].f;

    for (int i = 1; i < n; i++) {
        if (v[i].s >= last_f) {
            res.push_back(v[i]);
            last_f = v[i].f;
        }
    }

    cout << "Maximum number of activities = " << res.size() << endl;
    cout << "Selected activities: ";
    for (int i = 0; i < res.size(); i++) {
        cout << "(" << res[i].s << ", " << res[i].f << ")";
        if (i < res.size() - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}

'''
Output=
Maximum number of activities = 4
Selected activities: (1, 2), (3, 4), (5, 7), (8, 9)
'''

//____________________________________________________________________________________________________//

//Q2

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    string at[] = {"09:00", "09:10", "09:20", "11:00", "11:20"};
    string dt[] = {"09:40", "12:00", "09:50", "11:30", "11:40"};
    int n = 5;
    vector<int> arr(n), dep(n);

    for (int i = 0; i < n; i++) {
        arr[i] = stoi(at[i].substr(0, 2)) * 60 + stoi(at[i].substr(3, 2));
        dep[i] = stoi(dt[i].substr(0, 2)) * 60 + stoi(dt[i].substr(3, 2));}

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int plat = 1, res = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat++;
            i++;
        } else {
            plat--;
            j++;
}
        res = max(res, plat);}
    cout << "Minimum number of platforms required = " << res << endl;
    return 0;
}

'''
Output
Minimum number of platforms required = 3
'''