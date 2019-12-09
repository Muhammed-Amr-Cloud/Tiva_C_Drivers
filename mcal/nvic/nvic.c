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
    uint8 Periority_Selection = 0 ;
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



        SCB_APINT |=  VECT_KEY |((SCB_APINT & (0x00000700))| (NVIC_CfgArr[CfArr_Index].Interrupt_Periorty<< SHIFT_BY_EIGHTD_FOR_INTERRUPT_PERIORITY));



        switch(Periority_Selection)
        {
            static uint8 Periority_Counter     = 1;
            static uint8 sub_Periority_Counter = 1;

            case 0:
            case 1:
            case 2:
            case 3:
                NVIC_REG->PRI0 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ; //(4*4+13) ->NICE
                Periority_Counter++;
                sub_Periority_Counter += 4 ;

                Periority_Selection++;
                break;

            case 4:
            case 5:
            case 6:
            case 7:
                sub_Periority_Counter = 0  ;
                Periority_Counter     = 0  ;

                NVIC_REG->PRI1 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                Periority_Counter++;
                sub_Periority_Counter += 4 ;
                Periority_Selection++;
                break;

            case 8:
            case 9:
            case 10:
            case 11:
                sub_Periority_Counter = 0  ;
                Periority_Counter     = 0  ;

                NVIC_REG->PRI2 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                Periority_Counter++;
                sub_Periority_Counter += 4 ;
                Periority_Selection++;
                break;

            case 12:
            case 13:
            case 14:
            case 15:
                sub_Periority_Counter = 0  ;
                Periority_Counter     = 0  ;

                NVIC_REG->PRI3 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                Periority_Counter++;
                sub_Periority_Counter += 4 ;
                Periority_Selection++;
                break;
            case 16:
            case 17:
            case 18:
            case 19:
                sub_Periority_Counter = 0  ;
                Periority_Counter     = 0  ;

                NVIC_REG->PRI4 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                Periority_Counter++;
                sub_Periority_Counter += 4 ;
                Periority_Selection++;
                break;

             case 20:
             case 21:
             case 22:
             case 23:
                 sub_Periority_Counter = 0  ;
                 Periority_Counter     = 0  ;

                 NVIC_REG->PRI5 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                 Periority_Counter++;
                 sub_Periority_Counter += 4 ;
                 Periority_Selection++;
                 break;

             case 24:
             case 25:
             case 26:
             case 27:
                 sub_Periority_Counter = 0  ;
                 Periority_Counter     = 0  ;

                 NVIC_REG->PRI6 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                 Periority_Counter++;
                 sub_Periority_Counter += 4 ;
                 Periority_Selection++;
                 break;

             case 28:
             case 29:
             case 30:
             case 31:
                 sub_Periority_Counter = 0  ;
                 Periority_Counter     = 0  ;

                 NVIC_REG->PRI7 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                 Periority_Counter++;
                 sub_Periority_Counter += 4 ;
                 Periority_Selection++;
                  break;

             case 32:
             case 33:
             case 34:
             case 35:
                 sub_Periority_Counter = 0  ;
                 Periority_Counter     = 0  ;

                 NVIC_REG->PRI8 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                 Periority_Counter++;
                 sub_Periority_Counter += 4 ;
                 Periority_Selection++;
                 break;

             case 36:
             case 37:
             case 38:
             case 39:
                 sub_Periority_Counter = 0  ;
                 Periority_Counter     = 0  ;

                 NVIC_REG->PRI9 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                 Periority_Counter++;
                 sub_Periority_Counter += 4 ;
                 Periority_Selection++;
                 break;

             case 40:
             case 41:
             case 42:
             case 43:
                 sub_Periority_Counter = 0  ;
                 Periority_Counter     = 0  ;

                 NVIC_REG->PRI10 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                 Periority_Counter++;
                 sub_Periority_Counter += 4 ;
                 Periority_Selection++;
                 break;

             case 44:
             case 45:
             case 46:
             case 47:
                 sub_Periority_Counter = 0  ;
                 Periority_Counter     = 0  ;

                 NVIC_REG->PRI11 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                 Periority_Counter++;
                 sub_Periority_Counter += 4 ;
                 Periority_Selection++;
                 break;

             case 48:
             case 49:
             case 50:
             case 51:
                 sub_Periority_Counter = 0  ;
                 Periority_Counter     = 0  ;

                 NVIC_REG->PRI12 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                 Periority_Counter++;
                 sub_Periority_Counter += 4 ;
                 Periority_Selection++;
                 break;

             case 52:
             case 53:
             case 54:
             case 55:
                 sub_Periority_Counter = 0  ;
                 Periority_Counter     = 0  ;

                 NVIC_REG->PRI13 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                 Periority_Counter++;
                 sub_Periority_Counter += 4 ;
                 Periority_Selection++;
                  break;
             case 56:
             case 57:
             case 58:
             case 59:
                 sub_Periority_Counter = 0  ;
                 Periority_Counter     = 0  ;

                 NVIC_REG->PRI14 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                 Periority_Counter++;
                 sub_Periority_Counter += 4 ;
                 Periority_Selection++;
                 break;

             case 60:
             case 61:
             case 62:
             case 63:
                 sub_Periority_Counter = 0  ;
                 Periority_Counter     = 0  ;

                 NVIC_REG->PRI15 = ((NVIC_CfgArr[CfArr_Index].Interrupt_Sub_Periority & (0x07))<< ((4*Periority_Counter) + sub_Periority_Counter))  ;
                 Periority_Counter++;
                 sub_Periority_Counter += 4 ;
                 Periority_Selection++;
              break;

             default :
                 Periority_Selection = 0 ;
                 break;


        }



    }

    /*TODO : return to non-privilege mode */

}



