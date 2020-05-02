#include "PIDController.h"

Config* init(float target, const float Kp, const float Ki, const float Kd)
{
	Config* p = (Config*)malloc(sizeof(Config));

	p->target = target;

	p->Kp = Kp;
	p->Ki = Ki;
	p->Kd = Kd;

	p->curentValue = 0;
	p->IValue = 0;
	return p;
}

float fit(float inputValue,Config* controller)
{
	float POut = 0;
	float IOut = 0;
	float DOut = 0;

	float error = 0;

	controller->lastValue = controller->curentValue;
	controller->curentValue = controller->target - inputValue;
	error = controller->curentValue - controller->lastValue;

	if (controller->target - controller->curentValue<controller->target*0.14
		&& controller->target - controller->curentValue > controller->target * 0.14)
	{
		controller->isIsolated = 0;
	}
	else {
		controller->isIsolated = 1;
	}

	controller->IValue += inputValue * (1-controller->isIsolated);

	POut = controller->Kp * controller->curentValue;
	IOut = controller->Ki * controller->IValue;
	DOut = controller->Kd * error;

	
	return POut + IOut + DOut;
}
