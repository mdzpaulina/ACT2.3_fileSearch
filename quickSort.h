#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include <string>
using namespace std;

//Clase para quickSort
class QuickSort{
    public:
    static void quickSort(vector<string>& arr); // Inicializa quickSort
    static int partition(vector<string>& arr, int low, int high); // Llamado del quickSort para la partición
    static void quickSort(vector<string>& arr, int low, int high); // Llamado que establece límites
};

// Declarar la función convertirFecha
string convertirFecha(const string& line);

#endif
