#pragma once

#include<stdio.h>
#include<stdlib.h>


typedef struct ControllerData
{
	float Kp;
	float Ki;
	float Kd;

	float target;
	float curentValue;
	float lastValue;
	float IValue;
	int isIsolated;

}Config;

Config* init(float target, const float Kp, const float Ki, const float Kd);

float fit(float inputValue,Config* controller);