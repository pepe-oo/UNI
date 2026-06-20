#include <iostream>
#include <vector>

using namespace std;

void solve (int pos, int n, vector<int>& comb, const vector<int>& v)
{
    if (comb.size() == 2 && (comb[0] + comb[1] == 10))
    {
        for (int i = 0; i < 2; ++i) {cout << comb[i] << ' ';}
        cout << endl;
        return;
    }
    else if (pos == n) {return;}
    else if (comb.size() > 2) {return;}
    if (comb.size() < 2)
    {
        comb.push_back(v[pos]);
        solve(pos + 1, n ,comb , v);
        comb.pop_back();
    }
    solve (pos + 1, n, comb ,v);
}

int main()
{
    vector<int> v;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        v.push_back(x);
    }
    vector<int> comb;
    solve(0,n,comb,v);
}