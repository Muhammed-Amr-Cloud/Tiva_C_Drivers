/*
 * nvic_lcfg.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "nvic_cfg.h"
#include "../mcal/nvic/nvic_types.h"



const NVIC_CfgType NVIC_CfgArr[NVIC_NUM_OF_ENABLED_INT]={

   /*TODO Configure each Enabled Interrupt */
{     GPIO_Port_A_Int,      Interrupt_Enable, EIGHT_GROUPS_ONE_SUB, 0x01  },
{     GPIO_Port_B_Int,      Interrupt_Enable, EIGHT_GROUPS_ONE_SUB, 0x01  },
{     GPIO_Port_C_Int,      Interrupt_Enable, EIGHT_GROUPS_ONE_SUB, 0x01  },
{     GPIO_Port_D_Int,      Interrupt_Enable, EIGHT_GROUPS_ONE_SUB, 0x01  },
{     GPIO_Port_E_Int,      Interrupt_Enable, EIGHT_GROUPS_ONE_SUB, 0x01  },
//{     UART0_Int,                         },
//{     UART1_Int,                         },
//{     SSI0_Int,                          },
//{     I2C0_Int,                          },
//{     PWM0_Fault_Int,                    },
//{     PWM0_Generator_0_Int,              },
//{     PWM0_Generator_1_Int,              },
//{     PWM0_Generator_2_Int,              },
//{     QEI0_Int,                          },
//{     ADC0_Sequence_0_Int,               },
//{     ADC0_Sequence_1_Int,               },
//{     ADC0_Sequence_2_Int,               },
//{     ADC0_Sequence_3_Int,               },
//{     Sixteen_32_Bit_Timer_0A_Int,       },
//{     Sixteen_32_Bit_Timer_0B_Int,       },
//{     Sixteen_32_Bit_Timer_1A_Int,       },
//{     Sixteen_32_Bit_Timer_1B_Int,       },
//{     Sixteen_32_Bit_Timer_2A_Int,       },
//{     Sixteen_32_Bit_Timer_2B_Int,       },
//{     Analog_Comparator_0_Int,           },
//{     Analog_Comparator_1_Int,           },
//{     System_Control_Int ,               },
//{     Flash_Memory_Control_Int,          },
//{     GPIO_Port_F_Int,                   },
//{     UART2_Int,                         },
//{     SSI1_Int,                          },
//{     Sixteen_32_Bit_Timer_3A_Int,       },
//{     Sixteen_32_Bit_Timer_3B_Int,       },
//{     I2C1_Int,                          },
//{     QEI1_Int,                          },
//{     CAN0_Int,                          },
//{     CAN1_Int,                          },
//{     Hibernation_Module_Int,            },
//{     USB_Int,                           },
//{     PWM_Generator_3_Int,               },
//{     DMA_Software_Int,                  },
//{     DMA_Error_Int,                     },
//{     ADC1_Sequence_0_Int,               },
//{     ADC1_Sequence_1_Int,               },
//{     ADC1_Sequence_2_Int,               },
//{     ADC1_Sequence_3_Int,               },
//{     SSI2_Int,                          },
//{     SSI3_Int,                          },
//{     UART3_Int,                         },
//{     UART4_Int,                         },
//{     UART5_Int,                         },
//{     UART6_Int,                         },
//{     UART7_Int,                         },
//{     I2C2_Int ,                         },
//{     I2C3_Int,                          },
//{     Sixteen_32_Bit_Timer_4A_Int,       },
//{     Sixteen_32_Bit_Timer_4B_Int,       },
//{     Sixteen_32_Bit_Timer_5A_Int,       },
//{     Sixteen_32_Bit_Timer_5B_Int,       },
//{     Sixteen_64_Bit_Timer_0A_Int,       },
//{     Thirty_Two_64_Bit_Timer_0B_Int,    },
//{     Thirty_Two_64_Bit_Timer_1A_Int,    },
//{     Thirty_Two_64_Bit_Timer_1B_Int,    },
//{     Thirty_Two_64_Bit_Timer_2A_Int,    },
//{     Thirty_Two_64_Bit_Timer_2B_Int,    },
//{     Thirty_Two_64_Bit_Timer_3A_Int,    },
//{     Thirty_Two_64_Bit_Timer_3B_Int,    },
//{     Thirty_Two_64_Bit_Timer_4A_Int,    },
//{     Thirty_Two_64_Bit_Timer_4B_Int,    },
//{     Thirty_Two_64_Bit_Timer_5A_Int,    },
//{     Thirty_Two_64_Bit_Timer_5B_Int,    },
//{     System_Exception_Int,              },
//{     PWM1_Generator_0_Int,              },
//{     PWM1_Generator_1_Int,              },
//{     PWM1_Generator_2_Int,              },
//{     PWM1_Generator_3_Int,              },
//{     PWM1_Fault                         },
};
