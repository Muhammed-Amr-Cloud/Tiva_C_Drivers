/*
 * nvic.c
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */


#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
/*TODO include processor.h*/

#include "../../config/nvic_cfg.h"
#include "../mcu_hw.h"
#include "nvic_types.h"
#include "nvic.h"

#define SHIFT_BY_EIGHTD_FOR_INTERRUPT_PERIORITY         8
#define VECT_KEY                                        ((uint32)0xFA050000<< 16)

extern NVIC_CfgType NVIC_CfgArr[];


void NVIC_init(void)
{
    /*TODO : switch to privilege mode - use switch function in processor.h*/


    /*TODO :loop for NVIC_CfgArr configure each Interrupt
     *  as stated in Cfg (Enable/Priority/sub-priority)
     *  */

    NVIC_Interrupt_Id_t Interrupt_Id  ;
    uint8 CfArr_Index   ;
    uint8 PortId        ;
    uint8 Bit_Possition ;


    for(CfArr_Index = 0 ; CfArr_Index <  NVIC_NUM_OF_ENABLED_INT; ++CfArr_Index)
    {
        Interrupt_Id = NVIC_CfgArr[CfArr_Index].InterruptID ;

        PortId = Interrupt_Id / 32 ;

        Bit_Possition = Interrupt_Id % 32 ;

        if(NVIC_CfgArr[CfArr_Index].Interrupt_Control == Interrupt_Enable)
        {   static uint8 Enable_Counter = 0  ;
            if(Enable_Counter <32)
            {
                SET_BIT(NVIC_REG->EN0,Bit_Possition);
                Enable_Counter++;
            }

            else if(Enable_Counter > 31 && Enable_Counter <64)
            {
                SET_BIT(NVIC_REG->EN1,Bit_Possition);
                Enable_Counter++;
            }
            else if (Enable_Counter >63 && Enable_Counter < 96)
            {
                SET_BIT(NVIC_REG->EN2,Bit_Possition);
                Enable_Counter++;

            }
            else if (Enable_Counter > 95 && Enable_Counter < 128)
            {
                SET_BIT(NVIC_REG->EN3,Bit_Possition);
                Enable_Counter++;

            }
            else if (Enable_Counter > 127 && Enable_Counter < 128)
            {
                SET_BIT(NVIC_REG->EN4,Bit_Possition);
                Enable_Counter++;

            }
            else
            {
                Enable_Counter = 0 ;
            }


        }
        else
        {
            static uint8 Enable_Counter = 0  ;
            if(Enable_Counter <32)
            {
                SET_BIT(NVIC_REG->DIS0,Bit_Possition);
                Enable_Counter++;
            }

            else if(Enable_Counter > 31 && Enable_Counter <64)
            {
                SET_BIT(NVIC_REG->DIS1,Bit_Possition);
                Enable_Counter++;
            }
            else if (Enable_Counter >63 && Enable_Counter < 96)
            {
                SET_BIT(NVIC_REG->DIS2,Bit_Possition);
                Enable_Counter++;

            }
            else if (Enable_Counter > 95 && Enable_Counter < 128)
            {
                SET_BIT(NVIC_REG->DIS3,Bit_Possition);
                Enable_Counter++;

            }
            else if (Enable_Counter > 127 && Enable_Counter < 128)
            {
                SET_BIT(NVIC_REG->DIS4,Bit_Possition);
                Enable_Counter++;

            }
            else
            {
                Enable_Counter = 0 ;
            }

        }


        SCB_APINT |=  VECT_KEY |((SCB_APINT & (0x00000700))| NVIC_CfgArr[CfArr_Index].Interrupt_Periorty );

    }

    /*TODO : return to non-privilege mode */

}



