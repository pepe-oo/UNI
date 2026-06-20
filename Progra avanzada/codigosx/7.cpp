#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve (vector<int>& perm, vector<bool>& usados, int agregados, int n)
{
    if  (agregados == n)
    {
        for (int i = 0; i < n; ++i) { cout << perm[i];}
        cout << endl;
    }
    for (int i = 1; i < n + 1; ++i)
    {
        if (!usados[i])
        {
            usados[i] = true;
            perm.push_back(i);
            solve (perm, usados,agregados + 1, n);
            perm.pop_back();
            usados[i] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<bool> usados (n + 1);
    vector<int> perm;
    solve (perm,usados,0,n);
}