#include <iostream>
#include <vector>
#include <string>

int main() 
{
    std::string t;
    std::cin >> t;
    std::vector<char> out;
    for (size_t i = 0; i < t.length(); ++i) 
    {
        char caracter_actual = t[i];
        if (caracter_actual == '<') 
        {
            if (!out.empty()) 
            {
                out.pop_back();
            }
        } 
        else 
        {
            out.push_back(caracter_actual);
        }
    }
    for (size_t i = 0; i < out.size(); ++i) 
    {
        std::cout << out[i];
    }
    std::cout << std::endl;
    return 0;
}