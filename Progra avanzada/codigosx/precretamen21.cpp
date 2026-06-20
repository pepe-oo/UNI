#include <iostream>
#include <vector>

using namespace std;

class Student 
{
    private:
        vector<int> scores;
    public:
        void input()
        {
            for (int i = 0; i < 5; ++i)
            {
                int n;
                cin >> n;
                scores.push_back(n);
            }
        }
        int calculateTotalScore()
        {
            int out = 0;
            for (int i = 0; i < 5; ++i) {out += scores[i];}
            return out;
        }
};

int main()
{
    cout << "anacehi";
}