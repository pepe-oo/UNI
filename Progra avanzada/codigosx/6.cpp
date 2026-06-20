#include <iostream>
#include <vector>
#include <string>
#include <utility>

bool valido (const std::string& col1, const std::string& col2, const std::vector<std::pair<std::string, std::string>>& rest)
{
    std::pair<std::string, std::string> obj = {col1,col2};
    for (size_t i = 0; i < rest.size(); ++i)
    {
        if (rest[i] == obj) {return false;}
    }
    return true;
}



void solve(std::vector<std::string>& comb, std::vector<bool>& usado, const int& n, int& cont, const std::vector<std::string>& v, const std::vector<std::pair<std::string, std::string>>& rest,std::vector<std::string>& favorito, bool& encontrado_favorito) // <--- RECÍBELO AQUÍbool& encontrado_favorito)             // <--- RECÍBELO AQUÍ
{
    if (comb.size() == n)
    {
        ++cont;
        if (!encontrado_favorito)
        {
            favorito = comb;
            encontrado_favorito = true;
        }
        return;
    }
    
    // CORRECCIÓN IMPORTANTE: El bucle debe ir hasta 'n'
    // Si tienes N elementos, los índices son 0 a n-1. 
    // Tu código decía 'i < n - 1', lo que ignoraba el último elemento.
    for (int i = 0; i < n; ++i) 
    {
        if (!usado[i])
        {
            if (!comb.empty() && !valido(comb.back(), v[i], rest)) { continue; }
            
            usado[i] = true;
            comb.push_back(v[i]);
            solve(comb, usado, n, cont, v, rest, favorito, encontrado_favorito); // Pasa los nuevos argumentos
            comb.pop_back();
            usado[i] = false;
        }
    }
}
int main() {
    // Optimización de E/S para concursos de programación
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (!(std::cin >> t)) return 0; // Lee cantidad de casos de prueba
    std::vector<std::string> favorito;
    bool encontrado_favorito = false;
    while (t--) {
        int n;
        std::cin >> n;
        
        // v: colores ordenados por preferencia (la entrada ya los da así)
        std::vector<std::string> v(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> v[i];
        }
        
        int m;
        std::cin >> m;
        
        // rest: parejas prohibidas
        std::vector<std::pair<std::string, std::string>> rest;
        for (int i = 0; i < m; ++i) {
            int id1, id2; 
            std::cin >> id1 >> id2;
            // Ajuste a base 0:
            rest.push_back({std::to_string(id1 - 1), std::to_string(id2 - 1)});
            rest.push_back({std::to_string(id2 - 1), std::to_string(id1 - 1)});
        }
        // Estructuras de control para el Backtracking
        std::vector<std::string> comb;
        std::vector<bool> usado(n, false);
        int cont = 0;
        encontrado_favorito = false; // Variable global reset
        favorito.clear();            // Vector global reset
        
        // Ejecución
        solve(comb, usado, n, cont, v, rest,favorito,encontrado_favorito);
        
        // Salida
        std::cout << cont << "\n";
        
        // Imprimir favorito (con el formato correcto de espacios)
        for (size_t i = 0; i < favorito.size(); ++i) {
            std::cout << favorito[i] << (i == favorito.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    
    return 0;
}