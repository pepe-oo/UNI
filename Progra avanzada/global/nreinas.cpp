#include <iostream>
#include <vector>

bool verificar (std::vector<std::vector<char>>& tablero, int f, int c, int max_c, int max_f)
{
    bool flag_h = true;
    bool flag_v = true;
    bool flag_d = true;
    for (int i = 0; i < max_c; ++i)
    {
        if (tablero[f][i] == 'x') {flag_h = false;}
    }
    for (int i = 0; i < max_f; ++i)
    {
        if (tablero[i][c] == 'x') {flag_v = false;}
    }
    for (int i = 0; i < max_c && i < max_f; ++i)
    {
        if (tablero[f + i][c + i] == 'x') {flag_d = false;}
    }
    for (int i = 0; (f - i >= 0) && (c - i >= 0); ++i)
    {
        if (tablero[f - i][c - i] == 'x') {flag_d = false;}
    }
    return flag_d && flag_h && flag_v;
}

int df [] = { -1 , 1 , 0 , 0};
int dc [] = {0 , 0 , -1 , 1};

void solve (int f, int c, int max_c, int max_f, std::vector<std::vector<char>>& tablero, int& cont)
{
    if (verificar(tablero, f ,c, max_c, max_f))
    {
        ++cont;
        tablero[f][c] == 'x';
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        int nueva_f = f + df[i];
        int nueva_c = c + dc[i];
        if (nueva_f >= 0 && nueva_f < max_f && nueva_c >= 0 && nueva_c < max_c)
        {
            if (tablero[nueva_f][nueva_c] == '.')
            {
                solve(nueva_f, nueva_c, max_c, max_f, tablero, cont);
            }
        }
    }
}