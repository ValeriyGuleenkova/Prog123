#include "CVector.hpp"
#include "CVector0.hpp"
#include "CVectorfactory.hpp"
#include "CVector0factory.hpp"

CVector* CVector0Factory::Create()
{
	vector<double> num1{};
	int length1 = 0;
	string FileName1 = "";
	return new CVector0(FileName1, length1, num1);
}
