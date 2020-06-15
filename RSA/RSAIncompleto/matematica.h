#pragma once
#include <iostream>
#include <random>
#include <NTL/ZZ.h>
using namespace std;
NTL::ZZ criba(NTL::ZZ n)
{
    bool* primos = new bool[n];
    for (int i = 0; i < n; i++)
    {
        primos[i] = false;
    }

    for (int j = 2; j * j <= n; j++)
    {
        if (!(primos[j]))
        {
            for (int k = j * j; k <= n; k += j)
            {
                primos[k] = true;
            }
        }
    }
    /*for (int l = 2; l <= n; l++)
    {
        if (!(primos[l]))
        {
            cout << l << " ";
        }
    }*/

    while (true)
    {
        int temp = rand() % n;
        if (!(primos[temp]))
            return temp;
    }
}
NTL::ZZ mod(NTL::ZZ x, NTL::ZZ y)
{
    NTL::ZZ r;
    r = x - ((x / y) * y);
    if (r < 0)
        r = x - (((x / y) - 1) * y);
    return r;
}
NTL::ZZ mcd(NTL::ZZ x, NTL::ZZ y)
{
    NTL::ZZ r;
    r = mod(x, y);
    while (r > 0)
    {
        x = y;
        y = r;
        r = mod(x, y);
    }
    return y;
}
NTL::ZZ inversa(NTL::ZZ x, NTL::ZZ y)
{
    NTL::ZZ q, s, t, r;
    NTL::ZZ r1 = x, r2 = y, s1 = NTL::conv < NTL::ZZ >("1"), s2 = NTL::conv < NTL::ZZ >("0"), t1 = NTL::conv < NTL::ZZ >("0"), t2 = NTL::conv < NTL::ZZ >("1");
    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    s = s1;
    t = t1;

    return mod(s, y);
}