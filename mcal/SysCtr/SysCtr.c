/*
 * SysCtr.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcu_hw.h"
#include "../../config/SysCtr_cfg.h"
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"

/*TODO include SysCtr_cfg.h*/

void SysCtr_init(void)
{
    /*TODO Enable configured Peripherals CLock gates*/

    RCGCGPIO_REG.R0 = SYSCTR_RCC_PORTA ;
    RCGCGPIO_REG.R1 = SYSCTR_RCC_PORTB ;
    RCGCGPIO_REG.R2 = SYSCTR_RCC_PORTC ;
    RCGCGPIO_REG.R3 = SYSCTR_RCC_PORTD ;
    RCGCGPIO_REG.R4 = SYSCTR_RCC_PORTE ;
    RCGCGPIO_REG.R5 = SYSCTR_RCC_PORTF ;




    /*TODO Set System CLock Source as configured*/

    /*TODO set CLock Frequency as configured -
     * use Figure 5-5. Main Clock Tree Page.222 in DATASHEET as reference.
     * */



}
uint32 SysCtr_getSysClockFreq(void)
{
    /*TODO return the current system clock frequency */

}

