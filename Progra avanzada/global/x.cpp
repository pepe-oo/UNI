#include <iostream>
#include <vector>

void solve (std::vector<int> opciones, int n, std::vector<int>& comb, int k,std::vector<bool> usado)
{
    if (comb.size() == k)
    {
        for (int i = 0; i < k; ++i) {std::cout << comb[i] << " ";}
        std::cout << std::endl;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!usado[i])
        {
            usado[i] = true;
            comb.push_back(opciones[i]);
            solve (opciones,n,comb,k,usado);
            comb.pop_back();
            usado[i] = false;
        }
    }
}

int main ()
{
    int n,k;
    std::cin >> n >> k;
    std::vector<int> comb;
    std::vector<bool> usado (n,false);
    std::vector<int> opciones;
    for (int i = 1; i <= n; ++i)
    {
        opciones.push_back(i);
    }
    solve(opciones,n,comb,k,usado);
    return 0;
}