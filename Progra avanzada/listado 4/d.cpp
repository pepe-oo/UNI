#include <iostream>
#include <string>
#include <vector>

bool backtraing (std::vector<std::string>& v, std::string& pass, size_t cont, std::string out, std::vector<bool>& fallos)
{
    if (cont == pass.length()) 
    {
        std::cout << out << std::endl;
        return true;
    }
    if (fallos[cont] == true) {
        return false; 
    }
    for (size_t i = 0; i < v.size(); i++)
    {
        if (pass.substr(cont,v[i].size()) == v[i])
        {
            std::string salida;
            if (out == "") {salida = v[i];}
            else {salida =  out + " " + v[i];}
            if (backtraing(v,pass,cont + v[i].size(), salida,fallos) == true ) {return true;}
            
        }
    }
    fallos[cont] = true;
    return false;
}

int main()
{
    int x;
    std::cin >> x;
    for (int k = 0; k < x; k++)
    {
        std::vector<std::string> v;
        std::string s;
        std::string pass;
        int n;
        std::cin >> n;
        
        for (int i = 0; i< n; i++)
        {
            std::cin >> s;
            v.push_back(s);
        }
        std::cin >> pass;
        std::vector<bool> fallos(pass.length() + 5, false);
        int cont = 0;
        if (backtraing(v,pass,cont,"",fallos) == false) {std::cout << "WRONG PASSWORD" << std::endl;}
    }
}