/*
 * attitude_pid.c
 *
 *  Created on: Jul 30, 2025
 *      Author: tcast
 */
#include "attitude_pid.h"

void PID_Init(PID_Controller *pid, float Kp, float Ki, float Kd, float output_limit, float integral_limit)
{
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->prev_error = 0.0f;
    pid->integral = 0.0f;
    pid->output_limit = output_limit;
    pid->integral_limit = integral_limit;
}

float PID_Compute(PID_Controller *pid, float setpoint, float measurement, float dt)
{
    float error = setpoint - measurement;
    pid->integral += error * dt;

    // ✅ Integral windup protection
    if (pid->integral > pid->integral_limit) pid->integral = pid->integral_limit;
    else if (pid->integral < -pid->integral_limit) pid->integral = -pid->integral_limit;

    float derivative = (error - pid->prev_error) / dt;
    pid->prev_error = error;

    float output = (pid->Kp * error) + (pid->Ki * pid->integral) + (pid->Kd * derivative);

    // ✅ Output clamp
    if (output > pid->output_limit) output = pid->output_limit;
    else if (output < -pid->output_limit) output = -pid->output_limit;

    return output;
}


