#include <iostream>
#include <vector>
#include <string>

class Personaje
{
    public:
        std::string nombre;
        int poder;
        int ki;
        Personaje (std::string nom, int p, int k)
        {
            nombre = nom;
            poder = p;
            ki = k;
        }
};

int max = -1;

bool validar (int m, int pos,std::vector<Personaje>& comb, const std::vector<Personaje>& opciones )
{
    int x = 0;
    for (size_t i = 0; i < comb.size(); ++i) {x += comb[i].ki;}
    x += opciones[pos].ki;
    if (m >= x) {return true;} 
    return false;
}

void solve (int pos, int n, std::vector<Personaje>& comb, const std::vector<Personaje>& opciones, int& max, int m)
{
    if (pos == opciones.size())
    {
        if (comb.size() == n)
        {
            int x = 0;
            for (int i = 0; i < n; ++i) {
                x += comb[i].poder;
            }
            if (x > max) {max = x;}
        }
        return;
    }
    
    if (validar(m,pos,comb,opciones))
    {
        comb.push_back(opciones[pos]);
        solve(pos + 1,n,comb,opciones,max,m);
        comb.pop_back();
    }
    solve(pos + 1,n,comb,opciones,max,m);
}

int main ()
{
    std::vector<Personaje> listapj;
    int n, m, maxki;
    std::cin >> n >> m >> maxki;
    for (int i = 0; i < n; ++i)
    {
        std::string nombre;
        int poder;
        int ki;
        std:: cin >> nombre >> poder >> ki;
        Personaje pj (nombre,poder,ki);
        listapj.push_back(pj);
    }
    std::vector<Personaje> comb;
    solve(0,m,comb,listapj,max,maxki);
    std::cout << max << std::endl;
    return 0;
}