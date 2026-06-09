#include <iostream>
#include <vector>

void solve(size_t start,int n,int k, std::vector<int>& actual)
{
    for (int i = start; i < n + 1; ++i)
    {
        actual.push_back(i);
        if (actual.size() == k) 
        {
            for (int j = 0; j < k; ++j)
            {
                std::cout << actual[j];
                if (j < actual.size() - 1) {std::cout << " ";}
            }
            std::cout << std::endl;
        }
        else 
        {
            solve(i + 1,n,k,actual);
        }
        actual.pop_back();
    }
    
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> actual;
    solve(1,n,k,actual);
    return 0;
}