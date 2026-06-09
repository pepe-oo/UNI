#include <iostream>

class vector
{
    int *v;
    int sz;
    int cap;
public:
    vector()
    {
        sz = 4;
        cap = 10;
        v = new int[cap];
        v[0] = 1;
        v[1] = 2;
        v[2] = 44;
        v[3] = 5;
    }

    ~vector()
    {
        delete[] v; 
    }
    int getit (int i) const
    {
        return v[i];
    };
    int getsz() const
    {
        return sz;
    }
}; 

std::ostream& operator<<(std::ostream&out,const vector& v)
{
    out << "El vector v es del peru:";
    for (int i = 0; i < v.getsz(); i++)
    {
        out << v.getit(i) << " ";
    }
    out << "\n";
    return out;
}

int main()
{
    vector v1;
    std::cout << v1;
    return 0;
}