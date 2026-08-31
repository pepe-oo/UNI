#include <iostream>

typedef int tele;

struct tnodo
{   
    tele info;
    tnodo* sig;
};

class tlista
{
    private:
        int pos;
        int length;
        tnodo *head;
        tnodo *curr;
        tnodo *tail;
    public:
        void append (int value)
        {
            
        }
        int getvaluepos (int pos1)
        {
            if ( 0 > pos1 || pos1 >= length) {return -1;}
            if (pos1 == pos) {return curr->sig->info;}
            if (pos1 > pos) 
            {
                for (int i = 0; i < pos1 - pos; ++i)
                {
                    
                }
            }
        }
};

struct tNodo_doble
{
    int info;
    tNodo_doble *ant;
    tNodo_doble *sig;
};


class tlista_doble_enlazada
{
    private:
        unsigned int pos;
        unsigned int length;
        tNodo_doble *head;
        tNodo_doble *curr;
        tNodo_doble *tail;
    public:

};

class bivector
{
    int len;
    bool vector[500];
    public:
        int select(int j) {}
        int member (int j) {}
        void interseccion (bivector *a, bivector *b)
        {
            bool[500] out;  
            if (a->len > b->len)
            {
                int pos = b->select(1);
                while (pos != b->len)
                {
                    if (b->member(pos) == a->member(pos))
                    {
                        c->member
                    }
                }
            }
        }
};

class polinomio {
    private:
        monomio *P;
        int grado; // grado del polinomio
    public:
        int getGrado();
        float getMonomio(int e);
        void setMonomio(float c, int e);
        polinomio sumarPolinomios(polinomio *p1, polinomio *p2)
        {
            for (int i = 0; i < grado; ++i)
        }
};