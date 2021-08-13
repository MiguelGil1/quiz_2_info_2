#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char cadena[50];
    char cadena_numeros[50];
    char cadena_caracteres[50];
    cout << "El siguiente programa separa los numeros ingresados de las letras:" << endl;
    cout << "Ingrese la cadena de caracteres y numeros: ";
    cin >> cadena;
    int numeros = 0;
    int chars = 0;
    for(int i = 0; i < int(strlen(cadena)); i++){
        if(cadena[i] >= 48 and cadena[i] <= 57){
            cadena_numeros[numeros] = cadena[i];
            numeros++;
        }else{
            cadena_caracteres[chars] = cadena[i];
            chars++;
        }
    }
    cout << "Cadena original: " << cadena << endl;
    cout << "Texto: " << cadena_caracteres << endl;
    cout << "Numero: " << cadena_numeros << endl;
    return 0;
}
