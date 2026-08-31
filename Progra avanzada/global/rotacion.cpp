#include <iostream>
#include <vector>

int main() 
{
    int n, m_cols;
    std::cin >> n >> m_cols; // N filas, M columnas
    
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m_cols));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m_cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // 1. Definir los límites basados en N y M
    int inicio_fila = 0;
    int fin_fila = n - 1;
    int inicio_col = 0;
    int fin_col = m_cols - 1;

    std::cout << "Recorrido en espiral (N x M): ";

    // El bucle corre mientras las paredes no se crucen
    while (inicio_fila <= fin_fila && inicio_col <= fin_col) 
    {
        // Paso 1: Izquierda a Derecha
        for (int j = inicio_col; j <= fin_col; ++j) {
            std::cout << matrix[inicio_fila][j] << " ";
        }
        inicio_fila++; // Movemos el límite superior hacia abajo

        // Paso 2: Arriba a Abajo
        for (int i = inicio_fila; i <= fin_fila; ++i) {
            std::cout << matrix[i][fin_col] << " ";
        }
        fin_col--; // Movemos el límite derecho hacia la izquierda

        // Paso 3: Derecha a Izquierda (¡Aquí el IF es vital!)
        if (inicio_fila <= fin_fila) {
            for (int j = fin_col; j >= inicio_col; --j) {
                std::cout << matrix[fin_fila][j] << " ";
            }
            fin_fila--; // Movemos el límite inferior hacia arriba
        }

        // Paso 4: Abajo a Arriba (¡Aquí el IF también es vital!)
        if (inicio_col <= fin_col) {
            for (int i = fin_fila; i >= inicio_fila; --i) {
                std::cout << matrix[i][inicio_col] << " ";
            }
            inicio_col++; // Movemos el límite izquierdo hacia la derecha
        }
    }
    std::cout << "\n";

    return 0;
}