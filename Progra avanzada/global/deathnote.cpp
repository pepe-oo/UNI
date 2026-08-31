#include <iostream>
#include <vector>
#include <string>

class Personaje
{
    public:
        std::string nombre;
        int habilidad;
        int riesgo;
        Personaje (std::string nom, int hab, int rie)
        {
            nombre = nom;
            habilidad = hab;
            riesgo = rie;
        }
};

int max = -1;

int suma(std::vector<Personaje>& comb)
{
    int out = 0;
    for (size_t i = 0; i < comb.size(); ++i)
    {
        out += comb[i].habilidad;
    }
    return out;
}

int suma_riesgo(std::vector<Personaje>& comb)
{
    int out = 0;
    for (size_t i = 0; i < comb.size(); ++i)
    {
        out += comb[i].riesgo;
    }
    return out;
}

void solve (int& max, const std::vector<Personaje>& opciones, std::vector<Personaje>& comb, int pos, int n, int m, int k)
{
    if (comb.size() == m)
    {
        if (suma(comb) > max) {max = suma(comb);}
        return;
    }
    if (pos == n) {return;}
    if (suma_riesgo(comb) > k) {return;}
    if (suma_riesgo(comb) + opciones[pos].riesgo < k)
    {
        comb.push_back(opciones[pos]);
        solve (max, opciones, comb, pos + 1, n ,m ,k);
        comb.pop_back();
    }
    solve (max, opciones, comb, pos + 1, n ,m ,k);
}

int main ()
{
    int n,m,k;
    std::cin >> n >> m >> k;
    std::vector<Personaje> opciones;
    for (int i = 0; i < n; ++i)
    {
        std::string nombre;
        int h,r;
        std::cin >> nombre >> h >> r;
        Personaje pj (nombre,h,r);
        opciones.push_back(pj);
    }  
    std::vector<Personaje> comb;
    solve (max, opciones, comb, 0, n ,m ,k);
    std::cout << max << std::endl;
    return 0;
}