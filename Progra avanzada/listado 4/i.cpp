#include <iostream>
#include <sstream>
#include <string>
#include <sstream>

class Student
{
    private:
        int age;
        std::string first_name;
        std::string last_name;
        int standard;
    public:
        void set_age (int a)
        {
            age = a;
        }
        void set_first_name (std::string a)
        {
            first_name = a;
        }
        void set_last_name (std::string a)
        {
            last_name = a;
        }
        void set_standard (int a)
        {
            standard = a;
        }
        int get_age ()
        {
            return age;
        }
        std::string get_first_name()
        {
            return first_name;
        }
        std::string get_last_name()
        {
            return last_name;
        }
        int get_standard()
        {
            return standard;
        }
        std::string to_string()
        {
            std::stringstream out;
            out << age << "," << first_name << "," << last_name << "," << standard;
            return out.str();
        }
};

int main() {
    int edad, grado;
    std::string nombre, apellido;
    std::cin >> edad;
    std::cin >> nombre;
    std::cin >> apellido;
    std::cin >> grado;
    Student estudiante1;
    estudiante1.set_age(edad);
    estudiante1.set_first_name(nombre);
    estudiante1.set_last_name(apellido);
    estudiante1.set_standard(grado);
    std::cout << estudiante1.get_age() << "\n";
    std::cout << estudiante1.get_last_name() << ", " << estudiante1.get_first_name() << "\n";
    std::cout << estudiante1.get_standard() << "\n";
    std::cout << "\n";
    std::cout << estudiante1.to_string() << "\n";
    return 0;
}