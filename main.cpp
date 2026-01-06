#include <iostream>
#include <string>
#include <cctype> // Para la función tolower
#include <iomanip> // Para formatear la salida

using namespace std;

// Función para calcular el IMC
float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

// Función para interpretar el resultado del IMC
string interpretarIMC(float imc) {
    if (imc < 18.5) {
        return "Bajo peso";
    } else if (imc < 24.9) {
        return "Peso normal";
    } else if (imc < 29.9) {
        return "Sobrepeso";
    } else {
        return "Obesidad";
    }
}

int main() {
    char opcion;
    float *ptrPeso = new float;
    float *ptrAltura = new float;
    float *ptrIMC = new float;

    cout << "=== CALCULADORA DE IMC ===" << endl;
    cout << "Presione 'x' para salir en cualquier momento" << endl << endl;

    do {
        cout << "Ingrese su peso en kg: ";
        string input;
        cin >> input;

        // Verificar si el usuario quiere salir
        if (tolower(input[0]) == 'x' && input.length() == 1) {
            cout << "Saliendo del programa..." << endl;
            break;
        }

        try {
            *ptrPeso = stof(input);
        } catch (...) {
            cout << "Entrada no valida. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cout << "Ingrese su altura en metros (ej. 1.75): ";
        cin >> input;

        // Verificar si el usuario quiere salir
        if (tolower(input[0]) == 'x' && input.length() == 1) {
            cout << "Saliendo del programa..." << endl;
            break;
        }

        try {
            *ptrAltura = stof(input);
        } catch (...) {
            cout << "Entrada no válida. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        // Calcular e imprimir resultados
        *ptrIMC = calcularIMC(*ptrPeso, *ptrAltura);
        string resultado = interpretarIMC(*ptrIMC);

        cout << fixed << setprecision(2);
        cout << "\n=== RESULTADOS ===" << endl;
        cout << "Peso: " << *ptrPeso << " kg" << endl;
        cout << "Altura: " << *ptrAltura << " m" << endl;
        cout << "IMC: " << *ptrIMC << " - " << resultado << endl << endl;

        cout << "Desea realizar otro calculo? (s/n): ";
        cin >> opcion;
        cout << endl;

    } while (tolower(opcion) == 's');

    // Liberar memoria
    delete ptrPeso;
    delete ptrAltura;
    delete ptrIMC;

    return 0;
}