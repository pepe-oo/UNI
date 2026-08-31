#include <vector>
#include <iostream>

int sum (std::vector<int> comb, int n)
{
    int out = 0;
    for (int i = 0; i < n; ++i) {out += comb[i];}
    return out;
}

void solve (std::vector<int>& comb, int pos, int n, int& cont, const std::vector<int>& opciones, int suma, int max)
{
    if (comb.size() == n)
    {
        if (sum(comb,n) == suma) 
        {
            ++cont;
            
        }
        //for (int i = 0; i < n; ++i) {std::cout << comb[i] << std::endl;}
        return;
    }
    std::cout << pos << std::endl;
    if (pos == max) {return;}
    if  (!comb.empty() && sum(comb, n) + pos < suma)
    {
        comb.push_back(opciones[pos]);
        solve(comb, pos + 1, n, cont, opciones, suma, max);
        comb.pop_back();
    }
    solve(comb, pos + 1, n, cont, opciones, suma, max);
}

int main()
{
    int cantidad, max, suma;
    std::cin >> cantidad >> max >> suma;
    std::vector<int> opciones;
    for (int i = 1; i <= max; ++i)
    {
        opciones.push_back(i);
    }
    std::vector<int> comb;
    int cont = 0;
    solve (comb, 0, cantidad, cont, opciones, suma, max);
    std::cout << cont << std::endl;
    return 0;
}