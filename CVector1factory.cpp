#include "CVector.hpp"
#include "CVector1.hpp"
#include "CVectorfactory.hpp"
#include "CVector1factory.hpp"

CVector* CVector1Factory::Create()
{
	vector<double> num1{};
	int length1 = 0;
	string FileName1 = "";
	return new CVector1(FileName1, length1, num1);
}
