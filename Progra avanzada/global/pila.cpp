#include <iostream>

class PilaInt
{
    private:
        int *datos;
        int tope;
        int capacidad;
    public:
        PilaInt()
        {
            capacidad = 4;
            tope = 0;
            datos = new int[capacidad];
        }
        ~PilaInt()
        {
            delete[] datos;
        }
        PilaInt (const PilaInt& otro)
        {
            capacidad = otro.capacidad;
            datos = new int[capacidad];
            tope = otro.tope;
            capacidad = otro.capacidad;
            for (int i = 0; i < tope; ++i)
            {
                datos[i] = otro.datos[i];
            }
        }
        void push (int val)
        {
            if (tope == capacidad)
            {
                capacidad *= 2;
                int *copia = new int[capacidad];
                for (int i = 0; i < tope; ++i)
                {
                    copia[i] = datos[i];
                }
                delete[] datos;
                datos = copia;
            }
            datos[tope] = val;
            ++tope;
        }
        int pop()
        {
            --tope;
            int out = datos[tope];
            datos[tope] = 0;
            return out;
        }
        int peek() {return datos[tope - 1];}
        bool isEmpty() const
        {
            return tope == 0;
        }
        int size() const {return tope;}
        friend std::ostream& operator<<(std::ostream& out, PilaInt& o)
        {
            out << '[';
            for (int i = 0; i < o.tope; ++i) 
            {
                out << o.datos[i];
                if (i < o.tope - 1) {out << ',';}
            }
            out << ']';
            return out;
        }
        PilaInt& operator=(const PilaInt& otro)
        {
            if (this != &otro) 
            {
                delete[] datos; 
                capacidad = otro.capacidad;
                tope = otro.tope;
                datos = new int[capacidad];
                for (int i = 0; i < tope; ++i) {
                    datos[i] = otro.datos[i];
                }
            }
            return *this; 
        }
};