#include "RobotMain.h"

RDK::EncodingMotor encodingMotor1;
RDK::EncodingMotor encodingMotor2;
RDK::EncodingMotor encodingMotor3;
RDK::EncodingMotor encodingMotor4;
RDK::MecanumMotion mecanumMotion;

void Motor1Callback(double pwm)
{
    if (pwm > 0) {
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, pwm);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
    } else{
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, -pwm);
    }
}
void Motor3Callback(double pwm)
{
    if (pwm > 0) {
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, pwm);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, 0);
    } else{
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, 0);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, -pwm);
    }
}
void Motor2Callback(double pwm)
{
    if (pwm > 0) {
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, pwm);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 0);
    } else{
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, -pwm);
    }
}
void Motor4Callback(double pwm)
{
    if (pwm > 0) {
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_3, pwm);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, 0);
    } else{
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_3, 0);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, -pwm);
    }
}

void RobotTest()
{
    mecanumMotion.Move(0.1, 800, 0);
    mecanumMotion.Move(0.1, 0, 800);
    mecanumMotion.Move(0.1, -800, 0);
    mecanumMotion.Move(0.1, 0, -800);
};

void RobotInit()
{
    encodingMotor1.SetPID(70, 500, 120);
    encodingMotor1.SetOutputRange(-1000, 1000);
    encodingMotor1.SetSpeed(0);//单位脉冲数
    encodingMotor1.SetCallback(Motor1Callback);

    encodingMotor2.SetPID(70, 500, 120);
    encodingMotor2.SetOutputRange(-1000, 1000);
    encodingMotor2.SetSpeed(0);//单位脉冲数
    encodingMotor2.SetCallback(Motor2Callback);
    encodingMotor2.SetReverse(true);

    encodingMotor3.SetPID(70, 500, 120);
    encodingMotor3.SetOutputRange(-1000, 1000);
    encodingMotor3.SetSpeed(0);//单位脉冲数
    encodingMotor3.SetCallback(Motor3Callback);

    encodingMotor4.SetPID(70, 500, 120);
    encodingMotor4.SetOutputRange(-1000, 1000);
    encodingMotor4.SetSpeed(0);//单位脉冲数
    encodingMotor4.SetCallback(Motor4Callback);
    encodingMotor4.SetReverse(true);

    mecanumMotion.SetEncodingMotor1(&encodingMotor1);
    mecanumMotion.SetEncodingMotor2(&encodingMotor2);
    mecanumMotion.SetEncodingMotor3(&encodingMotor3);
    mecanumMotion.SetEncodingMotor4(&encodingMotor4);

};

void RobotTick() {
    short speed = 0;

    speed = (short) __HAL_TIM_GET_COUNTER(&htim3);
    __HAL_TIM_SET_COUNTER(&htim3, 0);
    encodingMotor1.AddPulse(speed);
    encodingMotor1.Tick();

    speed = (short) __HAL_TIM_GET_COUNTER(&htim5);
    __HAL_TIM_SET_COUNTER(&htim5, 0);
    encodingMotor2.AddPulse(speed);
    encodingMotor2.Tick();

    speed = (short) __HAL_TIM_GET_COUNTER(&htim2);
    __HAL_TIM_SET_COUNTER(&htim2, 0);
    encodingMotor3.AddPulse(speed);
    encodingMotor3.Tick();

    speed = (short) __HAL_TIM_GET_COUNTER(&htim4);
    __HAL_TIM_SET_COUNTER(&htim4, 0);
    encodingMotor4.AddPulse(speed);
    encodingMotor4.Tick();
};