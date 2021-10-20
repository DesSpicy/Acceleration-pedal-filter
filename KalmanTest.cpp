
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "KalmanHeader.h"

double NOISY[5000];
double FILTERED[5000];

int main()
{
	string A1;
	vector <double> U_N;
	//number of lines
	int i = 0;
	ifstream KFdata;
	KFdata.open("BigPot.txt");

	if (KFdata.is_open())
	{
		while (!KFdata.eof()) //while the end of the file is NOT reached
		{
			getline(KFdata, A1, '\n');
			U_N.push_back(stod(A1));
			i += 1;
		}
		KFdata.close(); //close file
		cout << "Number of entries: " << i << endl << endl;
	}
	else
	{
		cerr << "Error Opening File!!" << endl;
	}
	
	//initialize 1 array "NOISY" stores all noisy values in array format
	//double NOISY[2258];
	copy(U_N.begin(), U_N.end(), NOISY);
	////////////////////////////////////////////////////////////////////////////////

	//Beginning of filter, filtering one number at a time
	//double FILTERED[2258];
	
	ofstream Results;
	Results.open("Results.txt");
	for (int c = 0; c < i; c++)
	{
		FILTERED[c] = KALMAN(NOISY[c]);
		Results << FILTERED[c] << endl;
	}
	Results.close();
	

}