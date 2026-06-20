#ifndef alexissanchezdelcacho_HH
#define alexissanchezdelcacho_HH

#include <map>
#include <vector>
#include <string>

#include "Jugador.h"
#include "Marcador.h"
#include "Actuacion.h"

class alexissanchezdelcacho : public Jugador
{
    private: 
        std::string nombre;
    private:
        alexissanchezdelcacho (std::string nom = "alexissanchezdelcacho") : Jugador(nom)
        {
            nombre = "Pedro Ortiz";
        }
        int jugar (const std::map<std::string, Marcador> &puntos, const )
};

#endif;