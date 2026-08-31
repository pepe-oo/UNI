#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> residuos_vistos(42, 0);
    for (int i = 0; i < 10; ++i) 
    {
        int num;
        if (std::cin >> num) 
        {
            int residuo = num % 42;
            residuos_vistos[residuo] = 1;
        }
    }
    int cantidad = 0;
    for (int i = 0; i < 42; ++i) 
    {
        if (residuos_vistos[i] == 1) 
        {
            cantidad += 1;
        }
    }
    std::cout << cantidad << std::endl;
    return 0;
}