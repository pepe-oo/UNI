#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    int cont = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n ; ++j)
        {
            if ((v[i] + v[j]) % 2 == 0 && std::abs(v[i] - v[j]) <= k) {++cont;} 
        }
    }
    std:: cout << cont << std::endl;
}