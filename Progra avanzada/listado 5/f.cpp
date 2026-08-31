#include <iostream>
#include <vector>
#include <string>

int main() 
{
    int lineas;
    std::cin >> lineas;
    std::string basura;
    std::getline(std::cin, basura);
    while (lineas--) {
        std::string frase;
        std::getline(std::cin, frase);
        std::vector<int> letras_vistas(26, 0);
        for (size_t i = 0; i < frase.length(); ++i) 
        {
            char letra = frase[i];
            if (letra >= 'A' && letra <= 'Z') 
            {
                int indice = letra - 'A';
                letras_vistas[indice] = 1;
            } 
            else if (letra >= 'a' && letra <= 'z') 
            {
                int indice = letra - 'a';
                letras_vistas[indice] = 1;
            }
        }
        std::vector<char> faltantes;
        for (int i = 0; i < 26; ++i) 
        {
            if (letras_vistas[i] == 0) 
            {
                char letra_faltante = 'a' + i;
                faltantes.push_back(letra_faltante);
            }
        }
        if (faltantes.empty()) 
        {
            std::cout << "pangram\n";
        } 
        else 
        {
            std::cout << "missing ";
            for (size_t i = 0; i < faltantes.size(); ++i) 
            {
                std::cout << faltantes[i];
            }
            std::cout << "\n";
        }
    }
    return 0;
}