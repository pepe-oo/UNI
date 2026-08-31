#include <iostream>
#include <vector>

class Personajes
{
    public:
        std::string nombrepj;
        std::string dpto;
        std::string bebida;
        std::string party;
        Personajes (std::string nombre ,std::string depto, std::string drink, std::string p)
        {
            nombrepj = nombre;
            dpto = depto;
            bebida = drink;
            party = p;
        }
};

bool validar (const std::vector<Personajes>& comb, Personajes pj)
{
    std::vector<std::string> dptos {"Informatica", "Electronica", "Mecanica", "Quimica", "Fisica"};
    std::vector<std::string> bebidas {"Eggos", "BilzYPap"};
    
    // 1. Requisitos individuales mínimos (Early Exit)
    bool depto_valido = false;
    for (int i = 0; i < 5; ++i)
    {
        if (dptos[i] == pj.dpto) { depto_valido = true; }
    }
    if (!depto_valido) { return false; }
    
    if (pj.bebida != bebidas[0] && pj.bebida != bebidas[1]) { return false; }
    
    // 2. Convivencia de facciones políticas
    if (pj.party == "Neutral") { return true; } // Los Neutral pueden convivir con cualquiera
    
    for (size_t i = 0; i < comb.size(); ++i)
    {
        // Si el candidato es TheParty, no puede haber nadie de UpsideDown (y viceversa)
        if (pj.party == "TheParty" && comb[i].party == "UpsideDown") { return false; }
        if (pj.party == "UpsideDown" && comb[i].party == "TheParty") { return false; }
    }
    
    return true; // Superó todos los filtros sin conflictos
}
void solve (std::vector<Personajes>& comb, std::vector<bool>& usado, int n, int& cont, const std::vector<Personajes> opciones,int m,int inicio)
{
    if (comb.size() > n)
    {
        return;
    }
    for (int i = inicio; i < m; ++i)
    {
        if (!usado[i])
        {
            if(!comb.empty() && !validar(comb,opciones[i])) continue;
            usado[i] = true;
            comb.push_back(opciones[i]);
            ++cont;
            solve(comb,usado,n,cont,opciones,m,i + 1);
            comb.pop_back();
            usado[i] = false;
        }
    }
}

int main()
{
    int m,k;
    std::cin >> m >> k;
    std::vector<Personajes> listapersonajes;
    for (int i = 0; i < m; ++i)
    {
        std::string n,d,b,p;
        std::cin >> n >> d >> b >> p;
        Personajes nuevopj(n,d,b,p);
        listapersonajes.push_back(nuevopj);
    }
    std::vector<Personajes> comb;
    std::vector<bool> usado (m,false);
    int cont = 0;
    int inicio = 0;
    solve(comb,usado,k,cont,listapersonajes,m, inicio);
    std::cout << cont << std::endl;
    return 0;
}