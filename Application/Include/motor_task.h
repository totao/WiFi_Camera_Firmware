/*
***************************************************************************************************
*                            Motor Control Task
*
* File   : motor_task.h
* Author : Douglas Xie
* Date   : 2017.10.27
***************************************************************************************************
* Copyright (C) 2017 Douglas Xie.  All rights reserved.
***************************************************************************************************
*/

#ifndef USE_DEMO_VERSION

#ifndef  MOTOR_TASK
#define  MOTOR_TASK

/* Include Head Files ---------------------------------------------------------------------------*/
#include "global_config.h"

/* Macro Define ---------------------------------------------------------------------------------*/
#define MOTOR_TASK_PERIOD   (10 / portTICK_PERIOD_MS)

/* Motor step pwm timer define */
#define MOTOR_TIMER         TIM6
#define hmotor_timer        htim6
#define MOTOR_TIMER_FREQ    1000000UL   /* Timer base frquency 1MHz */
#if defined(STM32F410Rx)
#define MOTOR_TIMER_PRES    100         /* Timer prescaler */
#elif defined(STM32F437xx)
#define MOTOR_TIMER_PRES    180         /* Timer prescaler */
#else
#error "motor_task.h missing MOTOR_TIMER_PERS"
#endif

/* Motor enable pins define */
#define MOTOR_EN_CH1        MOTOR_EN1_GPIO_Port, MOTOR_EN1_Pin
#define MOTOR_EN_CH2        MOTOR_EN2_GPIO_Port, MOTOR_EN2_Pin
#define MOTOR_EN_CH3        MOTOR_EN3_GPIO_Port, MOTOR_EN3_Pin
#define MOTOR_EN_CH4        MOTOR_EN4_GPIO_Port, MOTOR_EN4_Pin
#define MOTOR_EN_CH5        MOTOR_EN5_GPIO_Port, MOTOR_EN5_Pin
/* Motor direction pins define */
#define MOTOR_DIR_CH1       MOTOR_DIR1_GPIO_Port, MOTOR_DIR1_Pin
#define MOTOR_DIR_CH2       MOTOR_DIR2_GPIO_Port, MOTOR_DIR2_Pin
#define MOTOR_DIR_CH3       MOTOR_DIR3_GPIO_Port, MOTOR_DIR3_Pin
#define MOTOR_DIR_CH4       MOTOR_DIR4_GPIO_Port, MOTOR_DIR4_Pin
#define MOTOR_DIR_CH5       MOTOR_DIR5_GPIO_Port, MOTOR_DIR5_Pin
/* Motor step pins define */
#define MOTOR_STEP_CH1      MOTOR_STEP1_GPIO_Port, MOTOR_STEP1_Pin
#define MOTOR_STEP_CH2      MOTOR_STEP2_GPIO_Port, MOTOR_STEP2_Pin
#define MOTOR_STEP_CH3      MOTOR_STEP3_GPIO_Port, MOTOR_STEP3_Pin
#define MOTOR_STEP_CH4      MOTOR_STEP4_GPIO_Port, MOTOR_STEP4_Pin
#define MOTOR_STEP_CH5      MOTOR_STEP5_GPIO_Port, MOTOR_STEP5_Pin

/* Pins general output control interface */
#define Motor_OutputLow(x)      HAL_GPIO_WritePin(x, GPIO_PIN_RESET)
#define Motor_OutputHigh(x)     HAL_GPIO_WritePin(x, GPIO_PIN_SET)
#define Motor_OutputToggle(x)   HAL_GPIO_TogglePin(x)
/* Enable pins control interface */
#define Motor_TurnEnable(x)     HAL_GPIO_WritePin(x, GPIO_PIN_RESET)
#define Motor_TurnDisable(x)    HAL_GPIO_WritePin(x, GPIO_PIN_SET)
/* Direction pins control interface */
#define Motor_TurnLeft(x)       HAL_GPIO_WritePin(x, GPIO_PIN_SET)
#define Motor_TurnRight(x)      HAL_GPIO_WritePin(x, GPIO_PIN_RESET)

#define MOTOR_DEFAULT_DIR       'R'
#define MOTOR_DEFAULT_FREQ      1000     /* 1kHz */
#define MOTOR_DEFAULT_STEP      200      /* unit step for feed 1 unit */

#define MOTOR_DEFAULT_PERIOD    5000     /* 10MHz / 5000 / 2 = 1kHz */

/* Data Type Define -----------------------------------------------------------------------------*/
typedef struct
{
    uint8_t  enable;
    uint8_t  direction;
    uint16_t step;
    uint16_t period;
} Motor_Control_t;

typedef struct
{
    uint16_t timer_period;
    Motor_Control_t motor1;
    Motor_Control_t motor2;
    Motor_Control_t motor3;
    Motor_Control_t motor4;
    Motor_Control_t motor5;
} Motor_Group_t;

typedef enum
{
    MOTOR_RUN_CH1 = 1,
    MOTOR_RUN_CH2,
    MOTOR_RUN_CH3,
    MOTOR_RUN_CH4,
    MOTOR_RUN_CH5,
    MOTOR_IDLE
} Motor_State_t;

/* Function Declaration -------------------------------------------------------------------------*/

/*******************************************************************************
* @Brief   Motor Control Task
* @Param   
* @Note    
* @Return  
*******************************************************************************/
void Motor_ControlTask(void * argument);

/*******************************************************************************
* @Brief   Motor Step Control
* @Param   
* @Note    motor step control signal generation in timer IRQ handler
* @Return  
*******************************************************************************/
void Motor_StepControl_IRQ(void);


#endif /* MOTOR_TASK */
#endif /* USE_DEMO_VERSION */
