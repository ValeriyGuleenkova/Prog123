class CVector1 : public CVector
{
public:
	CVector1(string FileName1, int length1, vector<double> num1);
	CVector1();
	void output();
	using CVector::operator =;
	CVector1(const CVector& other);
};
