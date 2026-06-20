/* 
.push_back(x) mete un elemento a v 
.front() devuelve el primer valor de v (pos 0)
.back() devuelve el ultimo valor de v (pos -1)
.pop.bacK() elimina el ultimo valor de v
.size() retorna la cantidad de elementos de v
.empty retorna un bool si es que esta vacio o no
INT_MAX 
*/

//codigo para leer grafos
#include <iostream>
#include <vector>
#include <utility>
#include <climits>

int lista_grafo()
{
    unsigned n,m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<unsigned,unsigned>>> g(n + 1, std::vector<std::pair<unsigned,unsigned>>());
    for (unsigned i = 0; i < m; ++i)
    {
        unsigned n1, n2,p;
        std::cin >> n1 >> n2 >> p;
        g[n1].push_back(std::make_pair(n2,p));
        g[n2].push_back(std::make_pair(n1,p));
    }
}

int matriz_ady()
{
    unsigned n,m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matriz(n + 1,std::vector<int>(n + 1, __INT_MAX__));
    for (unsigned i = 0; i < m; ++i)
    {
        unsigned n1,n2;
        int w;
        matriz[n1][n2] = w;
        matriz[n2][n1] = w;
    }
}

int azucar_sintactico(std::vector<std::vector<std::pair<unsigned,unsigned>>> g)
{
    std::vector<int>::iterator it;
    for (it = g.begin(); it != g.end(); it++)
    for (auto v:g) // auto busca el tipo de dato que es g
}