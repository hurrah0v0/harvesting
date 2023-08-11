#include "encoder.h"
#include "tim.h"

int Read_Encoder(unsigned char TIMX)
{
   int Encoder_TIM;    
   switch(TIMX)
	 {
	     case 2:  Encoder_TIM= (short)TIM2 -> CNT;  TIM2 -> CNT=0;break;	
		   case 3:  Encoder_TIM= (short)TIM3 -> CNT;  TIM3 -> CNT=0;break;
       case 4:  Encoder_TIM= (short)TIM4 -> CNT;  TIM4 -> CNT=0;break;	
		   case 5:  Encoder_TIM= (short)TIM5 -> CNT;  TIM5 -> CNT=0;break;
		 
		   default: Encoder_TIM=0;
		 
	 }
	  // if(Encoder_TIM<0)   Encoder_TIM=-Encoder_TIM;          //将编码器读到的数据变为正数
		return Encoder_TIM;
}

uint32_t read_encoder(void)
{
    uint32_t encoderNum = 0;
    encoderNum = (TIM3->CNT); 
    return encoderNum;
}
