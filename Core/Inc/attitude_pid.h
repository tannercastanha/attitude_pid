/*
 * attitude_pid.h
 *
 *  Created on: Jul 30, 2025
 *      Author: tcast
 */

#ifndef INC_ATTITUDE_PID_H_
#define INC_ATTITUDE_PID_H_

#ifndef ATTITUDE_PID_H
#define ATTITUDE_PID_H

typedef struct {
    float Kp;
    float Ki;
    float Kd;

    float prev_error;
    float integral;

    float output_limit;       // Max output (e.g. 500.0)
    float integral_limit;     // Max integral term (optional but recommended)
} PID_Controller;

/**
 * @brief Initialize a PID controller.
 */
void PID_Init(PID_Controller *pid, float Kp, float Ki, float Kd, float output_limit, float integral_limit);

/**
 * @brief Compute PID output.
 */
float PID_Compute(PID_Controller *pid, float setpoint, float measurement, float dt);

#endif // ATTITUDE_PID_H



#endif /* INC_ATTITUDE_PID_H_ */
