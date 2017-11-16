#include <iostream>
#include <time.h>
using namespace std;

float mark(float mark);
float mark2(float mark);

int main()
{
	int x = 5;
	int y = 7;

	float **arr10 = new float*[x];
	float **arr11 = new float*[x];
	float **arr12 = new float*[x];
	float **arr13 = new float*[x];

	for (int i = 0; i < x; i++)
	{
		arr10[i] = new float[y];
		arr11[i] = new float[y];
		arr12[i] = new float[y];
		arr13[i] = new float[y];
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			arr10[i][j] = (rand() % 11) * 0.1;
		for (int j = 0; j < y; j++)
			arr11[i][j] = (rand() % 11) * 0.1;
		for (int j = 0; j < y; j++)
			arr12[i][j] = (rand() % 11) * 0.1;
		for (int j = 0; j < y; j++)
			arr13[i][j] = (rand() % 11) * 0.1;
	}

	int **arr = new int*[x];
	int **arr1 = new int*[x];
	int **arr2 = new int*[x];
	int **arr3 = new int*[x];

	for (int i = 0; i < x; i++)
	{
		arr[i] = new int[y];
		arr1[i] = new int[y];
		arr2[i] = new int[y];
		arr3[i] = new int[y];
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			arr[i][j] = mark2(arr10[i][j]);
		for (int j = 0; j < y; j++)
			arr1[i][j] = mark2(arr11[i][j]);
		for (int j = 0; j < y; j++)
			arr2[i][j] = mark2(arr12[i][j]);
		for (int j = 0; j < y; j++)
			arr3[i][j] = mark2(arr13[i][j]);
	}

	int **arr20 = new int*[x];
	int **arr21 = new int*[x];
	int **arr22 = new int*[x];
	int **arr23 = new int*[x];

	for (int i = 0; i < x; i++)
	{
		arr20[i] = new int[y];
		arr21[i] = new int[y];
		arr22[i] = new int[y];
		arr23[i] = new int[y];
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			arr20[i][j] = mark(arr10[i][j]);
		for (int j = 0; j < y; j++)
			arr21[i][j] = mark(arr11[i][j]);
		for (int j = 0; j < y; j++)
			arr22[i][j] = mark(arr12[i][j]);
		for (int j = 0; j < y; j++)
			arr23[i][j] = mark(arr13[i][j]);
	}

	float Oi[4] = { 0.2, 0.2, 0.3, 0.3 };
	float Hj[5] = { 0.4, 0.1, 0.1, 0.2, 0.2 };
	float Ek[7] = { 0.1, 0.1, 0.2, 0.1, 0.3, 0.1, 0.1 };

	float q1 = 0;
	float q2 = 0;
	float q3 = 0;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			q1 = q1 + arr[i][j] + arr1[i][j] + arr2[i][j] + arr3[i][j];

	q1 = q1 / 140;
	//cout << "Q1 = " << q1 << endl;

	float res[20];

	for (int i = 0; i < x; i++)
	{
		float r1 = 0;
		float r2 = 0;
		float r3 = 0;
		float r4 = 0;
		for (int j = 0; j < y; j++)
		{
			r1 = r1 + (arr10[i][j] * Ek[j]);
			r2 = r2 + (arr11[i][j] * Ek[j]);
			r3 = r3 + (arr12[i][j] * Ek[j]);
			r4 = r4 + (arr13[i][j] * Ek[j]);
		}
		res[i] = r1;
		res[i + 5] = r2;
		res[i + 10] = r3;
		res[i + 15] = r4;
	}

	float res2[5];
	for (int i = 0; i < 5; i++)
	{
		float result = 0;
		for (int j = 0; j < 4; j++)
			result = result + (res[i + j] * Oi[j]);
		res2[i] = result;
	}

	for (int i = 0; i < 5; i++)
		q2 = q2 + (res2[i] * Hj[i]);

	//cout << "Q2 = " << q2 << endl;

	/*
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			q3 = q3 + arr20[i][j] + arr21[i][j] + arr22[i][j] + arr23[i][j];

	q3 = q3 / 140;
	cout << "Q3 = " << q3 << endl;
	*/

	float **mass1 = new float*[x];
	float **mass2 = new float*[x];
	float **mass3 = new float*[x];
	float **mass4 = new float*[x];

	for (int i = 0; i < x; i++)
	{
		mass1[i] = new float[y];
		mass2[i] = new float[y];
		mass3[i] = new float[y];
		mass4[i] = new float[y];
	}
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			mass1[i][j] = Ek[j] * Hj[i] * Oi[0];
		for (int j = 0; j < y; j++)
			mass2[i][j] = Ek[j] * Hj[i] * Oi[1];
		for (int j = 0; j < y; j++)
			mass3[i][j] = Ek[j] * Hj[i] * Oi[2];
		for (int j = 0; j < y; j++)
			mass4[i][j] = Ek[j] * Hj[i] * Oi[3];
	}
	
	float d1 = 0;
	float d2 = 0;
	float d3 = 0;
	float d4 = 0;
	q3 = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			d1 = d1 + (mass1[i][j] * arr20[i][j]);
		for (int j = 0; j < y; j++)
			d2 = d2 + (mass2[i][j] * arr21[i][j]);
		for (int j = 0; j < y; j++)
			d3 = d3 + (mass3[i][j] * arr22[i][j]);
		for (int j = 0; j < y; j++)
			d4 = d4 + (mass4[i][j] * arr23[i][j]);
	}
	q3 = (d1 + d2 + d3 + d4) / 140;
	float q31 = (d1 + d2 + d3 + d4);
	//cout << "Q3 = " << q3 << endl;

	freopen("matrix.txt", "w", stdout);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (arr10[i][j] == 1)
				cout << "1.0" << " ";
			else if (arr10[i][j] == 0)
				cout << "0.0" << " ";
			else
				cout << (float)(arr10[i][j]) << " ";
		}
		cout << "            ";
		for (int j = 0; j < y; j++)
		{
			cout << arr20[i][j] << " ";
		}
		cout << "            ";
		for (int j = 0; j < y; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (arr11[i][j] == 1)
				cout << "1.0" << " ";
			else if (arr11[i][j] == 0)
				cout << "0.0" << " ";
			else
				cout << arr11[i][j] << " ";
		}
		cout << "            ";
		for (int j = 0; j < y; j++)
		{
			cout << arr21[i][j] << " ";
		}
		cout << "            ";
		for (int j = 0; j < y; j++)
		{
			cout << arr1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (arr12[i][j] == 1)
				cout << "1.0" << " ";
			else if (arr12[i][j] == 0)
				cout << "0.0" << " ";
			else
				cout << arr12[i][j] << " ";
		}
		cout << "            ";
		for (int j = 0; j < y; j++)
		{
			cout << arr22[i][j] << " ";
		}
		cout << "            ";
		for (int j = 0; j < y; j++)
		{
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (arr13[i][j] == 1)
				cout << "1.0" << " ";
			else if (arr13[i][j] == 0)
				cout << "0.0" << " ";
			else
				cout << arr13[i][j] << " ";
		}
		cout << "            ";
		for (int j = 0; j < y; j++)
		{
			cout << arr23[i][j] << " ";
		}
		cout << "            ";
		for (int j = 0; j < y; j++)
		{
			cout << arr3[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Q1 = " << q1 << "                          Q2 = " << q3 << "  Q2.1 = " << q31 << "            Q3 = " << q2 << endl;
	cout << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << mass1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << mass2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << mass3[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << mass4[i][j] << " ";
		}
		cout << endl;
	}
	fclose(stdout);

	return EXIT_SUCCESS;
}

float mark(float mark)
{
	int result = 0;
	if (mark > 0.88)
		result = 5;
	else if (mark > 0.68 && mark <= 0.88)
		result = 4;
	else if (mark >= 0.5 && mark <= 0.68)
		result = 3;
	else if (mark >= 0.3 && mark < 0.5)
		result = 2;
	else if (mark >= 0 && mark < 0.3)
		result = 1;

	return result;
}

float mark2(float mark)
{
	int result = 0;
	if (mark >= 0 && mark <= 0.5)
		result = 0;
	else if (mark > 0.5)
		result = 1;
	return result;
}