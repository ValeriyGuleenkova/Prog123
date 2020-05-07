#include "CVector.hpp"
#include "CVector0.hpp"
#include "CVector1.hpp"
#include "functions.hpp"
#include "CVectorfactory.hpp"
#include "CVector0factory.hpp"
#include "CVector1factory.hpp"

CVector0 operator- (const CVector& first, const CVector& second)
{
	CVector0 res;
	res.num = first.num;
	res.length = first.length;
	res.FileName = first.FileName;
	res.num.reserve(first.length);
	if (first.length != second.length)
	{
		cout << "+ ERROR: WRONG LENGTHS" << endl;
	}
	else
	{
		auto start = chrono::system_clock::now();
#pragma omp parallel for
		for (int i = 0; i < first.length; i++)
		{
			res.num[i] = first.num[i] - second.num[i];
		}
		auto end = chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
		cout << "Operator - time is " << elapsed_ms << " ms" << endl;
	}
	return res;
}

CVector0 operator+ (const CVector& first, const CVector& second)
{

	CVector0 res;
	res.num = first.num;
	res.length = first.length;
	res.FileName = first.FileName;
	res.num.reserve(first.length);

	if (first.length != second.length)
	{
		cout << "+ ERROR: WRONG LENGTHS" << endl;
	}
	else
	{
		auto start = chrono::system_clock::now();
#pragma omp parallel for
		for (int i = 0; i < first.length; i++)
		{
			res.num[i] = first.num[i] + second.num[i];
		}
		auto end = chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
		//cout << "Operator + time is " << elapsed_ms << " ms" << endl;
	}
	return res;
}

vector<CVector*> ReadFile()
{
	int flag = 0;
	CVector0Factory Hori;
	CVector1Factory Vert;
	map<string, Factory*> factories_ = { {"Hori",&Hori},{"Vert",&Vert} };
	ifstream in("input.txt");
	if (!in)
	{
		cout << "FILE ERROR!" << endl;
		flag = 1;
	}
	vector<CVector*> arr;
	arr.reserve(256);
	if (flag == 0)
	{
		double m;
		string I;
		int length;
		string str;
		while (!in.eof())
		{
			vector<double> num{};
			in >> I;
			in >> str;
			in >> length;
			for (int i = 0; i < length; i++)
			{
				in >> m;
				num.push_back(m);
			}
			auto resFactory = factories_[I];
			auto newVector = resFactory->Create();
			newVector->num = num;
			newVector->length = length;
			newVector->FileName = str;
			arr.push_back(newVector);
			num.clear();
		}
	}
	return arr;
}