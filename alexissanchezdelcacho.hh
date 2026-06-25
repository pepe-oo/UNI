#ifndef alexissanchezdelcacho_HH
#define alexissanchezdelcacho_HH

#include <map>
#include <vector>
#include <string>
#include <utility>

#include "Jugador.h"
#include "Marcador.h"
#include "Actuacion.h"

class alexissanchezdelcacho : public Jugador
{
    private: 
        std::string nombre;
        const std::vector<std::string> juegosposibles = {
        "balas", "tontos", "trenes", "cuadras", "quinas", "senas",
        "escalera", "full", "poker", "grande", "grande2"
        };
        const std::map<std::string,int> puntaje_maximo = {
            {"balas", 5}, {"tontos", 10}, {"trenes", 15},
            {"cuadras", 20}, {"quinas", 25}, {"senas", 30},
            {"escalera", 25}, {"full", 35}, {"poker", 45},
            {"grande", 50}, {"grande2", 50}
        };
        const std::vector<std::string> ultimo_recurso = {
        "grande2", "grande", "poker", "full", "escalera",
        "balas", "tontos", "trenes", "cuadras", "quinas", "senas"
        };  
        int evaluardados(const std::vector<int>& dados, const std::vector<int>& indices, const std::map<std::string, Marcador>& puntos)
        {
            std::map<int,int> jugada;
            for (int i = 0; i < 5; ++i)
            {
                bool flag = false;
                for (size_t k = 0; k < indices.size(); ++k)
                {
                    if (i == indices[k]) {flag = true; break;}
                }
                if (!flag) {++jugada[dados[i]];}
            }
            int puntaje = 0;
            const std::vector<std::string> nombres_num = {"balas", "tontos", "trenes", "cuadras", "quinas", "senas"};
            for (auto it = jugada.begin(); it != jugada.end(); ++it)
            {
                int numero = it->first;
                int cantidad = it->second;
                if (cantidad >= 2)
                {
                    int puntos_min = cantidad * numero;
                    if (numero >= 1 && numero <= 6)
                    {
                        std::string nombre_jugada = nombres_num[numero -1];
                        if (puntos.at(nombre).puntajes.at(nombre_jugada) == -1) {puntaje += puntos_min * 50;}
                        else {puntaje += puntos_min;}
                    }
                }
            }
            return puntaje;
        }
        bool validar (const std::string& jugada, const std::map<std::string, Marcador>& puntos)
        {
            return (puntos.at(nombre).puntajes.at(jugada)) == -1;
        }
    public:
        alexissanchezdelcacho(std::string nom = "alexissanchezdelcacho") : Jugador(nom)
        {
            nombre = nom; 
        }
        std::string Getnombre() const {return nombre;}
        int jugar (
            const std::map<std::string, Marcador> &puntos, 
            const std::vector<Actuacion>& actuaciones, 
            const std::vector<int>& dados, 
            const Anotacion& resultadoPrevio) override
        {
            int size = actuaciones.size();
            std::pair <int, int> max = {-1,-1};
            for (int i = 0; i < size; ++i)
            {
                if (actuaciones[i].accion == "dormida" || 
                    (actuaciones[i].accion == "anotar" && (actuaciones[i].anotacion.juego == "grande" || actuaciones[i].anotacion.juego == "grande2"))) 
                {
                    return i;
                } 
                if ((actuaciones[i].anotacion.juego == "poker" && actuaciones[i].anotacion.puntos == 45) && validar ("poker",puntos)) {return i;}
                if ((actuaciones[i].anotacion.juego == "full" && actuaciones[i].anotacion.puntos == 35) && validar ("full",puntos)) {return i;}
                if ((actuaciones[i].anotacion.juego == "escalera" && actuaciones[i].anotacion.puntos == 25) && validar ("escalera",puntos)) {return i;}
            }
            bool solotachar = true;
            for (int i = 0; i < size; ++i) 
            {
                if (actuaciones[i].accion == "anotar" || actuaciones[i].accion == "lanzar" || actuaciones[i].accion == "sobre") 
                {
                    solotachar = false;
                    break;
                }
            }
            if (solotachar)
            {
                for (size_t k = 0; k < juegosposibles.size(); ++k) 
                {
                    if (puntos.at(nombre).puntajes.at(juegosposibles[k]) == -1) 
                    {
                        for (int i = 0; i < size; ++i) 
                        {
                            if (actuaciones[i].accion == "tachar" && actuaciones[i].anotacion.juego == juegosposibles[k]) {return i;}
                        }
                    }
                }
            }
            int mejor_lanzamiento = -1;
            int mejor_puntaje = -1;
            for (int i = 0; i < size; ++i)
            {
                if (actuaciones[i].accion == "lanzar")
                {
                    int ptos = evaluardados (dados,actuaciones[i].indiceDados,puntos);
                    if (ptos > mejor_puntaje) 
                    {
                        mejor_puntaje = ptos;
                        mejor_lanzamiento = i;
                    }
                }
            }
            if (mejor_lanzamiento != -1 && mejor_puntaje > 0) {return mejor_lanzamiento;}
            int turno = 0;
            for (const auto& juego : juegosposibles) 
            {
                if (puntos.at(nombre).puntajes.at(juego) != -1) {turno++;}
            }
            if (turno <= 4)
            {
                for (int i = 0; i < size; ++i)
                {
                    if (actuaciones[i].accion == "anotar" && actuaciones[i].anotacion.puntos >= 15) {return i;}
                }
                for (int i = 0; i < size; ++i)
                {
                    if (actuaciones[i].accion == "lanzar" && actuaciones[i].indiceDados.size() == 5) {return i;}
                }
            }
            if (turno > 4 && turno <= 8)
            {
                for (int i = 0; i < size; ++i)
                {
                    if (actuaciones[i].accion == "anotar")
                    {
                        if (actuaciones[i].anotacion.juego == "poker" && actuaciones[i].anotacion.puntos > 0) {return i;}
                        if (actuaciones[i].anotacion.juego == "full" && actuaciones[i].anotacion.puntos > 0) {return i;}
                        if (actuaciones[i].anotacion.juego == "escalera" && actuaciones[i].anotacion.puntos > 0) {return i;}
                        if (actuaciones[i].anotacion.puntos > max.second) {max = std::make_pair (i,actuaciones[i].anotacion.puntos);}
                    }
                }
                if (max.second >= 0) {return max.first;}
                for (int i = 0; i < size; ++i)
                {
                    if (actuaciones[i].accion == "tachar" && actuaciones[i].anotacion.juego == "grande") {return i;}
                    if (actuaciones[i].accion == "tachar" && actuaciones[i].anotacion.juego == "grande2") {return i;}
                }
                for (size_t k = 0; k < juegosposibles.size(); ++k) 
                {
                    if (puntos.at(nombre).puntajes.at(juegosposibles[k]) == -1) 
                    {
                        for (int i = 0; i < size; ++i) 
                        {
                            if (actuaciones[i].accion == "tachar" && actuaciones[i].anotacion.juego == juegosposibles[k]) {return i;}
                        }
                    }
                }
            }
            else
            {
                std::vector<std::string> jugadas_disp;
                for (auto it = puntos.at(nombre).puntajes.begin(); it != puntos.at(nombre).puntajes.end(); ++it)
                {
                    if (it->second == -1) {jugadas_disp.push_back(it->first);}
                }
                for (int i = 0; i < size; ++i)
                {
                    for (size_t k = 0; k < jugadas_disp.size(); ++k)
                    {
                        if (actuaciones[i].accion == "anotar" &&
                            actuaciones[i].anotacion.juego == jugadas_disp[k] && 
                            puntaje_maximo.at(jugadas_disp[k]) / 2 <= actuaciones[i].anotacion.puntos && 
                            actuaciones[i].anotacion.puntos > max.second)
                        {max = std::make_pair(i, actuaciones[i].anotacion.puntos);}
                    }
                }
                if (max.second != -1) {return max.first;}
                for (size_t k = 0; k < ultimo_recurso.size(); ++k) 
                {
                    if (puntos.at(nombre).puntajes.at(ultimo_recurso[k]) == -1) 
                    {
                        for (int i = 0; i < size; ++i) 
                        {
                            if (actuaciones[i].accion == "tachar" && actuaciones[i].anotacion.juego == juegosposibles[k]) {return i;}
                        }
                    }
                }
            }
            for (int i = 0; i < size; ++i) 
            {
                if (actuaciones[i].accion == "anotar" || actuaciones[i].accion == "sobre") {return i;}
            }
            return 0;
        }
};

#endif