#include "CVector.hpp"
#include "CVector0.hpp"
#include "CVector1.hpp"
#include "functions.hpp"

void autotest1()
{
	vector<double> num1;
	vector<double> num2;
	for (int i = 0; i < 5; i++)
	{
		num1.push_back(1.4);
		num2.push_back(1.1);
	}
	string str1 = "str1.txt";
	string str2 = "str2.txt";
	int flag = 0;

	CVector1 a(str1, 5, num1);
	CVector1 b(str2, 5, num2);
	CVector0 c;

	c = a - b;

	for (int i = 0; i < c.length; i++) if (c.num[i] == 0, 3) flag++;

	if (flag == 5) printf("Test 1 complete!\n");
	else printf("Test 1 fail!\n");

	return;
}

void autotest2()
{
	vector<double> num1{ 1.5,2.5,3.5,4.5,5.5 };
	vector<double> num2{ 8.5,7.5,6.5,5.5,4.5 };
	string str1 = "str1.txt";
	string str2 = "str2.txt";
	int flag = 0;

	CVector0 a(str1, 5, num1);
	CVector0 b(str2, 5, num2);
	CVector1 c = a + b;

	for (int i = 0; i < c.length; i++) if (c.num[i] == 10.0) flag++;
	if (flag == 5) printf("Test 2 complete!\n");
	else printf("Test 2 fail!\n");

	return;
}

void autotest3()
{
	vector<double> num1{ 1.0,1.0,1.0,1.0,1.0 };
	vector<double> num2{ 6.0,6.0,1.0,9.0,3.0 };
	string str1 = "str1.txt";
	string str2 = "str2.txt";

	CVector1 a(str1, 5, num1);
	CVector0 b(str2, 5, num2);
	double c = a * b;

	if (c == 25.0) printf("Test 3 complete!\n");
	else printf("Test 3 fail!\n");

	return;
}

void autotest4()
{
	vector<double> num1{ 1,2,3,4,5 };
	vector<double> num2{ 6,6,1,9,3 };
	string str1 = "str1.txt";
	string str2 = "str2.txt";

	CVector1 a(str1, 5, num1);
	CVector0 b(str2, 5, num2);
	CVector0 c = a + b;

	if (c.FileName == "str1.txt") printf("Test 4 complete!\n");
	else printf("Test 4 fail!\n");

	return;
}

void OpenMPTest()
{
	vector<double> num1;
	vector<double> num2;

	int N = 20000000;

	for (int i = 0; i < N; i++)
	{
		num1.push_back(1.0);
		num2.push_back(2.5);
	}
	string str1 = "str1.txt";
	string str2 = "str2.txt";
	int flag = 0;

	CVector1 a(str1, N, num1);
	CVector1 b(str2, N, num2);
	CVector0 c;

	c = a - b;

	for (int i = 0; i < c.length; i++) if (c.num[i] == -1.5) flag++;

	if (flag == N) printf("OpenMPTest complete!\n");
	else printf("OpenMPTest fail!\n");

	return;
}