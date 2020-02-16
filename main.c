#include"pid.h"
#include<time.h>

//parameters for PID
#define KP 0.75
#define KI 0.175
#define KD 0.035

//target value
const double target = 500;



int main()
{
	//set random number seed
	srand((unsigned int)time(0));

	double src;

	//set a sample value
	src = rand()%200;

	//input the original value
	/*if (scanf_s("%lf", &src) != 1)
	{
		return -1;
	}
	*/

	struct PID* p = PID_init(&src, &target, KP, KI, KD);

	printf_s("%f\n", src);
	//simulate a loop
	for (int times = 1;; times++)
	{
		//pid control
		PID_controller(p);

		//print every temp value
		printf_s("%1.9f\n",p->result);

		//end the loop
		if (fabs(p->result - target) < 1e-6)
		{
			//output for modification
			printf_s("使用了%d次PID调节\n", times);

			//free the RAM
			free(p);

			break;
		}

		//simulate a error caused by mechine
		p->result += 1e-6 * ((rand() % 20)+1-10);
	}

	return 0;
}