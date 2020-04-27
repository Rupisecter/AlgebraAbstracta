#include <iostream>
#include <cmath>  
using namespace std;
class Algoritmos
{
public:
    int a, b, r;
    Algoritmos(int _a, int _b);
    int mod(int x, int y);
    int Algoritmo1();
    int Algoritmo2();
    int Algoritmo3(int x, int y);
    int Algoritmo4(int x, int y);
    int Algoritmo5();
    int Algoritmo6(int x, int y);
    int Algoritmo7();
};

Algoritmos::Algoritmos(int _a, int _b)
{
    a = _a;
    b = _b;
}

int Algoritmos::mod(int x, int y)
{
    if (x % y < 0)
        return x % y + y;
    return x % y;
}

int Algoritmos::Algoritmo1()
{
    r = a % b;
    cout << "a: " << a << " b: " << b << " r: " << r << endl;
    if (!r)
        return b;
    else
    {
        a = b;
        b = r;
        return Algoritmo1();
    }
}

int Algoritmos::Algoritmo2()
{
    r = a % b;
    cout << "a: " << a << " b: " << b << " r: " << r << endl;
    if (!r)
        return b;
    else if (r > (b / 2))
        r = b - r;
    a = b;
    b = r;
    return Algoritmo2();
}

int Algoritmos::Algoritmo3(int x, int y)
{
    cout << "a: " << x << " b: " << y << endl;
    if (y == 0)
        return x;
    return Algoritmo3(y, mod(x, y));
}

int Algoritmos::Algoritmo4(int x, int y)
{
    cout << "a: " << x << " b: " << y << endl;
    if (y > x)
        return Algoritmo4(y, x);             //y es mayor que x
    else if (!y)
        return x;                           //y es igual a 0
    else if (!(mod(x, 2)) && !(mod(y, 2)))
        return 2 * Algoritmo4(x / 2, y / 2);       //x e y son pares
    else if (!(mod(x, 2)) && (mod(y, 2)))
        return  Algoritmo4(x / 2, y);          //x es par, y es impar
    else if ((mod(x, 2)) && !(mod(y, 2)))
        return  Algoritmo4(x, y / 2);          // x es impar, y es par
    else
        return Algoritmo4(((abs(x) - abs(y)) / 2), y);       //x e y son impares
}

int Algoritmos::Algoritmo5()
{
    int g;
    g = 1;
    cout << "a: " << a << " b: " << b << " g: " << g << endl;
    while (!(mod(a, 2)) && !(mod(b, 2)))
    {
        a = a / 2;
        b = b / 2;
        g = 2 * g;
        cout << "a: " << a << " b: " << b << " g: " << g << endl;

    }
    while (a != 0)
    {
        while (!(mod(a, 2)))
        {
            a = a / 2;
            cout << "a: " << a << " b: " << b << " g: " << g << endl;
        }
        while (!(mod(b, 2)))
        {
            b = b / 2;
            cout << "a: " << a << " b: " << b << " g: " << g << endl;
        }
        int t = abs((a - b)) / 2;
        if (a >= b)
            a = t;
        else
            b = t;
        cout << "a: " << a << " b: " << b << " g: " << g << endl;
    }
    return g * b;
}

int Algoritmos::Algoritmo6(int x, int y)
{
    while (x != y)
    {
        cout << "a: " << x << " b: " << y << endl;
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }
    cout << "a: " << x << " b: " << y << endl;
    return x;
}

int Algoritmos::Algoritmo7()
{
    int r;
    r = mod(a, b);
    cout << "a: " << a << " b: " << b << " r: " << r << endl;
    while (r > 0)
    {
        cout << "b: " << b << " r: " << r << endl;
        a = b;
        b = r;
        r = mod(a, b);
    }
    cout << "b: " << b << " r: " << r << endl;
    return b;
}
#pragma once
