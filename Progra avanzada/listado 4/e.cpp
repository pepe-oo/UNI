#include <iostream>
#include <vector>
#include <string>

bool interseccion (int& posx, int& posy, std::vector<std::string>& mapa)
{
    int flag = 0;
    if (mapa[posx + 1][posy] == '.') {flag = 1;}
    if (mapa[posx -1][posy] == '.')
    {
        if(flag == 1) {return true;}
        flag = 1;
    }
    if (mapa[posx][posy + 1] == '.')
    {
        if(flag == 1) {return true;}
        flag = 1;
    }
    if (mapa[posx][posy - 1] == '.' && flag == 1){return true;}
    return false;
}

int backtracking (int& x, int& y, std::vector<std::string> mapa, int posx, int posy, int cont)
{
    if (mapa[posx][posy] == '*') {return cont;}
    if (posx >= x || posy >= y || posx < 0 || posy < 0) {return 0;}
    if (mapa[posx][posy] == 'x' || mapa[posx][posy] == 'a') {return 0;}

    return cont_local;
}

int main()
{
    int x;
    std::cin >> x;
    for (int i = 0; i < x; i ++)
    {
        int n,m;
        std:: cin >> n >> m;
        std::vector<std::string> mapa;
        for (int k = 0; k < n; k++) {std::cin >> mapa[i];}

    }
}
