#include "CVector.hpp"
#include "CVector0.hpp"
#include "CVector1.hpp"

CVector0::CVector0() = default;

CVector0::CVector0(string FileName1, int length1, vector<double> num1) :CVector(FileName1, length1, num1) {}

void CVector0::output()
{
	ofstream out(FileName, ios_base::app);
	if (!out) return;
	for (int i = 0; i < length; i++)
	{
		out << num[i] << " ";
	}
	out << endl << endl;
	return;
}

CVector0::CVector0(const CVector & other) :CVector(other) {}