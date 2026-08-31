#include <iostream>
#include <string>

int main() 
{
    std::string texto;
    std::cin >> texto;
    int dias = 0;
    for (size_t i = 0; i < texto.length(); ++i) 
    {
        int residuo = i % 3;
        char caracter_actual = texto[i];
        if (residuo == 0) 
        {
            if (caracter_actual != 'P') { ++dias;}
        } 
        else if (residuo == 1) 
        {
            if (caracter_actual != 'E') { ++dias;}
        } 
        else 
        {
            if (caracter_actual != 'R') {++dias;}
        }
    }
    std::cout << dias << "\n";
    return 0;
}