#include <iostream>
#include <vector>

int main()
{
    int n;
    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
    {
        std::cin >> n;
        v.push_back(n);
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int k = 0; k < 4; ++k)
        {
            if (v[k] > v[k+1])
            {
                int aux = v[k];
                v[k] = v[k+1];
                v[k + 1] = aux;
            for (int m = 0; m < 5; ++m) {std::cout << v[m] << (m < 4 ? " " : "");}
            std::cout << std::endl;
            }
        }
    }
    return 0;
}