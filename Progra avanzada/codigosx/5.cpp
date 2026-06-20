#include <iostream>
#include <vector>
#include <math.h>

void solve(std::vector<int> x, const std::vector<int> &v)
{
    
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v;
    while (n > 0)
    {
        int digit = n % 10;
        v.push_back(digit);
        n /= 10;
    }
    std::vector<int> x = v;
    solve(x,v);
    return 0;
}