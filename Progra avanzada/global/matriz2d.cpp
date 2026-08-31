class Matriz2D
{
    private:
        double **datos;
        int filas;
        int columnas;
    public:
        Matriz2D (int f, int c)
        {
            filas = f;
            columnas = c;
            datos = new double*[f];
            for (int i = 0; i < f; ++i)
            {
                datos[i] = new double[c]();
            }
        }
        ~Matriz2D()
        {
            for (int i = 0; i < filas; ++i)
            {
                delete[] datos[i];
            }
            delete[] datos;
        }
        Matriz2D& operator=(const Matriz2D&)
        {
            Matriz2D(this->Getfilas(),this->Getcols());
        }
        int Getfilas() {return filas;}
        int Getcols() {return columnas;}
        double& operator() (int i, int j)
        {
            return datos[i][j];
        }
        Matriz2D traspuesta()
        {
            Matriz2D(this->Getcols(),this->Getfilas());
        }
        Matriz2D operator+(const Matriz2D& o)
        {
            for (int i = 0; i < o.Getfilas(); ++i)
            {

            }
        } 
};