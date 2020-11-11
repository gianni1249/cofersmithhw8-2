#include <string>
#include "AnalogIn.h"
#include <iostream>
using namespace std;


float getResistance(int adc_value) {     
	           float cur_voltage = adc_value * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
		   float R2 = (cur_voltage * 10000)/(1.80f - cur_voltage);
	           return R2;
}

int main(){

	cout << "Using AIN0 to read analog value." << endl;
	AnalogIn AIN(0);
	AIN.getNumber();
	AIN.setNumber(0);
	AIN.readADCsample();
	cout << "Measuring resistance ..." << endl;
	cout << "ADC value is: " << AIN.readADCsample() << endl;
	float Resistance  = getResistance(AIN.readADCsample());
	cout << "Resistance: " << Resistance << " Ohms " <<  endl;




}

