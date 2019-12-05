/*
 * SysCtr_cfg.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_
#define E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_


#define SYSCTR_RCC_PORTA            ENABLE
#define SYSCTR_RCC_PORTB            DISABLE
#define SYSCTR_RCC_PORTC            ENABLE
#define SYSCTR_RCC_PORTD            ENABLE
#define SYSCTR_RCC_PORTE            ENABLE
#define SYSCTR_RCC_PORTF            ENABLE

/*

#define SYSCTR_RCC_PORTA
#define SYSCTR_RCC_PORTA
#define SYSCTR_RCC_PORTA
#define SYSCTR_RCC_PORTA
#define SYSCTR_RCC_PORTA
#define SYSCTR_RCC_PORTA
#define SYSCTR_RCC_PORTA
#define SYSCTR_RCC_PORTA
#define SYSCTR_RCC_PORTA
#define SYSCTR_RCC_PORTA
*/

/*
typedef struct
{
    SysCtr_GPIO_CLOCK_t port_Clock_Control ;


}SysCtr_Configuraion_t;

*/

/*TODO implement suitable container to store the followings
 *
 * which peripheral clock gate Enabled
 * Desired System clock Source
 * Desired System CLock Frequency
 * attached External Crystal freq?
 * */


#endif /* E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_ */
