//To used this file, please include in the project the BitOperations.h file;


//============ AT90CAN ========================================================================//
//============= UART0============= //
#define BAUD_RATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUD_RATE * 16UL))) - 1)



#define USART1_TX_ENABLE B1(UCSR1B,TXEN1)
#define USART1_RX_ENABLE B1(UCSR1B,RXEN1)
#define USART1_MODE_ASYNCRONOUS B0(UCSR1C,UMSEL1)
#define USART1_MODE_SYNCRONOUS	B1(UCSR1C,UMSEL1)
#define USART1_PARITY_DISABLED	B0(UCSR1C,UPM11);B0(UCSR1C,UPM10)
#define USART1_PARITY_EVEN			B1(UCSR1C,UPM11);B0(UCSR1C,UPM10)
#define USART1_PARITY_ODD			B1(UCSR1C,UPM11);B1(UCSR1C,UPM10)
#define UASRT1_1_BIT	B0(UCSR1C,UMSEL1)
#define UASRT1_2_BIT	B1(UCSR1C,UMSEL1)
#define UASRT1_CHAR_SIZE_5_BITS B0(UCSR1C,UCSZ12); B0(UCSR1C,UCSZ11); B0(UCSR1C,UCSZ10)
#define UASRT1_CHAR_SIZE_6_BITS B0(UCSR1C,UCSZ12); B0(UCSR1C,UCSZ11); B1(UCSR1C,UCSZ10)
#define UASRT1_CHAR_SIZE_7_BITS B0(UCSR1C,UCSZ12); B1(UCSR1C,UCSZ11); B0(UCSR1C,UCSZ10)
#define UASRT1_CHAR_SIZE_8_BITS B0(UCSR1C,UCSZ12); B1(UCSR1C,UCSZ11); B1(UCSR1C,UCSZ10)
#define UASRT1_CHAR_SIZE_9_BITS B1(UCSR1C,UCSZ12); B1(UCSR1C,UCSZ11); B1(UCSR1C,UCSZ10)

void UART1_Init()
{
	USART1_TX_ENABLE;
	USART1_RX_ENABLE;
	USART1_MODE_ASYNCRONOUS;
	USART1_PARITY_DISABLED;
	UASRT1_1_BIT;
	UASRT1_CHAR_SIZE_8_BITS;
UBRR1L = BAUD_PRESCALER;// Load lower 8-bits into the low byte of the UBRR register
UBRR1H = (BAUD_PRESCALER >> 8);

  
}
// function to send data
void USART1_Transmit (unsigned char data)
{
	/* Wait for empty transmit buffer */
	while ( ! ( UCSR1A & (1<<UDRE1)));
	/* Put data into buffer, sends the data */
	UDR1 = data;
}

void USART1_Transmit9bits (unsigned int data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR1A & (1<<UDRE1)));
	/* Copy 9th bit to TXB8 */
	UCSR1B &= ~(1<<TXB81);
	if ( data & 0x0100 )
	UCSR1B |= (1<<TXB81);
	/* Put data into buffer, sends the data */
	UDR1 = data;
}

unsigned char USART1_Receive (void)
{
	/* Wait for data to be received */
	while ( ! (UCSR1A & (1<<RXC1)));
	/* Get and return received data from buffer */
	return UDR1;
}

// unsigned int USART1_ReceiveHeader(void)
// {
// 	unsigned char status, resh, resl;
// 	/* Wait for data to be received */
// 	while ( ! (UCSR1A & (1<<RXC1)));
// 	/* Get status and 9th bit, then data */
// 	/* from buffer */
// 	status = UCSR1A;
// 	resh = UCSR1B;
// 	resl = UDR1;
// 	/* If error, return -1 */
// 	if ( status & (1<<FE1)|(1<<DOR1)|(1<<UPE1) )
// 	return -1;
// 	/* Filter the 9th bit, then return */
// 	resh = (resh >> 1) & 0x01;
// 	return ((resh << 8) | resl);
// }	

// void USART0_Flush (void)
// {
// 	unsigned char dummy;
// 	while (UCSR1A & (1<<RXC1) ) dummy = UDR1;
// }
	
	
	void uart_print4( uint8_t nibble){
		nibble &= 0b00001111;

		if( nibble <= 0x09 ){
			USART1_Transmit(nibble + 0x30);
			} else {
			USART1_Transmit((nibble - 0x0A) + 0x41);
		}
	}
	
	//prints a byte (8 bits) in hexadecimal
	//  uint8_t uart - which uart to send on
	//  uint8_t val - the byte to print
	void uart_print8(uint8_t val){
		uart_print4( val >> 4);
		uart_print4( val);
	}

	//prints a "word" (16 bits) in hexadecimal
	//  uint8_t uart - which uart to send on
	//  uint16_t val - the "word" to print
	void uart_print16(uint16_t val){
		uart_print8(val >> 8);
		uart_print8(val);
	}


