/*
 * nvic_types.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_
#define TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_



typedef enum
{

    GPIO_Port_A_Int,
    GPIO_Port_B_Int,
    GPIO_Port_C_Int,
    GPIO_Port_D_Int,
    GPIO_Port_E_Int,
    UART0_Int,
    UART1_Int,
    SSI0_Int,
    I2C0_Int,
    PWM0_Fault_Int,
    PWM0_Generator_0_Int,
    PWM0_Generator_1_Int,
    PWM0_Generator_2_Int,
    QEI0_Int,
    ADC0_Sequence_0_Int,
    ADC0_Sequence_1_Int,
    ADC0_Sequence_2_Int,
    ADC0_Sequence_3_Int,
    Sixteen_32_Bit_Timer_0A_Int,
    Sixteen_32_Bit_Timer_0B_Int,
    Sixteen_32_Bit_Timer_1A_Int,
    Sixteen_32_Bit_Timer_1B_Int,
    Sixteen_32_Bit_Timer_2A_Int,
    Sixteen_32_Bit_Timer_2B_Int,
    Analog_Comparator_0_Int,
    Analog_Comparator_1_Int,
    System_Control_Int = 27,
    Flash_Memory_Control_Int,
    GPIO_Port_F_Int,
    UART2_Int = 31,
    SSI1_Int,
    Sixteen_32_Bit_Timer_3A_Int,
    Sixteen_32_Bit_Timer_3B_Int,
    I2C1_Int,
    QEI1_Int,
    CAN0_Int,
    CAN1_Int,
    Hibernation_Module_Int = 40,
    USB_Int,
    PWM_Generator_3_Int,
    DMA_Software_Int,
    DMA_Error_Int,
    ADC1_Sequence_0_Int,
    ADC1_Sequence_1_Int,
    ADC1_Sequence_2_Int,
    ADC1_Sequence_3_Int,
    SSI2_Int = 49,
    SSI3_Int,
    UART3_Int,
    UART4_Int,
    UART5_Int,
    UART6_Int,
    UART7_Int,
    I2C2_Int = 57,
    I2C3_Int,
    Sixteen_32_Bit_Timer_4A_Int,
    Sixteen_32_Bit_Timer_4B_Int,
    Sixteen_32_Bit_Timer_5A_Int = 62,
    Sixteen_32_Bit_Timer_5B_Int,
    Sixteen_64_Bit_Timer_0A_Int,
    Thirty_Two_64_Bit_Timer_0B_Int,
    Thirty_Two_64_Bit_Timer_1A_Int,
    Thirty_Two_64_Bit_Timer_1B_Int,
    Thirty_Two_64_Bit_Timer_2A_Int,
    Thirty_Two_64_Bit_Timer_2B_Int,
    Thirty_Two_64_Bit_Timer_3A_Int,
    Thirty_Two_64_Bit_Timer_3B_Int,
    Thirty_Two_64_Bit_Timer_4A_Int,
    Thirty_Two_64_Bit_Timer_4B_Int,
    Thirty_Two_64_Bit_Timer_5A_Int,
    Thirty_Two_64_Bit_Timer_5B_Int,
    System_Exception_Int,
    PWM1_Generator_0_Int = 78,
    PWM1_Generator_1_Int,
    PWM1_Generator_2_Int,
    PWM1_Generator_3_Int,
    PWM1_Fault
}NVIC_Interrupt_Id_t;


typedef enum
{
    Interrupt_Enable,
    Interrupt_Disable,
}NVIC_Interrupt_Control_t;



typedef enum
{
    EIGHT_GROUPS_ONE_SUB = 0x0,
    FOUR_GROUPS_Two_SUB = 0x5,
    TWO_GROUPS_FOUR_SUB = 0x6,
    ONE_GROUP_EIGHT_SUB = 0x7
}Interrupt_Periority_Select_t;


typedef struct
{
    /*TODO create types to contain Configuration parameters for each Interrupts
     * make sure the following parameters should be visible to static code
     * InterruptNum
     * ENable\Disable
     * Priority Group
     * Sub-priority Group
     * */

    NVIC_Interrupt_Id_t InterruptID ;

    NVIC_Interrupt_Control_t Interrupt_Control ;

    Interrupt_Periority_Select_t Interrupt_Periorty ;x





}NVIC_CfgType;



#endif /* TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_ */
