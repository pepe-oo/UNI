#include <iostream>
#include <vector>
#include <string>

bool base (std::string comb)
{
    for (size_t i = 0; i < comb.length(); ++i) 
    {
        if (comb[i] == '_') {return false;}
    }
    return true;
}

bool valida(std::string comb)
{

}

void solve (std::string& comb, std::vector<bool>& usado, int n, const std::vector<char>& opciones, int& cont)
{
    if (base(comb))
    {
        ++cont;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (comb[i] == '_')
        {
            
        }
    }
}

int main()
{
    std::string palabra;
    std::cin >> palabra;
}