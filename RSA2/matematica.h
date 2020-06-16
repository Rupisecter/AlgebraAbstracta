#pragma once
#include <iostream>
#include <random>
#include <NTL/ZZ.h>
using namespace std;
int criba(int n)
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
unsigned long long int mod(unsigned long long int x, unsigned long long int y)
{
    unsigned long long int r;
    r = x - ((x / y) * y);
    if (r < 0)
        r = x - (((x / y) - 1) * y);
    return r;
}
unsigned long long int mcd(unsigned long long int x, unsigned long long int y)
{
    unsigned long long int r;
    r = mod(x, y);
    while (r > 0)
    {
        x = y;
        y = r;
        r = mod(x, y);
    }
    return y;
}
unsigned long long int inversa(unsigned long long int x, unsigned long long int y)
{
    unsigned long long int q, s, t, r;
    unsigned long long int r1 = x, r2 = y, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
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
unsigned long long int expmod(unsigned long long int base, unsigned long long int exp, unsigned long long int n)
{
    vector<long long int>mod_v;
    mod_v.push_back(mod(base, n));

    unsigned long long int n1, n2;
    unsigned long long int res = mod_v[0];
    unsigned long long int i = 0, j = 1, aux = 1;

    while (exp)
    {
        bool binario = mod(exp, 2);
        if (j > 1)
        {
            unsigned long long int mod_l = mod_v[i];
            unsigned long long int temp = pow(mod_l, 2);
            unsigned long long int aux = mod(temp, n);
            mod_v.push_back(aux);
            i += 1;
            if (binario)
            {

                n1 = mod(res, n);
                n2 = mod(mod_v[i], n);
                res = mod(n1 * n2, n);
            }
        }
        aux *= 2;
        exp /= 2;
        j += 1;
    }
    return res;
}