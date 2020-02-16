#pragma once

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

struct PID
{
	//PID values
	double error;
	double integral;
	double differential;

	//for differential
	double last_error;

	//PID weights
	float Kp;
	float Ki;
	float Kd;


	double src;
	double target;
	double result;
};
//initialize a PID
struct PID* PID_init(double* src, double* target, float Kp, float Ki, float Kd);

void PID_controller(struct PID* p);