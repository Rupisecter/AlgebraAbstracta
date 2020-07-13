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
	string msj = "THE GAME";
	vector<NTL::ZZ> cmsj = rsa.cypher(msj);
	for (int i = 0; i < cmsj.size(); i++)
	{
		cout << cmsj[i]<<" ";
	}
	cout << endl;
	vector<int> dmsj = rsa.decypher(cmsj);
	for (int i = 0; i < cmsj.size(); i++)
	{
		cout << dmsj[i] << " ";
	}
	cout << endl << endl << endl;
	RSABloques rsa2(1024);
	
	//cout << inversa(NTL::ZZ(303941125), NTL::ZZ(543687598));

}
