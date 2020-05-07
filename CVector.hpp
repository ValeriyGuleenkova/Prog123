#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <iterator>
#include <chrono>
using namespace std;

class CVector
{
public:
	string FileName;
	int length;
	vector<double> num;
	CVector(string FileName1, int length1, vector<double> num1);
	CVector();
	CVector(const CVector& other);
	double operator* (const CVector& other);
	virtual ~CVector();
	virtual void output() = 0;
	CVector& operator= (const CVector& other);
};
