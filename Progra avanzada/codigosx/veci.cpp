#include <iostream>
#include <vector>
#include <string>

using namespace std;

int valido(vector<int> &obj, vector<int> &v)
{
    if (obj.size() > v.size()) { return 2; }
    
    vector<bool> usados(v.size(), false); 
    
    for (int i = 0; i < obj.size(); i++)
    {
        bool encontrado = false; // <-- CORRECCIÓN 1: Se reinicia para cada elemento de 'obj'
        
        for (int k = 0; k < v.size(); ++k)
        {
            // CORRECCIÓN 2: El elemento debe coincidir Y NO haber sido usado ya
            if (obj[i] == v[k] && !usados[k]) 
            {
                encontrado = true;
                usados[k] = true; // Lo marcamos
                break;            // Ya lo encontramos, saltamos al siguiente elemento de 'obj'
            }
        }
        if (!encontrado) { return 1; } // Si un elemento de 'obj' no se halló en 'v'
    }
    
    // Si el tamaño es igual y encontramos todos, es una permutación perfecta
    if (obj.size() == v.size()) { return 0; }
    
    // Si encontramos todos los de 'obj' pero 'obj' aún es más pequeño que 'v' (está incompleto)
    return 1; 
}

void solve (vector<int>& comb, vector<bool>& usado,const int n, vector<int>& v)
{
    if (valido(comb, v) == 2) 
    {
        cout << 0;
        return;
    }
    if(valido(comb,v) == 0)
    {
        for (int i = 0; i < comb.size(); ++i)
        {
            cout << comb[i];
        }
        cout << endl;
        return; 
    }
    for (int i = 0; i < n; ++i)
    {
        if (!usado[i])
        {
            usado[i] = true;
            comb.push_back(v[i]);
            solve(comb,usado,n,v);
            comb.pop_back();
            usado[i] = false;
        }
    }
}

int main()
{
    string s;
    cin >> s;
    vector<int> v;
    for (size_t i = 0; i < s.size(); ++i)
    {
        v.push_back(s[i] - '0');
    }
    vector<int> comb;
    vector<bool> usado(v.size(), false); 
    int x = s.size();
    solve(comb,usado,x,v);
    return 0;
}