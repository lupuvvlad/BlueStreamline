#include <stdbool.h>
	// EEPROM AREA  ///////////////////////////////////////////////////////////
#define AX_MODEL_NUMBER_L           0x00
#define AX_MODEL_NUMBER_H           0x01
#define AX_VERSION                  0x02
#define AX_ID                       0x03
#define AX_BAUD_RATE                0x04
#define AX_RETURN_DELAY_TIME        0x05
#define AX_CW_ANGLE_LIMIT_L         0x06
#define AX_CW_ANGLE_LIMIT_H         0x07
#define AX_CCW_ANGLE_LIMIT_L        0x08
#define AX_CCW_ANGLE_LIMIT_H        0x09
//#define AX_SYSTEM_DATA2             10
#define AX_LIMIT_TEMPERATURE        0x0B
#define AX_DOWN_LIMIT_VOLTAGE       0x0C
#define AX_UP_LIMIT_VOLTAGE         0x0D
#define AX_MAX_TORQUE_L             0x0E
#define AX_MAX_TORQUE_H             0x0F
#define AX_RETURN_LEVEL             0x10
#define AX_ALARM_LED                0x11
#define AX_ALARM_SHUTDOWN           0x12
//#define AX_OPERATING_MODE           19
//#define AX_DOWN_CALIBRATION_L       20
//#define AX_DOWN_CALIBRATION_H       21
//#define AX_UP_CALIBRATION_L         22
//#define AX_UP_CALIBRATION_H         23

	// RAM AREA  //////////////////////////////////////////////////////////////
#define AX_TORQUE_ENABLE            0x18
#define AX_LED                      0x19
#define AX_CW_COMPLIANCE_MARGIN     0x1A
#define AX_CCW_COMPLIANCE_MARGIN    0x1B
#define AX_CW_COMPLIANCE_SLOPE      0x1C
//#define AX_CCW_COMPLIANCE_SLOPE     29
#define AX_GOAL_POSITION_L          0x1E
#define AX_GOAL_POSITION_H          0x1F
#define AX_GOAL_SPEED_L             0x20
#define AX_GOAL_SPEED_H             0x21
#define AX_TORQUE_LIMIT_L           0x22
#define AX_TORQUE_LIMIT_H           0x23
#define AX_PRESENT_POSITION_L       0x24
#define AX_PRESENT_POSITION_H       0x25
#define AX_PRESENT_SPEED_L          0x26
#define AX_PRESENT_SPEED_H          0x27
#define AX_PRESENT_LOAD_L           0x28
#define AX_PRESENT_LOAD_H           0x29
#define AX_PRESENT_VOLTAGE          0x2A
#define AX_PRESENT_TEMPERATURE      0x2B
#define AX_REGISTERED_INSTRUCTION   0x2C
//#define AX_PAUSE_TIME               45
#define AX_MOVING                   0x2E
#define AX_LOCK                     0x2F
#define AX_PUNCH_L                  0x30
#define AX_PUNCH_H                  0x31

    // Status Return Levels ///////////////////////////////////////////////////////////////
#define AX_RETURN_NONE              0x00
#define AX_RETURN_READ              0x01
#define AX_RETURN_ALL               0x02

    // Instruction Set ///////////////////////////////////////////////////////////////
#define AX_PING                     0x01
#define AX_READ_DATA                0x02
#define AX_WRITE_DATA               0x03
#define AX_REG_WRITE                0x04
#define AX_ACTION                   0x05
#define AX_RESET                    0x06
#define AX_SYNC_WRITE               0x83

	// Specials ///////////////////////////////////////////////////////////////
#define OFF                         0x00
#define ON                          0x01
#define LEFT						0x00
#define RIGHT                       0x01
#define AX_BYTE_READ                0x01
#define AX_BYTE_READ_POS            0x02
#define AX_RESET_LENGTH				0x02
#define AX_ACTION_LENGTH			0x02
#define AX_ID_LENGTH                0x04
#define AX_BD_LENGTH                0x04
#define AX_TEM_LENGTH               0x04
#define AX_VOLT_LENGTH              0x04
#define AX_LED_LENGTH               0x04
#define AX_TORQUE_LENGTH            0x05
#define AX_TORQUE_MAX_LENGTH		0x05
#define AX_ALARM_LENGTH				0x04
#define AX_POS_LENGTH               0x04
#define AX_LOAD_LENGTH				0x04
#define AX_RETURN_LENGTH			0x04
#define AX_SPEED_LENGTH				0x05
#define AX_GOAL_LENGTH              0x05
#define AX_READ_SPEED_LENGTH        0x04
#define AX_GOAL_SP_LENGTH           0x07
#define AX_ACTION_CHECKSUM			0xFA
#define BROADCAST_ID                0xFE
#define AX_START                    0xFF
#define AX_CCW_AL_L                 0XFF 
#define AX_CCW_AL_H                 0x03
#define BUFFER_SIZE					64
#define TIME_OUT                    10
#define	READ_TIME_OUT 				2
#define TX_DELAY_TIME  				12			// 12  delay is relerative to Baudrate, slow speed more delay is needed
#define TX_BD_DELAY_TIME			500
#define TX_READ_DELAY_TIME  		12			// 12 delay is relerative to Baudrate, slow speed more delay is needed
#define DIRECTION_PIN				1
#define DIRECTION_PORT				D
#include <inttypes.h>


/*
class DynamixelClass {
private:
	
	long 			Time_Counter;
	unsigned char 	Checksum; 	
	unsigned char 	Direction_Pin;
	unsigned char 	Incoming_Byte;               
	unsigned char 	Temperature_Byte;
	unsigned char 	Position_High_Byte;
	unsigned char 	Position_Low_Byte;
	unsigned char 	Load_High_Byte;
	unsigned char 	Load_Low_Byte;
	unsigned char 	Speed_Low_Byte;
	unsigned char 	Speed_High_Byte;
	unsigned int 	Voltage_Byte;

			
	unsigned int Position_Long_Byte;
	unsigned int Load_Long_Byte;
	unsigned int Speed_Long_Byte;
		                                       
	int Error_Byte;   
	int read_error(void);
	
public:
	
	void begin(long);
	void begin(long,unsigned char);
	void end(void);
	
	int reset(unsigned char);
	int ping(unsigned char); 
	int returnDelay(unsigned char,unsigned char);
	
	int setID(unsigned char, unsigned char);
	int setBD(unsigned char, long);
	
	int move(unsigned char, int);
	int moveSpeed(unsigned char, int, int);
	int endlessEnable(unsigned char,bool);
	int turn(unsigned char, bool, int);
	int turnRW(unsigned char, bool, int);
	int moveRW(unsigned char, int);
	int moveSpeedRW(unsigned char, int, int);
	
	int action(unsigned char);
	
	//int readTemperature(unsigned char);
	//int readVoltage(unsigned char);
	//int readPosition(unsigned char);
	//int readLoad(unsigned char);
	//int readSpeed(unsigned char);
	
	//int torqueMax(unsigned char, int);
	//int torqueEnable(unsigned char, bool);
	//int ledState(unsigned char, bool);
	i//nt alarmShutdown(unsigned char,int);
};
*/

long 			Time_Counter;
unsigned char 	Checksum;
unsigned char 	Incoming_Byte;
unsigned char 	Temperature_Byte;
unsigned char 	Position_High_Byte;
unsigned char 	Position_Low_Byte;
unsigned char 	Load_High_Byte;
unsigned char 	Load_Low_Byte;
unsigned char 	Speed_Low_Byte;
unsigned char 	Speed_High_Byte;
unsigned int 	Voltage_Byte;


unsigned int Position_Long_Byte;
unsigned int Load_Long_Byte;
unsigned int Speed_Long_Byte;

int Error_Byte;
int read_error(void);



int read_error(void)
{
/*
int Length_Read;

	Time_Counter = READ_TIME_OUT + millis(); 					// Setup time out error
	
    while(Serial.available() < 5 ) {							// Wait for header data, ID Length and error data from Dynamixel									
			if ( millis() >= Time_Counter) {
				return(-254);									// time out error , exit with fauilt code
			}					
		if( Serial.peek() != 0xFF )	{					
			Serial.read(); 										// Clear Present Byte so next Byte can be read as we are looking for header (start of Frame) data "0xFF"							
		} 

	}		
		Incoming_Byte = Serial.read();
		if (Incoming_Byte == 0xFF & Serial.peek() == 0xFF){		// check that there are 2 "0xFF" header data
			Serial.read(); 										// clear 2nd 0xFF
			Serial.read();                    					// ID sent from Dynamixel
			Length_Read = Serial.read();						// Frame Length
			Serial.read();
			if( Error_Byte != 0 ) {   							// See if error code was sent from Dynamixel	
				return (Error_Byte*(-1));					
				}
				
					Time_Counter = READ_TIME_OUT + millis(); 	// Setup time out error
					while(Serial.available() < Length_Read - 1)	// Wait loop for rest of data from Dynamixel			
					{					
						if ( millis() >= Time_Counter){
						return(-253);							// time out error , exit with fauilt code
						}
					}
									
		}else{
			return(-252);										//2nd Header data not recived, exit with fauilt code
			}
			*/
	return (0x00);											 	// No Ax Response
}


// Public Methods //////////////////////////////////////////////////////////////
/*
void DynamixelClass::begin(long baud)
{	
	Serial.begin(baud);
	
}

void DynamixelClass::begin(long baud, unsigned char D_Pin)
{	
	pinMode(D_Pin,OUTPUT);
	Direction_Pin = D_Pin;
	Serial.begin(baud);
	
}	

void DynamixelClass::end()
{
	Serial.end();
}


*/
int reset(unsigned char ID)
{
	Checksum = ~(ID + AX_RESET_LENGTH + AX_RESET);    // Bitwise not, then "AND" with HEX "FF" so only lower 8 bits are use      
	
	SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);
	uart_print8(AX_START);                     
	uart_print8(AX_START);
	uart_print8(ID);
	uart_print8(AX_RESET_LENGTH);
	uart_print8(AX_RESET);    
	uart_print8(Checksum);
	_delay_ms(TX_DELAY_TIME);
	SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);
    
    return (read_error());  
}


int ping(unsigned char ID)
{
    Checksum = (~(ID + AX_READ_DATA + AX_PING));  
	
	SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);
	uart_print8(AX_START);                     
	uart_print8(AX_START);
	uart_print8(ID);
	uart_print8(AX_READ_DATA);
	uart_print8(AX_PING);    
	uart_print8(Checksum);
	_delay_ms(TX_DELAY_TIME);
	SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);
    
    return (read_error());              
}

int returnDelay(unsigned char ID,unsigned char ReturnDelay)
{
    Checksum = ~(ID + AX_RETURN_LENGTH + AX_WRITE_DATA + AX_RETURN_DELAY_TIME + (ReturnDelay/2)); 
 	
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);      // Set Tx Mode
    uart_print8(AX_START);                 // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
	uart_print8(AX_RETURN_LENGTH);
    uart_print8(AX_WRITE_DATA);
    uart_print8(AX_RETURN_DELAY_TIME);
    uart_print8(ReturnDelay/2);
    uart_print8(Checksum);
    _delay_ms(TX_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);      // Set Rx Mode
    
    return (read_error());                // Return the read error
}

int setID(unsigned char ID, unsigned char New_ID)
{    
    Checksum = ~(ID + AX_ID_LENGTH + AX_WRITE_DATA + AX_ID + New_ID);  
	
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);     // Set Tx Mode
    uart_print8(AX_START);                // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
	uart_print8(AX_ID_LENGTH);
    uart_print8(AX_WRITE_DATA);
    uart_print8(AX_ID);
    uart_print8(New_ID);
    uart_print8(Checksum);
	_delay_ms(TX_DELAY_TIME);
	SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);      // Set Rx Mode
    
    return (read_error());                // Return the read error
}

int setBD(unsigned char ID, long Baud)
{    
	unsigned char Baud_Rate = 2000000/(Baud-1);
//	unsigned char Baud_Rate = (Baud);
    Checksum = ~(ID + AX_BD_LENGTH + AX_WRITE_DATA + AX_BAUD_RATE + Baud_Rate); 
 	
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);      // Set Tx Mode
    uart_print8(AX_START);                 // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
	uart_print8(AX_BD_LENGTH);
    uart_print8(AX_WRITE_DATA);
    uart_print8(AX_BAUD_RATE);
    uart_print8(Baud_Rate);
    uart_print8(Checksum);
    _delay_ms(TX_BD_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);      // Set Rx Mode
    
    return (read_error());                // Return the read error
}

int move(unsigned char ID, int Position)
{
    char Position_H,Position_L;
	Position_L = Position & 0xFF;
    Position_H = (Position >> 8) & 0xFF;           // 16 bits - 2 x 8 bits variables

    
    Checksum = ~(ID + AX_GOAL_LENGTH + AX_WRITE_DATA + AX_GOAL_POSITION_L + Position_L + Position_H);

   	SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);      // Set Tx Mode
    uart_print8(AX_START);                 // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_GOAL_LENGTH);
    uart_print8(AX_WRITE_DATA);
    uart_print8(AX_GOAL_POSITION_L);
    uart_print8(Position_L);
    uart_print8(Position_H);
    uart_print8(Checksum);
	_delay_ms(TX_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);       // Set Rx Mode
	
    return (read_error());                 // Return the read error
}

int moveSpeed(unsigned char ID, int Position, int Speed)
{
	
    char Position_H,Position_L,Speed_H,Speed_L;
	
	Position_L = Position & 0xFF;
    Position_H = Position >> 8;
	Speed_L = Speed & 0xFF;
    Speed_H = Speed >> 8;
    
	//Serial.flush();	
    
   Checksum = ~(ID + AX_GOAL_SP_LENGTH + AX_WRITE_DATA + AX_GOAL_POSITION_L + Position_L + Position_H + Speed_L + Speed_H);

	
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);     // Set Tx Mode
    uart_print8(AX_START);                // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_GOAL_SP_LENGTH);
    uart_print8(AX_WRITE_DATA);
    uart_print8(AX_GOAL_POSITION_L);
    uart_print8(Position_L);
    uart_print8(Position_H);
    uart_print8(Speed_L);
    uart_print8(Speed_H);
    uart_print8(Checksum);
    _delay_ms(TX_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);     // Set Rx Mode
    
    return (read_error());               // Return the read error
}



int turn(unsigned char ID, int SIDE, int Speed)
{	
	
	char Speed_H,Speed_L;
	Speed_H=0;
	Speed_L = Speed & 0xFF;	
		if (SIDE == 0){                          // Move Left                     
			Speed_H = Speed >> 8;
			}
		else if (SIDE == 1){					// Move Right
			Speed_H = (Speed >> 8)+4;	
			}	
			
			Checksum = ~(ID + AX_SPEED_LENGTH + AX_WRITE_DATA + AX_GOAL_SPEED_L + Speed_L + Speed_H);
			
			SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);     // Set Tx Mode
			uart_print8(AX_START);                // Send Instructions over Serial
			uart_print8(AX_START);
			uart_print8(ID);
			uart_print8(AX_SPEED_LENGTH);
			uart_print8(AX_WRITE_DATA);
			uart_print8(AX_GOAL_SPEED_L);
			uart_print8(Speed_L);
			uart_print8(Speed_H);
			uart_print8(Checksum);
			_delay_ms(TX_DELAY_TIME);
			SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);     // Set Rx Mode
			
			return(read_error());               // Return the read error		

}

int turnRW(unsigned char ID, bool SIDE, int Speed)
{	
	char Speed_H,Speed_L;
	Speed_L = Speed & 0xFF; 
		if (SIDE == 0){                          // Move Left
			Speed_H = Speed >> 8;
		}
		else if (SIDE == 1)						// Move Right
		{   
			Speed_H = (Speed >> 8)+4;
		}	
			Checksum = ~(ID + AX_SPEED_LENGTH + AX_REG_WRITE + AX_GOAL_SPEED_L + Speed_L + Speed_H);
			
			SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);     // Set Tx Mode
			uart_print8(AX_START);                // Send Instructions over Serial
			uart_print8(AX_START);
			uart_print8(ID);
			uart_print8(AX_SPEED_LENGTH);
			uart_print8(AX_REG_WRITE);
			uart_print8(AX_GOAL_SPEED_L);
			uart_print8(Speed_L);
			uart_print8(Speed_H);
			uart_print8(Checksum);
			_delay_ms(TX_DELAY_TIME);
			SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);     // Set Rx Mode
			
			return(read_error());               // Return the read error		

}

int endlessEnable(unsigned char ID, bool Status)
{
	if ( Status == 1) {
		char AX_CW_AL_L = 0;
		Checksum = ~(ID + AX_GOAL_LENGTH + AX_WRITE_DATA + AX_CCW_ANGLE_LIMIT_L );
		
		// Changing the CCW Angle Limits for Full Rotation.
		
		SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);     // Set Tx Mode
		uart_print8(AX_START);                // Send Instructions over Serial
		uart_print8(AX_START);
		uart_print8(ID);
		uart_print8(AX_GOAL_LENGTH);
		uart_print8(AX_WRITE_DATA);
		uart_print8(AX_CCW_ANGLE_LIMIT_L );
		uart_print8(AX_CW_AL_L);
		uart_print8(AX_CW_AL_L);
		uart_print8(Checksum);
		_delay_ms(TX_DELAY_TIME);
		SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);     // Set Rx Mode
		return(read_error());
	}
	else
	{
		turn(ID,0,0);
		long CCW_Limit = 1023;
		char CCW_Limit_H,CCW_Limit_L;
		CCW_Limit_L = CCW_Limit & 0xFF;
		CCW_Limit_H = CCW_Limit >> 8;           // 16 bits - 2 x 8 bits variables

		
		Checksum = ~(ID + AX_GOAL_LENGTH + AX_WRITE_DATA + AX_CCW_ANGLE_LIMIT_L +CCW_Limit_L + CCW_Limit_H);

		
		SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);      // Set Tx Mode
		uart_print8(AX_START);                 // Send Instructions over Serial
		uart_print8(AX_START);
		uart_print8(ID);
		uart_print8(AX_GOAL_LENGTH);
		uart_print8(AX_WRITE_DATA);
		uart_print8(AX_CCW_ANGLE_LIMIT_L);
		uart_print8(CCW_Limit_L);
		uart_print8(CCW_Limit_H);
		uart_print8(Checksum);
		_delay_ms(TX_DELAY_TIME);
		SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);       // Set Rx Mode
		
		return (read_error());                 // Return the read error
	}
}
int moveRW(unsigned char ID, int Position)
{

    char Position_H,Position_L;
	Position_L = Position & 0xFF;
    Position_H = Position >> 8;           // 16 bits - 2 x 8 bits variables

    
    Checksum = ~(ID + AX_GOAL_LENGTH + AX_REG_WRITE + AX_GOAL_POSITION_L + Position_L + Position_H);
    
	SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);      // Set Tx Mode
    uart_print8(AX_START);                 // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_GOAL_LENGTH);
    uart_print8(AX_REG_WRITE);
    uart_print8(AX_GOAL_POSITION_L);
    uart_print8(Position_L);
    uart_print8(Position_H);
    uart_print8(Checksum);
	_delay_ms(TX_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);       // Set Rx Mode
	
    return (read_error());                 // Return the read error
}

int moveSpeedRW(unsigned char ID, int Position, int Speed)
{
    char Position_H,Position_L,Speed_H,Speed_L;
	Position_L = Position & 0xFF; 
    Position_H = Position >> 8;  
    Speed_L = Speed & 0xFF;	
    Speed_H = Speed >> 8;
	
    //Serial.flush();
	
    Checksum = ~(ID + AX_GOAL_SP_LENGTH + AX_REG_WRITE + AX_GOAL_POSITION_L + Position_L + Position_H + Speed_L + Speed_H);
	
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);     // Set Tx Mode
    uart_print8(AX_START);                // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_GOAL_SP_LENGTH);
    uart_print8(AX_REG_WRITE);
    uart_print8(AX_GOAL_POSITION_L);
    uart_print8(Position_L);
    uart_print8(Position_H);
    uart_print8(Speed_L);
    uart_print8(Speed_H);
    uart_print8(Checksum);
    _delay_ms(TX_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);     // Set Rx Mode
    
    return (read_error());               // Return the read error
}

int action(unsigned char ID)
{	
	Checksum = ~(ID + AX_ACTION_LENGTH + AX_ACTION);
	
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);     // Set Tx Mode
    uart_print8(AX_START);                // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_ACTION_LENGTH);
    uart_print8(AX_ACTION);
    uart_print8(Checksum);
	_delay_ms(TX_DELAY_TIME);
	SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);     // Set Rx Mode
	
	return (read_error()); 				// Return the read error
}

int torqueMax( unsigned char ID, int Status)
{
    char TorqueMax_L,TorqueMax_H;
	TorqueMax_L = Status & 0xFF;      	
    TorqueMax_H = Status >> 8;    
	
	Checksum = ~(ID + AX_TORQUE_MAX_LENGTH + AX_WRITE_DATA + AX_MAX_TORQUE_L + TorqueMax_L + TorqueMax_H);
	
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);   // Set Tx Mode
    uart_print8(AX_START);              // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_TORQUE_MAX_LENGTH);
    uart_print8(AX_WRITE_DATA);
    uart_print8(AX_MAX_TORQUE_L);
    uart_print8(TorqueMax_L);
    uart_print8(TorqueMax_H);
    uart_print8(Checksum);
    _delay_ms(TX_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);    // Set Rx Mode
    
    return (read_error());              // Return the read error
}

int torqueEnable(unsigned char ID, bool Set)
{
    Checksum = ~(ID + AX_LED_LENGTH + AX_WRITE_DATA + AX_TORQUE_ENABLE + Set);
    
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);   // Set Tx Mode
    uart_print8(AX_START);              // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_LED_LENGTH);
    uart_print8(AX_WRITE_DATA);
    uart_print8(AX_TORQUE_ENABLE);
    uart_print8(Set);
    uart_print8(Checksum);
    _delay_ms(TX_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);    // Set Rx Mode
    
    return (read_error());              // Return the read error
}

int ledState(unsigned char ID, bool Status)
{    
    Checksum = ~(ID + AX_LED_LENGTH + AX_WRITE_DATA + AX_LED + Status);

    
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);   // Set Tx Mode
    uart_print8(AX_START);              // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_LED_LENGTH);
    uart_print8(AX_WRITE_DATA);
    uart_print8(AX_LED);
    uart_print8(Status);
    uart_print8(Checksum);
    _delay_ms(TX_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);    // Set Rx Mode
    
    return (read_error());              // Return the read error
}

void alarmShutdown(unsigned char  ID,int Set)
{
  Checksum = ~(ID + AX_ALARM_LENGTH + AX_WRITE_DATA + AX_ALARM_SHUTDOWN + Set);

    
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);   // Set Tx Mode
    uart_print8(AX_START);              // Send Instructions over Serial
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_ALARM_LENGTH);
    uart_print8(AX_WRITE_DATA);
    uart_print8(AX_ALARM_SHUTDOWN);
    uart_print8(Set);
    uart_print8(Checksum);
    _delay_ms(TX_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);    // Set Rx Mode

}

/*

int DynamixelClass::readTemperature(unsigned char ID)
{	
		int ID_Read;
		int Length_Read;
		int Para1_Read;
		int ChechS_Read;
		
	Checksum = ~(ID + AX_TEM_LENGTH  + AX_READ_DATA + AX_PRESENT_TEMPERATURE + AX_BYTE_READ);
    
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);
	Serial.flush();	
    uart_print8(AX_START);
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_TEM_LENGTH);
    uart_print8(AX_READ_DATA);
    uart_print8(AX_PRESENT_TEMPERATURE);
    uart_print8(AX_BYTE_READ);
    uart_print8(Checksum);	
	_delay_ms(TX_READ_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);     // Set Rx Mode
	
	Temperature_Byte = 0;
	Time_Counter = READ_TIME_OUT + millis(); 					// Setup time out error
	
    while(Serial.available() < 5 ) {							// Wait for header data, ID Length and error data from Dynamixel									
			if ( millis() >= Time_Counter) {
				return(-254);									// time out error , exit with fauilt code
			}					
		if( Serial.peek() != 0xFF )	{					
			Serial.read(); 										// Clear Present Byte so next Byte can be read as we are looking for header (start of Frame) data "0xFF"							
		} 

	}		
	
		Incoming_Byte = Serial.read();
		if (Incoming_Byte == 0xFF & Serial.peek() == 0xFF){		// check that there are 2 "0xFF" header data
			Serial.read(); 										// clear 2nd 0xFF
			ID_Read = Serial.read();                    		// ID sent from Dynamixel
			Length_Read = Serial.read();						// Frame Length
			Error_Byte = Serial.read();
			if( Error_Byte != 0 ) {   		// See if error code was sent from Dynamixel	
				return (Error_Byte*(-1));					
				}
				
					Time_Counter = READ_TIME_OUT + millis(); 	// Setup time out error
					while(Serial.available() < Length_Read - 1)	// Wait loop for rest of data from Dynamixel			
					{					
						if ( millis() >= Time_Counter){
						return(-253);							// time out error , exit with fauilt code
						}
					}
									
		}else{
			return(-252);											//2nd Header data not recived, exit with fauilt code
			}
		
		Para1_Read = Serial.read();							// Voltage Value  
		ChechS_Read = Serial.read();
			if ( ((~(ID_Read + Length_Read + Para1_Read)) & 0xFF) != ChechS_Read & 0xFF){	// Check sum of the recived data
				return(-251);	
			}		
			
			Temperature_Byte = Para1_Read;
	return (Temperature_Byte);               // Returns the read temperature
}

int DynamixelClass::readPosition(unsigned char ID)
{	
		int ID_Read;
		int Length_Read;
		int Para1_Read;
		int Para2_Read;
		int ChechS_Read;
		
	Checksum = ~(ID + AX_POS_LENGTH  + AX_READ_DATA + AX_PRESENT_POSITION_L + AX_PRESENT_POSITION_H);
    
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);
	Serial.flush();	
    uart_print8(AX_START);
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_POS_LENGTH);
    uart_print8(AX_READ_DATA);
    uart_print8(AX_PRESENT_POSITION_L);
    uart_print8(AX_PRESENT_POSITION_H);
    uart_print8(Checksum);	
    _delay_ms(TX_READ_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);     // Set Rx Mode
	
	Position_Long_Byte = 0;
	Time_Counter = READ_TIME_OUT + millis(); 					// Setup time out error
	
    while(Serial.available() < 5 ) {							// Wait for header data, ID Length and error data from Dynamixel									
			if ( millis() >= Time_Counter) {
				return(-254);									// time out error , exit with fauilt code
			}					
		if( Serial.peek() != 0xFF )	{					
			Serial.read(); 										// Clear Present Byte so next Byte can be read as we are looking for header (start of Frame) data "0xFF"							
		} 

	}		
		Incoming_Byte = Serial.read();
		if (Incoming_Byte == 0xFF & Serial.peek() == 0xFF){		// check that there are 2 "0xFF" header data
			Serial.read(); 										// clear 2nd 0xFF
			ID_Read = Serial.read();                    		// ID sent from Dynamixel
			Length_Read = Serial.read();						// Frame Length
			if( (Error_Byte = Serial.read()) != 0 ) {   		// See if error code was sent from Dynamixel	
				return (Error_Byte*(-1));					
				}
				
					Time_Counter = READ_TIME_OUT + millis(); 	// Setup time out error
					while(Serial.available() < Length_Read - 1)	// Wait loop for rest of data from Dynamixel			
					{					
						if ( millis() >= Time_Counter){
						return(-253);							// time out error , exit with fauilt code
						}
					}
									
		}else{
			return(-252);											//2nd Header data not recived, exit with fauilt code
			}
			
	Para1_Read = Serial.read();								// Positon Low data Value  
	Para2_Read = Serial.read();								// Positon High data Value 
	ChechS_Read = Serial.read();							// Check Sum data Value
//			if ( ((~(ID_Read + Length_Read + Para1_Read + Para2_Read )) & 0xFF) != ChechS_Read & 0xFF){	// Check sum of the recived data
//				return(-251);	
//			}	

		
	Position_Long_Byte = Para2_Read; 
	Position_Long_Byte = (Position_Long_Byte << 8) + Para1_Read;
	ChechS_Read = Serial.read();
			
	//		if ( ((~(ID_Read + Length_Read + Para1_Read + Para2_Read )) && 0xFF) != ChechS_Read && 0xFF)
	//		{	// Check sum of the recived data
	//			return(-252);	
	//		}
	
	return (Position_Long_Byte);     // Returns the read position
}

int DynamixelClass::readLoad(unsigned char ID)
{	
		int ID_Read;
		int Length_Read;
		int Para1_Read;
		int Para2_Read;
		int ChechS_Read;
	
    Checksum = ~(ID + AX_LOAD_LENGTH  + AX_READ_DATA + AX_PRESENT_LOAD_L + AX_PRESENT_LOAD_H);
    
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1); 
	Serial.flush();
    uart_print8(AX_START);
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_LOAD_LENGTH);
    uart_print8(AX_READ_DATA);
    uart_print8(AX_PRESENT_LOAD_L);
    uart_print8(AX_PRESENT_LOAD_H);
    uart_print8(Checksum);
    _delay_ms(TX_READ_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);     // Set Rx Mode
	
	Load_Long_Byte = 0;	
	Time_Counter = READ_TIME_OUT + millis(); 					// Setup time out error
	
    while(Serial.available() < 5 ) {							// Wait for header data, ID Length and error data from Dynamixel									
			if ( millis() >= Time_Counter) {
				return(-254);									// time out error , exit with fauilt code
			}					
		if( Serial.peek() != 0xFF )	{					
			Serial.read(); 										// Clear Present Byte so next Byte can be read as we are looking for header (start of Frame) data "0xFF"							
		} 

	}		
		Incoming_Byte = Serial.read();
		if (Incoming_Byte == 0xFF & Serial.peek() == 0xFF){		// check that there are 2 "0xFF" header data
			Serial.read(); 										// clear 2nd 0xFF
			ID_Read = Serial.read();                    		// ID sent from Dynamixel
			Length_Read = Serial.read();						// Frame Length
			if( (Error_Byte = Serial.read()) != 0 ) {   		// See if error code was sent from Dynamixel	
				return (Error_Byte*(-1));					
				}
				
					Time_Counter = READ_TIME_OUT + millis(); 	// Setup time out error
					while(Serial.available() < Length_Read - 1)	// Wait loop for rest of data from Dynamixel			
					{					
						if ( millis() >= Time_Counter){
						return(-253);							// time out error , exit with fauilt code
						}
					}
									
		}else{
			return(-252);											//2nd Header data not recived, exit with fauilt code
			}
			
	Para1_Read = Serial.read();								// Positon Low data Value  
	Para2_Read = Serial.read();								// Positon High data Value 
	ChechS_Read = Serial.read();							// Check Sum data Value
//			if ( ((~(ID_Read + Length_Read + Para1_Read + Para2_Read )) & 0xFF) != ChechS_Read & 0xFF){	// Check sum of the recived data
//				return(-251);	
//			}			
			
			Load_Long_Byte =  Para1_Read ; 			
			Load_Long_Byte = (Load_Long_Byte << 8) + Para2_Read;

	
	return (Load_Long_Byte);     // Returns the read position
}

int DynamixelClass::readSpeed(unsigned char ID)
{	
		int ID_Read;
		int Length_Read;
		int Para1_Read;
		int Para2_Read;
		int ChechS_Read;
	
    Checksum = ~(ID + AX_READ_SPEED_LENGTH  + AX_READ_DATA + AX_PRESENT_SPEED_L + AX_PRESENT_SPEED_H);
    
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1); 
	Serial.flush();
    uart_print8(AX_START);
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_READ_SPEED_LENGTH);
    uart_print8(AX_READ_DATA);
    uart_print8(AX_PRESENT_SPEED_L);
    uart_print8(AX_PRESENT_SPEED_H);
    uart_print8(Checksum);	
    _delay_ms(TX_READ_DELAY_TIME);
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);     // Set Rx Mode
	
	Speed_Long_Byte = 0;
	Time_Counter = READ_TIME_OUT + millis(); 					// Setup time out error
	
    while(Serial.available() < 5 ) {							// Wait for header data, ID Length and error data from Dynamixel									
			if ( millis() >= Time_Counter) {
				return(-254);									// time out error , exit with fauilt code
			}					
		if( Serial.peek() != 0xFF )	{					
			Serial.read(); 										// Clear Present Byte so next Byte can be read as we are looking for header (start of Frame) data "0xFF"							
		} 

	}		
		Incoming_Byte = Serial.read();
		if (Incoming_Byte == 0xFF & Serial.peek() == 0xFF){		// check that there are 2 "0xFF" header data
			Serial.read(); 										// clear 2nd 0xFF
			ID_Read = Serial.read();                    		// ID sent from Dynamixel
			Length_Read = Serial.read();						// Frame Length
			if( (Error_Byte = Serial.read()) != 0 ) {   		// See if error code was sent from Dynamixel	
				return (Error_Byte*(-1));					
				}
				
					Time_Counter = READ_TIME_OUT + millis(); 	// Setup time out error
					while(Serial.available() < Length_Read - 1)	// Wait loop for rest of data from Dynamixel			
					{					
						if ( millis() >= Time_Counter){
						return(-253);							// time out error , exit with fauilt code
						}
					}
									
		}else{
			return(-252);											//2nd Header data not recived, exit with fauilt code
			}
			
	Para1_Read = Serial.read();								// Positon Low data Value  
	Para2_Read = Serial.read();								// Positon High data Value 
	ChechS_Read = Serial.read();							// Check Sum data Value
//			if ( ((~(ID_Read + Length_Read + Para1_Read + Para2_Read )) & 0xFF) != ChechS_Read & 0xFF){	// Check sum of the recived data
//				return(-251);	
//			}			
	
	
			Speed_Long_Byte =  Para1_Read; 			
			Speed_Long_Byte = (Speed_Long_Byte << 8) + Para2_Read;

	return (Speed_Long_Byte);     // Returns the read position
}


int DynamixelClass::readVoltage(unsigned char ID)
{    
		int ID_Read;
		int Length_Read;
		int Para1_Read;
		int ChechS_Read;
		
	Checksum = ~(ID + AX_VOLT_LENGTH  + AX_READ_DATA + AX_PRESENT_VOLTAGE + AX_BYTE_READ);
	    
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,1);
	Serial.flush();	
    uart_print8(AX_START);
    uart_print8(AX_START);
    uart_print8(ID);
    uart_print8(AX_VOLT_LENGTH);
    uart_print8(AX_READ_DATA);
    uart_print8(AX_PRESENT_VOLTAGE);
    uart_print8(AX_BYTE_READ);
    uart_print8(Checksum);							 
	_delay_ms(TX_READ_DELAY_TIME);	
    SET_PIN_VAL(DIRECTION_PORT,DIRECTION_PIN,0);     // Set Rx Mode 
	
	Voltage_Byte = 0;	
	Time_Counter = READ_TIME_OUT + millis(); 					// Setup time out error
	
    while(Serial.available() < 5 ) {							// Wait for header data, ID Length and error data from Dynamixel									
			if ( millis() >= Time_Counter) {
				return(-254);									// time out error , exit with fauilt code
			}					
		if( Serial.peek() != 0xFF )	{					
			Serial.read(); 										// Clear Present Byte so next Byte can be read as we are looking for header (start of Frame) data "0xFF"							
		} 

	}		
		Incoming_Byte = Serial.read();
		if (Incoming_Byte == 0xFF & Serial.peek() == 0xFF){		// check that there are 2 "0xFF" header data
			Serial.read(); 										// clear 2nd 0xFF
			ID_Read = Serial.read();                    		// ID sent from Dynamixel
			Length_Read = Serial.read();						// Frame Length
			Error_Byte = Serial.read();
			if( Error_Byte != 0 ) {   		// See if error code was sent from Dynamixel	
				return (Error_Byte*(-1));					
				}
				
					Time_Counter = READ_TIME_OUT + millis(); 	// Setup time out error
					while(Serial.available() < Length_Read - 1)	// Wait loop for rest of data from Dynamixel			
					{					
						if ( millis() >= Time_Counter){
						return(-253);							// time out error , exit with fauilt code
						}
					}
									
		}else{
			return(-252);											//2nd Header data not recived, exit with fauilt code
			}
		
		Para1_Read = Serial.read();							// Voltage Value  
		ChechS_Read = Serial.read();
			if ( ((~(ID_Read + Length_Read + Para1_Read)) & 0xFF) != ChechS_Read & 0xFF){	// Check sum of the recived data
				return(-251);	
			}				

	Voltage_Byte = Para1_Read / 10;			// Voltage read is 10 times so it needs to be devied
	return (Voltage_Byte);               	// Returns the read Voltage
}
*/

/*
void led_on(){
uart_print8(0xFF);
uart_print8(0xFF);
uart_print8(0x01);
uart_print8(0x04);
uart_print8(0x03);
uart_print8(0x19);
uart_print8(0x01);
uart_print8(0xDD);
};
 */ 
void led_on(){
	uart_print8(0xFF);
	//_delay_ms(100);
	uart_print8(0xFF);
	//_delay_ms(100);
	uart_print8(0x01);//ID
	//_delay_ms(100);
	uart_print8(0x04);//LENGTH
	//_delay_ms(100);
	uart_print8(0x03);//INSTRUCTION
	//_delay_ms(100);
	uart_print8(0x19);//PARAM1
	//_delay_ms(100);
	uart_print8(0x01);//PARAM2
	
	Checksum = ~(0x04+0x03+0x11+0x01+0x01);// + AX_ALARM_LENGTH + AX_WRITE_DATA + AX_ALARM_SHUTDOWN + Set);
	//_delay_ms(100);
	uart_print8(Checksum);
	_delay_ms(1000);
};    
void led_off() {
uart_print8(0xFF);
uart_print8(0xFF);
uart_print8(0x01);
uart_print8(0x04);
uart_print8(0x03);
uart_print8(0x19);
uart_print8(0x00);
uart_print8(0xDE);
};

