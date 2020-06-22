#pragma once
#include <iostream>
#include <random>
#include <NTL/ZZ.h>
#include <vector>
using namespace std;
using namespace NTL;
vector<long long int> criba(long long int n)
{
    bool* primos = new bool[n];
    vector<long long int> listadeprimos;
    for (long long int i = 0; i < n; i++)
        primos[i] = false;
    for (long long int j = 2; j * j <= n; j++)
    {
        if (!(primos[j]))
        {
            for (long long int k = j * j; k <= n; k += j)
                primos[k] = true;
        }
    }
    for (long long int l = 2; l <= n; l++)
    {
        if (!(primos[l]))
            listadeprimos.push_back(l);
    }
    return listadeprimos;
}
long long int mod(long long int x, long long int y)
{
    long long int r;
    r = x - ((x / y) * y);
    if (r < 0)
        r = x - (((x / y) - 1) * y);
    return r;
}
long long int mcd(long long int x, long long int y)
{
    long long int r;
    r = mod(x, y);
    while (r > 0)
    {
        x = y;
        y = r;
        r = mod(x, y);
    }
    return y;
}
long long int inversa(long long int x, long long int y)
{
    long long int q, s, t, r;
    long long int r1 = x, r2 = y, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
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
    if (s < 0)
        s = mod(s, y);
    return s;
}
long long int expmod(long long int base, long long int exp, long long int n)
{
    vector<long long int>mod_v;
    mod_v.push_back(mod(base, n));

    long long int n1, n2;
    long long int res = mod_v[0];
    long long int i = 0, j = 1, aux = 1;

    while (exp)
    {
        bool binario = mod(exp, 2);
        if (j > 1)
        {
            long long int mod_l = mod_v[i];
            long long int temp = pow(mod_l, 2);
            long long int aux = mod(temp, n);
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
vector<long long int> criba2( long long int mayor, long long int menor)
{
    vector< long long int> primos;
    for (long long int i = menor; i <= mayor; i++)
    {
        if(mod(i,2))
            primos.push_back(i);
    }
    for (long long int k = 3; k < mayor; k+=2)
    {
        if (k * k < mayor)
        {
            for (long long int x = 0; x < primos.size(); x++)
            {
                if (!(mod(primos[x], k)))
                    primos.erase(primos.begin() + x);
            }
        }
    }
    return primos; 
}
bool coprimos(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 1; j < a.size(); j++)
        {
            if (mcd(a[i], a[j]) != 1)
                return true;
        }
    }
    return false;
}
vector<int> llenar(vector<int> &a,int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    return a;
}

void restochino(int n)//n es para la cantidad de operaciones
{
    vector<int> modulos,Ps,qs,xs;
    int P=1,pi,qi,x0,temp=0;
    cout << "Ejemplo: x(mod n)" << endl;
    cout << "Llene las x: ";
    xs = llenar(xs, n);
    cout <<"Llene los modulos: ";
    modulos=llenar(modulos,n);
    if ((coprimos(modulos)))
    {
        for (int i = 0; i < modulos.size(); i++)
        {
            P *= modulos[i];
        }
        for (int j = 0; j < modulos.size(); j++)
        {
            pi = P / modulos[j];
            Ps.push_back(pi);
            qi = inversa(Ps[j], modulos[j]);
            qs.push_back(qi);
            temp += xs[j] * Ps[j] * qs[j];
        }
        x0 = mod(temp, P);
        cout << x0 << " + " << P << "k";
    }
    else
        cout << "No hay solución";
}