#include <iostream>
#include "matematica.h"
#include <time.h>
#include <math.h>
#include "RSA.h"
using namespace std;

int main()
{
    RSA rsa(12);
    string msj = "C";
    long long int cmsj = rsa.cypher(msj);
    cout << cmsj << endl;
    long long int dmsj = rsa.decypher(cmsj);
    cout << dmsj << endl;
}


