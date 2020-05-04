#pragma once
#include <iostream>
#include <cmath>  
#include <NTL/ZZ.h>
using namespace std;
class Algoritmos
{
public:
    NTL::ZZ a, b, r;
    Algoritmos(NTL::ZZ _a, NTL::ZZ _b);
    ~Algoritmos();
    NTL::ZZ mod(NTL::ZZ x, NTL::ZZ y);
    NTL::ZZ Algoritmo1();
    NTL::ZZ Algoritmo2();
    NTL::ZZ Algoritmo3(NTL::ZZ x, NTL::ZZ y);
    NTL::ZZ Algoritmo4(NTL::ZZ x, NTL::ZZ y);
    NTL::ZZ Algoritmo5();
    NTL::ZZ Algoritmo6(NTL::ZZ x, NTL::ZZ y);
    NTL::ZZ Algoritmo7();

};

Algoritmos::Algoritmos(NTL::ZZ _a, NTL::ZZ _b)
{
    a = _a;
    b = _b;
}
Algoritmos::~Algoritmos()
{
    //destructor 
}

NTL::ZZ Algoritmos::mod(NTL::ZZ x, NTL::ZZ y)
{
    NTL::ZZ z;
    z = x - ((x / y) * y);
    return z;
}

NTL::ZZ Algoritmos::Algoritmo1()
{
    r = mod(a, b);
    cout << "a: " << a << " b: " << b << " r: " << r << endl;
    if (r==0)
        return b;
    else
    {
        a = b;
        b = r;
        return Algoritmo1();
    }
}

NTL::ZZ Algoritmos::Algoritmo2()
{
    r = mod(a, b);;
    cout << "a: " << a << " b: " << b << " r: " << r << endl;
    if (r==0)
        return b;
    else if (r > (b / 2))
        r = b - r;
    a = b;
    b = r;
    return Algoritmo2();
}

NTL::ZZ Algoritmos::Algoritmo3(NTL::ZZ x, NTL::ZZ y)
{
    cout << "a: " << x << " b: " << y << endl;
    if (y == 0)
        return x;
    return Algoritmo3(y, mod(x, y));
}

NTL::ZZ Algoritmos::Algoritmo4(NTL::ZZ x, NTL::ZZ y)
{
    cout << "a: " << x << " b: " << y << endl;
    NTL::ZZ temp(2);
    NTL::ZZ tempx, tempy;
    tempx = mod(x, temp);
    tempy = mod(y, temp);
    if (y > x)
        return Algoritmo4(y, x);             //y es mayor que x
    else if (y==0)
        return x;                           //y es igual a 0
    else if ((tempx==0) && (tempy==0))
        return 2 * Algoritmo4(x / 2, y / 2);       //x e y son pares
    else if ((tempx==0) && (tempy!=0))
        return  Algoritmo4(x / 2, y);          //x es par, y es impar
    else if ((tempx !=0) && (tempy==0))
        return  Algoritmo4(x, y / 2);          // x es impar, y es par
    else
        return Algoritmo4(((abs(x) - abs(y)) / 2), y);       //x e y son impares
}

NTL::ZZ Algoritmos::Algoritmo5()
{
    NTL::ZZ g,temp;
    g = 1;
    temp = 2;
    cout << "a: " << a << " b: " << b << " g: " << g << endl;
    while ((mod(a, temp)==0) && (mod(b, temp)==0))
    {
        a = a / 2;
        b = b / 2;
        g = 2 * g;
        cout << "a: " << a << " b: " << b << " g: " << g << endl;

    }
    while (a != 0)
    {
        while ((mod(a, temp)==0))
        {
            a = a / 2;
            cout << "a: " << a << " b: " << b << " g: " << g << endl;
        }
        while ((mod(b, temp)==0))
        {
            b = b / 2;
            cout << "a: " << a << " b: " << b << " g: " << g << endl;
        }
        NTL::ZZ t = abs((a - b)) / 2;
        if (a >= b)
            a = t;
        else
            b = t;
        cout << "a: " << a << " b: " << b << " g: " << g << endl;
    }
    return g * b;
}

NTL::ZZ Algoritmos::Algoritmo6(NTL::ZZ x, NTL::ZZ y)
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

NTL::ZZ Algoritmos::Algoritmo7()
{
    NTL::ZZ r;
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