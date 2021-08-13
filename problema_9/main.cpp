#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    char *numeros, digito;
    int longitud, n;
    cout << "Ingrese la cantidad de digitos: ";
    cin >> longitud;
    numeros = new char [longitud];
    for(int i = 0; i < longitud; i++){
        cout << "Ingrese el digito de la posicon [" << i+1 << "]: ";
        cin >> digito;
        numeros[i] = digito;
    }
    cout << "Ingrese en la cantidad de digitos que desea segmentar la cadena: ";
    cin >> n;
    while(n > longitud){
        cout << "Segmentacion fuera de rango." << endl;
        cout << "Ingrese en la cantidad de digitos que desea segmentar la cadena: ";
        cin >> n;
    }
    int tamanio = 0;
    int suma_tmp = 0;
    if(longitud%n == 0){
        int suma = 0;
        for(int i = 0; i < longitud; i+=n){
            suma_tmp = 0;
            int cantidad = n-1;
            for(int j = i; j < (i+n); j++){
                suma_tmp += (numeros[j] - 48) * (pow(10,cantidad));
                cantidad -= 1;
            }
            suma += suma_tmp;
        }
        cout << "Original: ";
        for(int i = 0; i < longitud; i++){
            cout << numeros[i];
        }
        cout << endl;
        cout << "Suma: " << suma << endl;
    }else{
        int suma = 0;
        for (int i = longitud - 1; i >=0; i-=n){
            int contador = 1;
            suma_tmp = 0;
            if((i+1) - n > 0){
                for(int j = i; j > i-n; j--){
                    suma_tmp += (numeros[j] - 48) * contador;
                    contador *= 10;
                }
                suma += suma_tmp;
            }else{
                for(int j = i; j >= 0 ; j--){
                    suma_tmp += (numeros[j] - 48) * contador;
                    contador *= 10;
                }
                suma += suma_tmp;
            }
        }
        cout << "Original: ";
        for(int i = 0; i < longitud; i++){
            cout << numeros[i];
        }
        cout << endl;
        cout << "Suma: " << suma << endl;
    }
    delete[] numeros;
    return 0;
}
