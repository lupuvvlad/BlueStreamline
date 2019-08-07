//Last update:2015.06.02;
//Pins to be used in the bit banging
#define I2C_DATA_PORT C
#define I2C_DATA_PIN 4
#define I2C_CLOCK_PORT C
#define I2C_CLOCK_PIN 5
#define I2C_CLK_PERIOD 5//x2[us]
#define I2C_SDA_INPUT INPUT(I2C_DATA_PORT,I2C_DATA_PIN);_delay_us(I2C_CLK_PERIOD)
#define I2C_SDA_HI INPUT(I2C_DATA_PORT,I2C_DATA_PIN)
#define I2C_SDA_LO OUTPUT(I2C_DATA_PORT,I2C_DATA_PIN);_delay_us(I2C_CLK_PERIOD)
#define I2C_SCL_INPUT INPUT(I2C_CLOCK_PORT,I2C_CLOCK_PIN)
#define I2C_SCL_HI INPUT(I2C_CLOCK_PORT,I2C_CLOCK_PIN);_delay_us(I2C_CLK_PERIOD)
#define I2C_SCL_LO OUTPUT(I2C_CLOCK_PORT,I2C_CLOCK_PIN);_delay_us(I2C_CLK_PERIOD)
#define I2C_DELAY_BETWEEN_PACKAGES _delay_us(2*I2C_CLK_PERIOD)

uint8_t I2CReadValue=0;
void I2C_Start(void){//Set both to high at the same time
	I2C_SDA_HI;_delay_us(I2C_CLK_PERIOD);
	I2C_SCL_HI;
	I2C_SDA_LO;_delay_us(I2C_CLK_PERIOD);
	I2C_SCL_LO;
}
void I2C_Stop(void){
	I2C_SCL_HI;
	I2C_SDA_HI;_delay_us(I2C_CLK_PERIOD);
}
void I2C_CLK(void){
	I2C_SCL_HI;
	I2C_SCL_LO;
}

uint8_t I2C_Write(uint8_t valueForWriting){//Return Acknowledge or Not_acknowledge bit;
	uint8_t ack=0;
	for(uint8_t i=0;i<8;i++){
		if(valueForWriting&128){I2C_SDA_HI;}
		else{I2C_SDA_LO;}
		I2C_CLK();
		valueForWriting<<=1;
	}
	I2C_SDA_INPUT;
	I2C_SCL_HI;
	ack=READ_PIN(I2C_DATA_PORT,I2C_DATA_PIN);
	I2C_SCL_LO;
	I2C_DELAY_BETWEEN_PACKAGES;
	return ack;
}
uint8_t I2C_Read(uint8_t ack){//0=Send_ACK_Low; 1=Send_ACK_HI;
	I2C_SDA_INPUT;
	I2CReadValue=0;
	for(uint8_t i=0;i<8;i++){
		I2C_SCL_HI;
		I2CReadValue<<=1;
		I2CReadValue|=(PINX(I2C_DATA_PORT)>>I2C_DATA_PIN)&1;
		I2C_SCL_LO;
	}
	if(ack==0){I2C_SDA_LO;}
	else{I2C_SDA_HI;}
	I2C_SCL_HI;
	if(ack==0){I2C_SDA_HI;}
	I2C_SCL_LO;
	return I2CReadValue;
}
uint8_t I2C_BusReset(){
	uint8_t i=9;//Nine clocks;
	uint8_t i2cBusFree=0;
	I2C_Start();
	while(i--){I2C_CLK();}
	if(READ_PIN(I2C_DATA_PORT,I2C_DATA_PIN)){i2cBusFree=1;}
	else{i2cBusFree=0;}
	return i2cBusFree;
}
void I2C_Init(void){
	I2C_SCL_INPUT;_delay_us(I2C_CLK_PERIOD);
	I2C_SDA_INPUT;_delay_us(I2C_CLK_PERIOD);
	SET_PIN_LO(I2C_DATA_PORT,I2C_DATA_PIN);
	SET_PIN_LO(I2C_CLOCK_PORT,I2C_CLOCK_PIN);
}
