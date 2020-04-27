// euclides.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include "Algoritmos.h"
#include <time.h>
using namespace std;

int main()
{

    int ans, aux, n1, n2;
    clock_t inicio, endt;
    double tiempo;
    cout << "Numero 1: ";
    cin >> n1;
    cout << "\nNumero 2: ";
    cin >> n2;
    cout << "\nIngresa el numero del algoritmo: ";
    cin >> aux;
    Algoritmos alg(n1, n2);
    switch (aux)
    {
    case 1:
        inicio = clock();
        ans = alg.Algoritmo1();
        endt = clock();
        break;
    case 2:
        inicio = clock();
        ans = alg.Algoritmo2();
        endt = clock();
        break;
    case 3:
        inicio = clock();
        ans = alg.Algoritmo3(alg.a, alg.b);
        endt = clock();
        break;
    case 4:
        inicio = clock();
        ans = alg.Algoritmo4(alg.a, alg.b);
        endt = clock();
        break;
    case 5:
        inicio = clock();
        ans = alg.Algoritmo5();
        endt = clock();
        break;
    case 6:
        inicio = clock();
        ans = alg.Algoritmo6(alg.a, alg.b);
        endt = clock();
        break;
    case 7:
        inicio = clock();
        ans = alg.Algoritmo7();
        endt = clock();
        break;
    }
    tiempo = (endt - inicio) / (double)CLOCKS_PER_SEC;
    cout << "MCD: " << ans << " Tiempo: " << tiempo << endl;
}


