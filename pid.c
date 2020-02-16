#include"pid.h"



struct PID* PID_init(double* src, double* target, float Kp, float Ki, float Kd)
{
	struct PID* p = (struct PID*)malloc(sizeof(struct PID));

	if (!p)
	{
		return -1;
	}

	p->differential = 0;
	p->error = 0;
	p->integral = 0;
	p->last_error = 0;

	p->Kd = Kd;
	p->Ki = Ki;
	p->Kp = Kp;

	p->src = *src;
	p->target = *target;
	p->result=p->src;

	return p;
}

void PID_controller(struct PID* p)
{
	double index = 1;
	//get error value
	p->error = p->result - p->target;

	//get d_err value
	p->differential = p->last_error - p->error;

	// islate i_err

	if (fabs(p->error)<1 )
	{
		if (p->result < 0)
		{
			index = -1;
		}
		else
		{
			index = 1;
		}
		p->integral += p->error;

	}

	//get new src value
	p->result -= (p->Kp * p->error + p->Kd * p->differential + index * p->Ki * p->integral);

	//for next d_err
	p->last_error = p->error;

}
	





