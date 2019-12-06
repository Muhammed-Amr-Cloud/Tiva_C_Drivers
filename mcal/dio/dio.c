/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "dio_types.h"
#include "../mcu_hw.h"
/*TODO: include the header file that contains register definitions */

#include "dio.h"

Std_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Std_levelType ret;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*TODO: Return the level value of given Channel */

    switch(PortId)
    {
        case Dio_Port_A :
             ret = GET_BIT(PORTA_BaseAddr->GPIODATA,ChannelPos) ;
                     break;

        case Dio_Port_B :
            ret = GET_BIT(PORTB_BaseAddr->GPIODATA,ChannelPos) ;
                    break;

        case Dio_Port_C :
            ret = GET_BIT(PORTC_BaseAddr->GPIODATA,ChannelPos) ;
                    break;

        case Dio_Port_D :
            ret = GET_BIT(PORTD_BaseAddr->GPIODATA,ChannelPos) ;
                    break;

        case Dio_Port_E :
            ret = GET_BIT(PORTE_BaseAddr->GPIODATA,ChannelPos) ;
                    break;

        case Dio_Port_F :
            ret = GET_BIT(PORTF_BaseAddr->GPIODATA,ChannelPos) ;
                    break;

        default         :
                    break;

    }


    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Std_levelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;


    switch(PortId)
    {


    case Dio_Port_A :
        if(Level == STD_high)
        {
            SET_BIT(PORTA_BaseAddr->GPIODATA,ChannelPos);

        }
        else
        {
            CLR_BIT(PORTA_BaseAddr->GPIODATA,ChannelPos);

        }
        break;

    case Dio_Port_B :
        if(Level == STD_high)
        {
            SET_BIT(PORTB_BaseAddr->GPIODATA,ChannelPos);

        }
        else
        {
            CLR_BIT(PORTB_BaseAddr->GPIODATA,ChannelPos);

        }
        break;
    case Dio_Port_C :
        if(Level == STD_high)
        {
            SET_BIT(PORTC_BaseAddr->GPIODATA,ChannelPos);
        }
        else
        {
            CLR_BIT(PORTC_BaseAddr->GPIODATA,ChannelPos);
        }
        break;
    case Dio_Port_D :
        if(Level == STD_high)
        {
            SET_BIT(PORTD_BaseAddr->GPIODATA,ChannelPos);

        }
        else
        {

            CLR_BIT(PORTD_BaseAddr->GPIODATA,ChannelPos);
        }
        break;

    case Dio_Port_E :
        if(Level == STD_high)
        {
            SET_BIT(PORTE_BaseAddr->GPIODATA,ChannelPos);
        }
        else
        {
            CLR_BIT(PORTE_BaseAddr->GPIODATA,ChannelPos);
        }
        break;
    case Dio_Port_F :
        if(Level == STD_high)
        {
            SET_BIT(PORTF_BaseAddr->GPIODATA,ChannelPos);
        }
        else
        {
            CLR_BIT(PORTF_BaseAddr->GPIODATA,ChannelPos);
        }
        break;


    default:
        break;


    }

    /*TODO: Write the input value in the corresponding ChannelId */
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;

    /*TODO: Return the Port Value*/
    switch(PortId)
    {

        case Dio_Port_A:

            ret = PORTA_BaseAddr->GPIODATA ;
            break;
        case Dio_Port_B:

                ret = PORTB_BaseAddr->GPIODATA ;
                break;
        case Dio_Port_C:

                ret = PORTC_BaseAddr->GPIODATA ;
                break;
        case Dio_Port_D:

                ret = PORTD_BaseAddr->GPIODATA ;
                break;
        case Dio_Port_E:

                ret = PORTE_BaseAddr->GPIODATA ;
                break;

        case Dio_Port_F:

                  ret = PORTF_BaseAddr->GPIODATA ;
                    break;
        default:
                break;
    }
    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{

    switch(PortId)
        {

        case Dio_Port_A:

            PORTA_BaseAddr->GPIODATA =  value;
            break;
        case Dio_Port_B:

            PORTB_BaseAddr->GPIODATA =  value;
                break;
        case Dio_Port_C:

            PORTC_BaseAddr->GPIODATA =  value;
                break;
        case Dio_Port_D:

            PORTD_BaseAddr->GPIODATA =  value;
                break;
        case Dio_Port_E:

            PORTE_BaseAddr->GPIODATA =  value;
                break;
        case Dio_Port_F:

            PORTF_BaseAddr->GPIODATA =  value;
                break;

        }
           /*TODO: Write the input value in the corresponding PortId */
}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    /* TODO: toggle the corresponding ChannelId */


}
void Dio_FlipPort(Dio_PortType PortId)
{
    /*TODO: toggle the port value */

}



