/*
 * at90.c
 *
 * Created: 22-Sep-15 9:32:38 AM
 *  Author: Lupu TRANSMIT
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "BitOperations_V1.5.h"
//#include "Interruptss_v0.1.h"
//#include "LCD_V3.6.h"
//#include "SPI_V0.1.h"
#include "define.h"
#include "CAN_v0.1.h"
//#include "functions_lib.h"
#include "UART.h"




uint16_t rpm_c;
uint8_t throttle_c;
uint8_t eng_temp_c;
uint8_t air_temp_c;
uint8_t gear_c;
uint8_t speed_c;
uint8_t map_c;
uint8_t maf_c;
uint8_t oilp_c;


int main(void)
{	

	
//CLKPR=0x80;
//CLKPR=0x00;
//declararea porturilor

	OUTPUT	(D,5);
	INPUT	(D,6);
	OUTPUT(G,1);
	SET_PIN_HI(G,1);

CAN_Init();

UART1_Init();
_delay_ms(500);

//LCDShowChar("BlueStreamline",0,0);
	while(1)
	{


if (maf_c==230)
{
	maf_c=0;
}



maf_c++;





read_can_mobs0();
sendToKMS1();
sendToKMS2();
uart_print8(0xAF);

uart_print8(rpmMSB);
USART1_Transmit('t');
uart_print8(rpmLSB);
USART1_Transmit('t');
uart_print8(throttle_posMSB);
USART1_Transmit('t');
uart_print8(throttle_posLSB);
USART1_Transmit('t');
uart_print8(engine_temp);
USART1_Transmit('t');
uart_print8(air_temp);
USART1_Transmit('t');
uart_print8(gear);
USART1_Transmit('t');
uart_print8(map_sensMSB);
USART1_Transmit('t');
uart_print8(map_sensLSB);
USART1_Transmit('t');
uart_print8(maf_c);//status counter
USART1_Transmit('t');
uart_print8(oil_press);
USART1_Transmit('t');
uart_print8(eng_load);
USART1_Transmit('t');
uart_print8(lambda1);
USART1_Transmit('t');
USART1_Transmit('\n');
_delay_ms(20);



      };
	  

//end while

}
