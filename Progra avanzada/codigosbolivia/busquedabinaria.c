#include <stdio.h>

int bbinaria(int *v,int e, int l,int r)
{
    if (l == r)
    {
        if (v[l] == e)
        {
            return l;
        }
        else
        {
            return -1;
        }
    }
    int mitad = (l+r)/2;
    if(v[mitad] == e) return mitad;
    else if(v[mitad] > e) return (bbinaria(v,e,l,mitad-1));
    else return (bbinaria(v,e,mitad+1,r));
}