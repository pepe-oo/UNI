#include <iostream>
#include <vector>
#include <string>

int main ()
{
    std::string texto;
    std::cin >> texto;
    int cont = 0;
    for (int i = 0; i < texto.length(); ++i)
    {
        if (texto[i] == 'e') {++cont;}
    }
    cont *= 2;
    std::cout << 'h';
    for (int i = 0; i < cont; ++i) {std::cout << 'e';}
    std::cout << 'y' << std::endl;
    return 0;
}