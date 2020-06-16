#include <iostream>
#include "matematica.h"
#include <time.h>
#include <math.h>
#include "RSA.h"
using namespace std;

int main()
{

    RSA rsa;
    string msj = "C";
    unsigned long long int cmsj = rsa.cypher(msj);
    cout << cmsj << endl;

}


