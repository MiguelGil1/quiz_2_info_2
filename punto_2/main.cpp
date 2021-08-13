#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
/*
 * EL SIGUIENTE PROGRMA GARANTIZAQ SU CORRECTO FUNCIONAMIENTO SI SE LE INGRESA
 * UN SOLO CARACTER A LA VEZ
 * ADEMAS ES NECESARIO QUE LOS NUMEROS QUE SE INGRESEN SEAN POSITIVOS
 * SOLO INGRESE LETRAS MAYUSCULAS
*/
void leer_Cadena(char *ptrA);
int main(){
    char cadena[50] = {0};
    char cadena_numeros[50] = {0};
    char cadena_caracteres[50] = {0};
    char * ptrA = &cadena[0];
    leer_Cadena(ptrA);

    int numeros = 0;
    int chars = 0;
    for(int i = 0; i < int(strlen(cadena)); i++){
        if(cadena[i] >= 48 && cadena[i] <= 57){
            cadena_numeros[numeros] = cadena[i];
            numeros++;
        }else{
            cadena_caracteres[chars] = cadena[i];
            chars++;
        }
    }
    cout << "\nCadena original: " << cadena << endl<< endl;
    cout << "Texto: " << cadena_caracteres << endl << endl;
    cout << "Numero: " << cadena_numeros << endl << endl;

    int cifras = 3;
    int suma = 0;
    int suma_tmp = 0;
    if(int(strlen(cadena_numeros))%cifras == 0){
        for(int i = 0; i < int(strlen(cadena_numeros)); i+=cifras){
            suma_tmp = 0;
            int cantidad = cifras-1;
            for(int j = i; j < (i+cifras); j++){
                suma_tmp += (cadena_numeros[j] - 48) * (pow(10,cantidad));
                cantidad -= 1;
            }
            suma += suma_tmp;
        }
    }else{
        int multiplicador = 1;
        for(int i = int(strlen(cadena_numeros))-1; i >= 0; i-=cifras){
            multiplicador = 1;
            suma_tmp = 0;
            if((i+1) - cifras > 0){
                for(int j = i; j > i-cifras; j--){
                    suma_tmp += (cadena_numeros[j] - 48) * multiplicador;
                    multiplicador *= 10;
                }
                suma += suma_tmp;
            }else{
                for(int j = i; j >= 0; j--){
                    suma_tmp += (cadena_numeros[j] - 48) * multiplicador;
                    multiplicador *= 10;
                }
                suma += suma_tmp;
            }
        }
    }
    cout << "Original: ";
    for(int i = 0; i < int(strlen(cadena_numeros)); i++){
        cout << cadena_numeros[i];
    }

    cout << endl;
    cout << "Suma: " << suma << endl;

    int mayor_letra = 0;
    int veces_letra = 0;
    for(int i = 0; i < int(strlen(cadena_caracteres)); i++){
        if(int(cadena_caracteres[i]) > mayor_letra){
            mayor_letra = cadena_caracteres[i];
            veces_letra = 1;
        }else{
            veces_letra++;
        }
    }
    char letra = mayor_letra;
    int mayor_numero = 0;
    int veces_numero = 0;
    for(int i = 0; i < int(strlen(cadena_numeros)); i++){
        if(cadena_numeros[i] > mayor_numero){
            mayor_numero = cadena_caracteres[i];
            veces_numero = 1;
        }else{
            veces_numero++;
        }
    }
    cout << letra << " aparece (" << veces_letra << ") veces y el digito " << mayor_numero << " aparece (" << veces_numero << ") veces" << endl;
    return 0;
}

void leer_Cadena(char *ptrA){
    char caracter = 0;
    int contador_caracteres = 0;
    while(true){
        cout << "Ingrese otro caracter: ";
        cin >> caracter;
        if(caracter != '*'){
            ptrA[contador_caracteres] = caracter;
            contador_caracteres ++;
        }else{
            break;
        }
        if(contador_caracteres == 51){
            cout << "Exediste la capacidad del arreglo de caracteres" << endl;
            break;
        }
    }
}
