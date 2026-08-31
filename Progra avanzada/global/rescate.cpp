#include <iostream>
#include <string>
#include <vector>

class Persona
{
    public:
        std::string nombre;
        int habilidad;
        int costo;
        Persona (std::string n, int h, int c) 
        {
            nombre = n;
            habilidad = h;
            costo = c;
        }
};

int max = -1;

int suma (std::vector<Persona> comb)
{
    int out = 0;
    for (size_t i = 0; i < comb.size(); ++i)
    {
        out += comb[i].habilidad;
    }
    return out;
}

int suma_costo (std::vector<Persona> comb)
{
    int out = 0;
    for (size_t i = 0; i < comb.size(); ++i)
    {
        out += comb[i].costo;
    }
    return out;
}

void solve (int pos, int n, std::vector<Persona>& comb, const std::vector<Persona>& opciones, int costo_max, int cantidad)
{
    if (comb.size() == cantidad)
    {
        if(suma_costo(comb) < costo_max && suma(comb) > max) 
        {
            max = suma(comb);
        }
        return;
    }
    if (pos == n) {return;}
    if (suma_costo(comb) + opciones[pos].costo < costo_max)
    {
        comb.push_back(opciones[pos]);
        solve (pos + 1, n, comb, opciones, costo_max, cantidad);
        comb.pop_back();
    }
    solve (pos + 1, n, comb, opciones, costo_max, cantidad);
}

int main()
{
    int n, cantidad, costo_max;
    std::cin >> n >> cantidad >> costo_max;
    std::vector<Persona> opciones;
    for (int i = 0; i < n; ++i)
    {
        std::string nombre;
        int h, c;
        std::cin >> nombre >> h >> c;
        Persona pj (nombre,h,c);
        opciones.push_back(pj);
    }
    std::vector<Persona> comb;
    solve (0, n, comb, opciones, costo_max, cantidad);
    std::cout << max << std::endl;
    return 0;
}