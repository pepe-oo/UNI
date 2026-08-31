#include <iostream>
#include <vector>

int suma (std::vector<int> & comb)
{
    int out = 0;
    for (int i = 0; i < comb.size(); ++i)
    {
        out += comb[i];
    }
    return out;
}

void solve (int pos, int n, std::vector<int>& comb, int& cont,const std::vector<int>& opciones, int t)
{
    if (suma(comb) == t)
    {
        ++cont;
        return;
    }
    if (suma(comb) > t) {return;}
    if (pos == n) {return;}
    if (suma(comb) + opciones[pos] <= t)
    {
        comb.push_back(opciones[pos]);
        solve (pos + 1, n, comb, cont, opciones, t);
        comb.pop_back();
    }
    solve (pos + 1, n, comb, cont, opciones, t);
}

int main ()
{
    int n,t;
    std::cin >> n >> t;
    std::vector<int> opciones;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        opciones.push_back(x);
    }
    std::vector<int> comb;
    int cont = 0;
    solve(0,n,comb,cont,opciones,t);
    std::cout << cont << std::endl;
    return 0;
}