#include <iostream>
#include <vector>
#include <string>
#include <utility>

std::vector<std::string> mejor_comb;
int max = 0;

bool validar (std::string comb, std::string opcion, const std::vector<std::pair<std::string,std::string>> restricciones)
{
    std::pair<std::string, std::string> duo1 (comb, opcion);
    std::pair<std::string, std::string> duo2 (opcion, comb);
    for (size_t i = 0; i < restricciones.size(); ++i)
    {
        if (restricciones[i] == duo1 || restricciones[i] == duo2)
        {
            return false;
        }
    }
    return true;
}

void solve (std::vector<std::string>& comb, std::vector<bool>& usado, int n, int & cont, const std::vector<std::string>& opciones, const std::vector<std::pair<std::string,std::string>> restricciones)
{
    if (comb.size() == n)
    {
        ++cont;
        int cont_mjr = 0;
        for (int i  = 0; i < n; ++i)
        {
            if (comb[i] == opciones[i]) {++cont_mjr;}
        }
        if (cont_mjr > max) 
        {
            max = cont_mjr;
            mejor_comb = comb;
        }
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!usado[i])
        {
            if (comb.empty() || validar (comb.back(), opciones[i], restricciones))
            {
                usado[i] = true;
                comb.push_back(opciones[i]);
                solve (comb, usado, n, cont, opciones, restricciones);
                usado[i] = false;
                comb.pop_back();
            }
        }
    }
}

int main()
{
    int a;
    std::cin >> a;
    for (int i = 0; i < a; ++i)
    {
        int n;
        std::cin >> n;
        std::vector<std::string> opciones;
        for (int i = 0; i < n; ++i)
        {
            std::string color;
            std::cin >> color;
            opciones.push_back(color);
        }
        int x;
        std::cin >> x;
        std::vector<std::pair<std::string, std::string>> restricciones;
        for (int i = 0; i < x; ++i)
        {
            std::string col1, col2;
            std::cin >> col1 >> col2;
            restricciones.push_back({col1, col2});
        }
        std::vector<std::string> comb;
        int cont = 0;
        std::vector<bool> usado (n,false);
        solve(comb, usado, n, cont, opciones, restricciones);
        std::cout << cont << std::endl;
        for (int i = 0; i < n; ++i) {std::cout << mejor_comb[i] << ' ';}
        std::cout << std::endl;
    }
    return 0;
}