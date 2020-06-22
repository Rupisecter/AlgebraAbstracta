#include <iostream>
#include "matematica.h"
#include <time.h>
#include <math.h>
#include "RSA.h"
using namespace std;

int main()
{

    RSA rsa(16);
    string msj = "C";
    long long int cmsj = rsa.cypher(msj);
    cout << cmsj << endl;
    //criba2(1000000,900000);
    //restochino(3);//3 operaciones, 2mod3, 3mod5, 2mod7 por ejemplo
    
}


