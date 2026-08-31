#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

int main() 
{
    int n;
    std::cin >> n;
    std::map<std::string, std::vector<int>> v;
    for (int i = 0; i < n; ++i) 
    {
        std::string s;
        int y;
        std::cin >> s >> y;
        v[s].push_back(y);
    }
    for (auto& par : v) 
    {
        std::sort(par.second.begin(), par.second.end());
    }
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) 
    {
        std::string s;
        int k;
        std::cin >> s >> k;
        std::cout << v[s][k - 1] << "\n";
    }
    return 0;
}