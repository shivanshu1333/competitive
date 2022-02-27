#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    long long an = 0;
    string s;
    cin >> s;
    map<int, int> mp;
    mp[0] = 1;
    int k = 0;
    for (auto& c : s) {
        int d = c - '0';
        k ^= 1 << d;
        an += mp[k];
        for (int i = 0; i < 26; ++i) {
            an += mp[k ^ (1 << i)];
        }
        mp[k] += 1;
    }
    cout << an << endl;
    return 0;
}