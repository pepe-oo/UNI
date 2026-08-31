#include <iostream>
#include <ostream>
#include <string>   

class Contacto
{
    private:
        char nombre[50];
        char telefono[15];
        char email[50];
    public:
        Contacto (char n[50], char t[15], char e[50])
        {
            for (int i = 0; i < 50; ++i) {nombre[i] = n[i];}
            for (int i = 0; i < 15; ++i) {telefono[i] = t[i];}
            for (int i = 0; i < 50; ++i) {email[i] = e[i];}
        }
        bool operator==(const Contacto& otro) const
        {
            return otro.nombre == this->nombre;
        }
        friend std::ostream& operator<< (std::ostream out, const Contacto& otro)
        {
            out << otro.nombre << " | " << otro.telefono << " | " << otro.email << std::endl;
            return out;
        }
};

class Agenda
{
    private:
        Contacto contactos[50];
        int num_contactos;
    public:
        
};