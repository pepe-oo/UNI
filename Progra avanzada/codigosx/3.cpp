#include <iostream>
#include <vector>

void solve(int n, std::vector<int>& perm, bool used[])
{
    int size = perm.size();
    if (size == n) 
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << perm[j];
            if (j < size - 1) {std::cout << " ";}
        }
        std::cout << std::endl;
        return;
    }
    for (int i = 1; i < n + 1; ++i)
    {
        if (used[i]) continue;                        // ya está en perm
        if (!perm.empty() && abs(perm.back() - i) == 1) {continue;}
        perm.push_back(i);
        used[i] = 1;
        solve(n,perm,used);
        perm.pop_back();
        used[i] = 0;
    }
}

int main()
{
    int n;
    std::cin >> n;
    bool used[n + 1] = {};
    std::vector<int> perm;
    solve(n, perm, used);
    return 0;
}