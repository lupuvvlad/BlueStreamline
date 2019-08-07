//ATMEGA48_88_168
#define ENABLE_TWI B1(TWCR,TWEN)
#define TWI_INTERRUPT_ENABLE B1(TWCR,TWIE)
#define TWI_CLEAR_WRITE_COLLISION_FLAG B1(TWCR,TWINT);TWDR=0b11111111
#define TWI_CLEAR_INTERRUPT_FLAG B1(TWCR,TWINT)//This flag is not cleared by the HW;
#define TWI_SEND_ACK_BIT B1(TWCR,TWEA)
#define TWI_SEND_START_BIT B1(TWCR,TWSTA)
#define TWI_CLEAR_START_BIT B1(TWCR,TWSTA)
#define TWI_SEND_STOP_BIT B1(TWCR,TWSTO)

#define TWI_S_RELEASE_BUS B1(TWCR,TWSTO)//In case of error Slave has to be placed in this condition;

#define TWI_READ_STATUS BITS_GET(TWSR,0b11111000)

#define TWI_READ_DATA TWDR
#define TWI_PLACE_DATA_IN_REG(data) TWDR=data

#define TWI_SET_DEVICE_ADDRESS(addr) (TWAR|=addr<<1)//OK;

#define SET_M_TWI_CLK_400K TWBR=17;//[TWBR=17(FCPU=20MHz)];TWBR shoul be minimum 10 in master mode;
#define SET_M_TWI_CLK_200K TWBR=12;//[TWBR=12(FCPU=8MHz)];TWBR shoul be minimum 10 in master mode;
