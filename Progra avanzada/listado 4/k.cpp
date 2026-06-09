#include <ostream>
#include <sstream>

class Student
{
    private:
        int score[5];
    public:
        void input()
        {
            for (int i = 0; i < 5; i++)
            {
                scanf("%d", &score[i]);
            }
        }
        int calculateTotalScore()
        {
            int out = 0;
            for (int i = 0; i < 5; i++) {out += score[i];}
            return out;
        }
};

int main()
{
    
}