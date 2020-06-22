#include <iostream>
#include <vector>
using namespace std;
int mod(int x, int y)
{
    int r;
    r = x - ((x / y) * y);
    if (r < 0)
        r = x - (((x / y) - 1) * y);
    return r;
}
int mcd(int x, int y)
{
    int r;
    r = mod(x, y);
    while (r > 0)
    {
        x = y;
        y = r;
        r = mod(x, y);
    }
    return y;
}
int inversa (int x,  int y)
{
    int q, s, t, r;
    int r1 = x, r2 = y, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
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

    return s;
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
int main()
{
  restochino(3);
}