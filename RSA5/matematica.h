#pragma once
#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <ctime>
#include <math.h>
using namespace std;
vector<NTL::ZZ> criba(NTL::ZZ n)
{
    bool* primos = new bool[NTL::conv<long>(n)];
    vector<NTL::ZZ> listadeprimos;
    for (NTL::ZZ i = NTL::ZZ(0); i < n; i++)
        primos[NTL::conv<int>(i)] = false;
    for (NTL::ZZ j = NTL::ZZ(2); j * j <= n; j++)
    {
        if (!(primos[NTL::conv<int>(j)]))
        {
            for (NTL::ZZ k = j * j; k <= n; k += j)
                primos[NTL::conv<int>(k)] = true;
        }
    }
    for (NTL::ZZ l = NTL::ZZ(2); l <= n; l++)
    {
        if (!(primos[NTL::conv<int>(l)]))
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
NTL::ZZ modzz(NTL::ZZ  x, NTL::ZZ  y)
{
    NTL::ZZ  r;
    r = x - ((x / y) * y);
    if (r < 0)
        r = x - (((x / y) - 1) * y);
    return r;
}
NTL::ZZ inversa(NTL::ZZ x, NTL::ZZ y)
{
    NTL::ZZ q, s, t, r;
    NTL::ZZ r1 = x, r2 = y, s1 = NTL::ZZ(1), s2 = NTL::ZZ(0), t1 = NTL::ZZ(0), t2 = NTL::ZZ(1);
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
        s = modzz(s, y);
    return s;
}

NTL::ZZ expmod(NTL::ZZ base, NTL::ZZ exp, NTL::ZZ n)
{
    vector<NTL::ZZ>mod_v;
    mod_v.push_back(modzz(base, n));

    NTL::ZZ n1, n2;
    NTL::ZZ res = mod_v[0];
    NTL::ZZ i = NTL::ZZ(0), j = NTL::ZZ(1), aux = NTL::ZZ(1);

    while (exp>0)
    {
        short binario = NTL::conv<int>(modzz(exp, NTL::ZZ(2)));
        if (j > 1)
        {
            NTL::ZZ mod_l = mod_v[NTL::conv<long>(i)];
            NTL::ZZ temp = power(mod_l, 2);
            NTL::ZZ aux = modzz(temp, n);
            mod_v.push_back(aux);
            i += 1;
            if (binario)
            {

                n1 = modzz(res, n);
                n2 = modzz(mod_v[NTL::conv<long>(i)], n);
                res = modzz(n1 * n2, n);
            }
        }
        aux *= 2;
        exp /= 2;
        j += 1;
    }
    return res;
}
vector<NTL::ZZ> criba2(NTL::ZZ mayor, NTL::ZZ menor)
{
    vector<NTL::ZZ> primos;
    for (NTL::ZZ i = menor; i <= mayor; i++)
    {
        if(modzz(i,NTL::ZZ(2))==0)
            primos.push_back(i);
    }
    for (NTL::ZZ k = NTL::ZZ(3); k < mayor; k+=2)
    {
        if (k * k < mayor)
        {
            for (NTL::ZZ x = NTL::ZZ(0); x < primos.size(); x++)
            {
                if ((modzz(primos[NTL::conv<long>(x)], k))==0)
                    primos.erase(primos.begin() + NTL::conv<long>(x));
            }
        }
    }
    return primos; 
}
bool testPrimo(NTL::ZZ p) {
    bool valor = false;
    for (int i = 0; i < p - 1; i++) {
        NTL::ZZ j = power(NTL::ZZ(i), NTL::conv<long>(p - 1));
        if (modzz(j, p) == 1) {
            valor = true;
        }
        else {
            valor = false;
        }
    }
    return valor;
}
bool isPrime(NTL::ZZ n)
{
    // Corner case 
    if (n <= 1)  return false;

    // Check from 2 to n-1 
    for (NTL::ZZ i = NTL::ZZ(2); i < n; i++)
        if (modzz(n, i) == 0)
            return false;

    return true;
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

/*void restochino(int n)//n es para la cantidad de operaciones
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
}*/
NTL::ZZ GenerarRandom()
{
    MEMORYSTATUSEX DatosRAM;
    SYSTEMTIME Tiempo;
    DatosRAM.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&DatosRAM);
    GetLocalTime(&Tiempo);
    long long int Numero = Tiempo.wMilliseconds * DatosRAM.ullTotalPhys;
    NTL::ZZ NumeroFinal(Numero);
    return NumeroFinal;
}
/*vector<NTL::ZZ> GenerarBits(int bit,int cantidad)
{
    vector<NTL::ZZ> Numeros;
    NTL::ZZ Start=NTL::ZZ(1);
    NTL::ZZ End;
    NTL::ZZ Random = NTL::ZZ(0);
    for (int i = 0; i < bit - 1; i++)
    {
        Start *= 2;
    }
    End = Start * 2;
    clock_t timer;
    double tiempo;
    timer = clock();
    Numeros.push_back(Start);
    for(NTL::ZZ i=NTL::ZZ(0);i<cantidad;i++)
    {
        Random=modzz(GenerarRandom()+Random*GenerarRandom(),End);
        Numeros.push_back(modzz(Start+Random*Random*Random,End));
    }
    tiempo = (clock() - timer) / (double)CLOCKS_PER_SEC;
    cout << "Tiempo en generar: " << tiempo<<endl;

    return Numeros;
}*/
void cambiar(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

vector<int> convertirbinario(int a)
{
    vector<int> binariotemp;
    vector<int> binariofinal;
    while (a > 0)
    {
        binariotemp.push_back(mod(a, 2));
        a = a / 2;
    }
    for (int i = binariotemp.size(); i < 8; i++)
    {
        binariotemp.push_back(0);
    }
    for (int i = binariotemp.size() - 1; i >= 0; i--)
    {
        binariofinal.push_back(binariotemp[i]);
    }
    return binariofinal;
}

NTL::ZZ convertirdecimal(vector<int> a)
{
    NTL::ZZ numero=NTL::ZZ(0);
    a.pop_back();
    a.push_back(1);
    for (long long int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i])
            numero += power(NTL::ZZ(2),a.size()-1 - i);
    }
    while (!(testPrimo(numero)))
    {
        numero--;
    }
    return numero;
}

vector<int> corrimiento(vector<int>& K, vector<int>& C,vector<int>& D)
{
    for (int i = 0; i < K.size() / 2; i++)
    {
        C.push_back(K[i]);
    }
    for (int i = K.size() / 2; i < K.size(); i++)
    {
        D.push_back(K[i]);
    }
    C.push_back(C[0]);
    D.push_back(D[0]);
    C.erase(C.begin());
    D.erase(D.begin());
    vector<int> newK = C;
    for (int i = 0; i < D.size(); i++)
    {
        newK.push_back(D[i]);
    }
    return newK;
}
NTL::ZZ DES(vector<vector<int>> binarios,long long int bitscantidad)
{
    vector<int> tablaPC56(56);
    vector<int> tablaPC48(48);
    vector<vector<int>> tablas;
    vector<int> newbinary;
    vector<int> kn,newK;
    vector<int> C, D;
    tablaPC56 = {57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    tablaPC48 = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32 };
    tablas.push_back(tablaPC56);
    tablas.push_back(tablaPC48);
    for (long long int i = 0; i < tablaPC56.size(); i++)
    {
        int indice1 = tablaPC56[i] / 8;
        int indice2 = mod(tablaPC56[i], 8)-1;
        newbinary.push_back(binarios[indice1][indice2]);
        //cout << newbinary[i];
    }
    for (long long int i = 0; i < bitscantidad/48; i++)
    {
        newK=corrimiento(newbinary, C, D);
        for (long long int j = 0; j < tablaPC48.size(); j++)
        {
            kn.push_back(newK[j]);
            //cout << kn[j];
        }
    }
    for(long long int i=kn.size(); i < bitscantidad;i++)
    {
        newK = corrimiento(newbinary, C, D);
        kn.push_back(newK[i]);
        //cout << kn[i];
    }
    return convertirdecimal(kn);
}

NTL::ZZ iniciar2(vector<int> S)
{
    vector<vector<int>> Sbinary;
    for (int i = 0; i < 8; i++)
    {
        Sbinary.push_back(convertirbinario(S[i]));
    }
    return DES(Sbinary,8);
}
NTL::ZZ iniciarRC4(vector<int> K,int Z)
{
    vector<int> S;
    int f = 0;
    for (int i = 0; i < Z; i++)
    {
        S.push_back(i);
    }
    for (int i = 0; i < Z; i++)
    {
        f = mod((f + S[i] + K[mod(i, K.size())]), Z);
        int temp = S[i];
        S[i] = S[f];
        S[f] = temp;
    }
    return iniciar2(S);
}

vector<int> HardwareGen(vector<int> &a, int bits)
{
    SYSTEM_INFO	datos;
    SYSTEMTIME tiempo;
    _MEMORYSTATUSEX datos2;

    GetSystemInfo(&datos);
    GetLocalTime(&tiempo);
    GlobalMemoryStatusEx(&datos2);

    int random = tiempo.wSecond * datos.dwProcessorType;
    a.push_back(mod(random, bits));

    random = tiempo.wMilliseconds * datos.dwNumberOfProcessors * (random + 1);
    a.push_back(mod(random, bits));

    random = tiempo.wMilliseconds * datos.wProcessorRevision * (random + 1);
    a.push_back(mod(random, bits));

    random = tiempo.wDay * datos2.dwMemoryLoad * (random + 1);
    a.push_back(mod(random, bits));

    random = tiempo.wMonth * datos2.ullTotalPhys * (random + 1);
    a.push_back(mod(random, bits));

    return a;
}