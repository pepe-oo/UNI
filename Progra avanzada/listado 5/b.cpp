#include <iostream>
#include <vector>

int main() 
{
    int n;
    std::cin >> n;
    int total = 2 * n;
    std::vector<int> pila(total);
    for (int i = 0; i < total; ++i) 
    {
        std::cin >> pila[i];
    }
    std::vector<int> aux;
    aux.reserve(total);
    long long movimientos = 0;
    for (int i = 0; i < total; ++i) 
    {
        int calcetine_actual = pila[i];
        if (!aux.empty() && aux.back() == calcetine_actual) 
        {
            aux.pop_back();
            movimientos += 1;
        } 
        else 
        {
            aux.push_back(calcetine_actual);
            movimientos += 1;
        }
    }
    if (aux.empty()) 
    {
        std::cout << movimientos << "\n";
    } else 
    {
        std::cout << "impossible\n";
    }

    return 0;
}