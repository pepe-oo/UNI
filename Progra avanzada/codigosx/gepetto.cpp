#include <iostream>
#include <vector>

using namespace std;

bool valido (int pos, vector <int >& comb_actual,vector<vector<int>>& rest)
{
    
    for (size_t i = 0; i < rest.size(); ++i)
    {
        for (size_t k = 0; k < comb_actual.size(); ++k)
        {
            if ((comb_actual[k] == rest[i][0] && pos == rest[i][1]) || (comb_actual[k] == rest[i][1] && pos == rest[i][0])) {return false;}
        }
    }
    return true;
}

void solve (int pos , int n , vector <int >& comb_actual, int & cont, vector<vector<int>>& rest)
{
    if (pos == n + 1)
    {
        ++cont;
        return;
    }
    if (valido(pos,comb_actual,rest))
    {
        comb_actual.push_back(pos);
        solve(pos + 1, n, comb_actual,cont,rest);
        comb_actual.pop_back();
    }
    solve (pos + 1, n,comb_actual,cont,rest);
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> rest(m, vector<int>());
    for (int i = 0; i < m; ++i)
    {
        int a,b;
        cin >> a >> b;
        rest[i].push_back(a);
        rest[i].push_back(b);
    }
    vector<int> comb;
    int cont = 0;
    solve (1,n,comb,cont,rest);
    cout << cont << endl;
    return 0;
}