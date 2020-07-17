#include <iostream>
#include <vector>
#include <windows.h>
#include "matematica.h"
#include <NTL/ZZ.h>
#include "RSA.h"
#include "RSABloques.h"
using namespace std;



int main()
{
	//cout << expmod(NTL::ZZ(572), NTL::ZZ(29), NTL::ZZ(713));
	/*vector<int>numeros;
	numeros = HardwareGen(numeros,256);
	NTL::ZZ a = iniciarRC4(numeros, 256);
	cout << a<<endl<<power(NTL::ZZ(2),1024);*/
	RSA rsa(256);
	string msj = "C";
	string cmsj = rsa.cypher(msj);
	cout << endl<<cmsj;
	string dmsj = rsa.decypher(cmsj);
	cout << endl << dmsj << endl;	
	//cout << inversa(NTL::ZZ(303941125), NTL::ZZ(543687598));

}
