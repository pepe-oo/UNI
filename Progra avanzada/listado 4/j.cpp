#include <ostream>
#include <sstream>
#include <iostream>

class Person
{
    private:
        int age;
    public: 
        Person(int Initialage) // metodo constructor
        {
            if (Initialage < 0)
            {
                age = 0;
                printf("Age is not valid, setting age to 0.\n");
            }
            else
            {
                age = Initialage;
            }
        }
        void yearPasses() {age++;}
        void amIOld()
        {
            if (age < 13) {std::cout << "You are young." << std::endl;}
            else if (age >= 13 && age < 18) {std::cout << "You are a teenager." << std::endl;}
            else {std::cout << "You are old." << std::endl;}
        }
};

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d",&a);
        Person p1(a);
        p1.amIOld();
        for(int i = 0; i < 3; i++) {p1.yearPasses();}
        p1.amIOld();
    }   
    return 0;
}