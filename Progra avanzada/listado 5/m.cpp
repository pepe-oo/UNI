#include <iostream>

int suma(long long numero) 
{
    int suma = 0;
    while (numero > 0) 
    {
        suma += (numero % 10);
        numero /= 10;
    }
    return suma;
}

int main() {
    long long n;
    while (std::cin >> n && n != 0) {
        int sumaOriginal = suma(n);
        long long p = 11; 
        while (true) 
        {
            if (suma(n * p) == sumaOriginal) 
            {
                std::cout << p << std::endl;
                break; 
            }
            p++;
        }
    }
    return 0;
}