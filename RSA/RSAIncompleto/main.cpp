#include <iostream>
#include "matematica.h"
#include <time.h>
#include <math.h>
#include "RSA.h"
using namespace std;

int main()
{
    /*int aux;
    NTL::ZZ ans, n1, n2,n3;
    int a;
    n1 = NTL::conv < NTL:: ZZ > ("29648530");
    n2 = NTL::conv < NTL::ZZ >("42");
    n3 = NTL::conv < NTL::ZZ >("");
    ans = NTL::conv < NTL::ZZ >("0");
    //cout << (n1 * n1)%208777609;

    //a = pow(42, 124658);
    cout << n3 % 208777609;*/
    RSA rsa;
    string msj = "M";
    NTL::ZZ cmsj = rsa.cypher(msj);
    cout << cmsj << endl;
}


