#include "CVector.hpp"
#include "CVector0.hpp"
#include "CVector1.hpp"
#include "functions.hpp"
#include "autotests.hpp"

int main()
{
	autotest1();
	autotest2();
	autotest3();
	autotest4();
	OpenMPTest();

	vector<CVector*> arr = ReadFile();
	for (vector<CVector*>::iterator it = arr.begin(); it < arr.end(); it++) (*it)->output();
	for (vector<CVector*>::iterator it = arr.begin(); it < arr.end(); it++) delete (*it);

	return 0;
}
