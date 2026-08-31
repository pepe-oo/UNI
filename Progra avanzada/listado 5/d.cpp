#include <iostream>
#include <vector>

int main() 
{
    int casos;
    std::cin >> casos;
    while (casos--) 
    {
        int n;
        std::cin >> n;
        std::vector<int> posiciones;
        for (int i = 0; i < n; ++i) 
        {
            posiciones.push_back(i);
        }
        std::vector<int> resultado(n);
        int indice_actual = 0;
        for (int i = 1; i <= n; ++i) 
        {
            indice_actual = (indice_actual + i) % posiciones.size();
            int pos_elegida = posiciones[indice_actual];
            resultado[pos_elegida] = i;
            posiciones.erase(posiciones.begin() + indice_actual);
        }
        for (int i = 0; i < n; ++i) 
        {
            std::cout << resultado[i];
            if (i < n - 1) 
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}