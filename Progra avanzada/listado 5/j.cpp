#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool validar (const std::string& a, const std::string& b)
{
    if (a[0] != b[0]) {return a[0] < b[0];}
    return a[1] < b[1];
}

int main()
{
    int n;
    while (scanf("%d",&n) && n != 0)
    {
        std::vector<std::string> lista;
        std::string texto;
        for (int i = 0; i < n; ++i) 
        {
            std::cin >> texto;
            lista.push_back(texto);
        }
        std::stable_sort(lista.begin(),lista.end(),validar);
        for (int i = 0; i < n; ++i)
        {
            std:: cout << lista[i] << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}