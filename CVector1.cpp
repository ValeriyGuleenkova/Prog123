#include "CVector.hpp"
#include "CVector0.hpp"
#include "CVector1.hpp"

CVector1::CVector1() = default;

CVector1::CVector1(string FileName1, int length1, vector<double> num1) :CVector(FileName1, length1, num1) {}

void CVector1::output()
{
	ofstream out(FileName, ios_base::app);
	if (!out) return;
	for (int i = 0; i < length; i++)
	{
		out << num[i] << endl;
	}
	out << endl;
	return;
}

CVector1::CVector1(const CVector & other) :CVector(other) {}
