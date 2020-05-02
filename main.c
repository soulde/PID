#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"PIDController.h"

#define KP 0.45
#define KI 0.05
#define KD 0.07

#define TARGET 100

float simulator(float power,int isLinear)
{
	srand((unsigned)time(NULL));
	float error1 = (rand() % 200 * 0.01 - 1) * 0.1;
	float error2 = (rand() % 200 * 0.01 - 1) * 0.07;
	static float output ;
	const float mechaneff = 1.7;

	power += error2;
	if (isLinear) 
	{
		output += power * mechaneff;
	}
	else {
		output += power * power * mechaneff / 1.2 + power * mechaneff * 0.6;
	}


	return output + error1;
}


int main()
{
	float power = 0;
	float output = 0;
	Config* controller = init(TARGET, KP, KI, KD);
	
	for (;;) {
		power = fit(output, controller);
		output = simulator(power, 1);

		printf_s("%f\n", output);
		if (output - TARGET<0.001 && output - TARGET>-0.001)
			break;
		system("pause");
	}
	printf_s("success!!");

	return 0;
}