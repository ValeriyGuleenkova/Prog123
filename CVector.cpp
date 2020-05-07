#include "CVector.hpp"
#include "CVector0.hpp"
#include "CVector1.hpp"

CVector::CVector(string FileName1, int length1, vector<double> num1)
{
	FileName = FileName1;
	length = length1;
	for (int i = 0; i < length; i++)
	{
		num.push_back(num1[i]);
	}
}

CVector::CVector() = default;

CVector::CVector(const CVector & other)
{
	FileName = other.FileName;
	length = other.length;
	for (int i = 0; i < length; i++)
	{
		num.push_back(other.num[i]);
	}
}

CVector::~CVector() {}

double CVector::operator* (const CVector & other)
{
	double s = 0;
	if (length != other.length)
	{
		cout << "+ ERROR: WRONG LENGTHS" << endl;
		return 0;
	}
	auto start = chrono::system_clock::now();
#pragma omp parallel for
	for (int i = 0; i < length; i++) s = s + num[i] * other.num[i];
	auto end = chrono::system_clock::now();
	int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
	//cout << "Operator * time is " << elapsed_ms << " ms" << endl;
	return s;
}

CVector& CVector::operator= (const CVector & other)
{
	FileName = other.FileName;
	length = other.length;
	for (int i = 0; i < length; i++)
	{
		num.push_back(other.num[i]);
	}
	return *this;
}
