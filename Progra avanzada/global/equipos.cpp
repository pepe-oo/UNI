#include <iostream>
#include <vector>
#include <cmath>

int min = 1000000;

void solve (int n, std::vector<int> a, std::vector<int> b, const std::vector<int>& opciones, int pos)
{
    if (pos == n)
    {
        int valor_a = 0;
        for (size_t i = 0; i < a.size(); ++i)
        {
            valor_a += a[i];
        }
        int valor_b = 0;
        for (size_t i = 0; i < b.size(); ++i)
        {
            valor_b += b[i];
        }
        int dif = std::abs(valor_a - valor_b);
        if (dif < min) {min = dif;}
        return;
    }
    a.push_back(opciones[pos]);
    solve(n, a, b, opciones, pos + 1);
    a.pop_back();
    b.push_back(opciones[pos]);
    solve(n, a, b, opciones, pos + 1);
    b.pop_back();
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> opciones;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        opciones.push_back(x);
    }
    std::vector<int> a;
    std::vector<int> b;
    solve (n, a, b, opciones, 0);
    std::cout << min << std::endl;
    return 0;
}