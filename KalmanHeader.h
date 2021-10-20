#include <iostream>
#include <string>
#include <iomanip> //Formatting output
#include <sstream> //String stream library
#include <vector>
#include <fstream>
using namespace std;


//Kalman filter header
double KALMAN(double U)
{
	//Defining the constants
	static const double R = 500; //Noise covariance
	static const double H = 1.00; //Measurement scalar
	static double Q = 10; //Initially estimated covariance
	static double P = 0; //Error covariance
	static double U_hat = 0; //Initially estimated state
	static double K = 0; //Kalman gain

	K = (P * H) / (H * P * H + R); //Update the kalman gain
	U_hat = U_hat + K * (U - H * U_hat); //Update estimated state

	P = (1 - K * H) * P + Q; //Update error covariance

	return U_hat;

}