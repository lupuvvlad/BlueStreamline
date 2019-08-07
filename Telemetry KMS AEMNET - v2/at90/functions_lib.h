
//#include "BitOperations_V1.5.h"
//#include "SPI_V0.1.h"
#define HEX_DEC_ERROR 42

unsigned char hex_to_dec(unsigned char in)
{
	if(((in >= '0') && (in <= '9'))) return in-'0';
	in |= 0x20;
	if(((in >= 'a') && (in <= 'f'))) return in-'a' + 10;
	return HEX_DEC_ERROR;
}

void store_clock()
{
	SET_PIN_HI(E,5);
	_delay_us(1);

	SET_PIN_LO(E,5);
	_delay_us(1);
}

/*====================================================*/
/* spi_init() */
/*====================================================*/
void test()
{
	SET_PIN_LO(E,2);
	//PORTF=0x00;
	//SPIWriteByte(0xFF); /*this value is used for the the LEDs*/
	//SPIWriteByte(0xC0); /*this value is used for one of the 3x7Segments*/
	//SPIWriteByte(0x81); /*this value is used for the big 7Segment*/
	//SPIWriteByte(0x92); /*this value is used for one of the 3x7Segments*/

	store_clock();
}


/*====================================================*/
/* disp_type_gear_decoder(unsigned char input) */
/*====================================================*/

unsigned char disp_type_gear_decoder(uint16_t input)
{
	switch (input)
	{
		case 0: return DISP_TYPE_GEAR_0;
		break;
		case 1: return DISP_TYPE_GEAR_1;
		break;
		case 2: return DISP_TYPE_GEAR_2;
		break;
		case 3: return DISP_TYPE_GEAR_3;
		break;
		case 4: return DISP_TYPE_GEAR_4;
		break;
		case 5: return DISP_TYPE_GEAR_5;
		break;
		case 6: return DISP_TYPE_GEAR_6;
		break;
		case 7: return DISP_TYPE_GEAR_7;
		break;
		case 8: return DISP_TYPE_GEAR_8;
		break;
		case 9: return DISP_TYPE_GEAR_9;
		break;
		case 10: return DISP_TYPE_GEAR_BAR;
		break;
		default: return 0;
	};


};


void for_segments_decode()
{
	gear_to_display=disp_type_gear_decoder(gear);
	testvar=engine_temp/100;
	testvar2=engine_temp/10;
	if (testvar2>10)
	{
		testvar2=testvar2-10;
	}
	testvar3=engine_temp-((engine_temp/10)*10);

	speed_digit1=vehiclespeed/100;
	speed_digit2=vehiclespeed/10;
	if (speed_digit2>10)
	{
		speed_digit2=speed_digit2-10;
	}
	speed_digit3=vehiclespeed-((vehiclespeed/10)*10);
}
/*functiile pt RPM*/

unsigned char calculate_rpm(uint16_t input)
{
	if (input < 7000) {
		return DISP_TYPE_RPM_LIMIT_LOW;
	}
	else
	if (input < 8000) {
		return DISP_TYPE_RPM_1;
	}
	else
	if (input < 9000) {
		return DISP_TYPE_RPM_2;
	}
	else
	if (input < 10000) {
		return DISP_TYPE_RPM_3;
	}
	else
	if (input < 11000) {
		return DISP_TYPE_RPM_4;
	}
	else
	if (input < 12000) {
		return DISP_TYPE_RPM_5;
	}
	else
	if (input < 13000) {
		return DISP_TYPE_RPM_6;
	}
	else
	if (input < 13000) {
		return DISP_TYPE_RPM_7;
	}
	else
	if (input < 13000) {
		return DISP_TYPE_RPM_8;
	}
	else {
		return DISP_TYPE_RPM_LIMIT;
	};
};




void dammy(unsigned char LEDsVal, unsigned char GearVal)
{
	SET_PIN_LO(E,2);
	
	SPIWriteByte(LEDsVal); /*this value is used for the the LEDs*/
	SPIWriteByte(0xFF); /*this value is used for one of the 3x7Segments*/
	SPIWriteByte(GearVal); /*this value is used for the big 7Segment*/
	SPIWriteByte(0xFF); /*this value is used for one of the 3x7Segments*/

	store_clock();
}
/*===================================================================================================*/

/*pentru a putea folosi aceasta functie trebuie sa iti declari variabile globale pentru fiecare valoare
si ori de cate ori apelezi functia trebuie sa apelezi cu toti parametri*/


void display_value( unsigned char LEDsVal, unsigned char GearVal,
unsigned char seg11, unsigned char seg12, unsigned char seg13,
unsigned char seg21, unsigned char seg22, unsigned char seg23)
{
	SET_PIN_LO(E,2);
	
	//1
	//dammy(LEDsVal,GearVal);
	
	SPIWriteByte(LEDsVal); /*this value is used for the the LEDs*/
	SPIWriteByte(seg21); /*this value is used for the 3x7Segments from the left*/
	SPIWriteByte(GearVal); /*this value is used for the big 7Segment*/
	SPIWriteByte(seg11); /*this value is used for the 3x7Segments from the right*/

	store_clock();
	SET_PIN_HI(A,7);
	_delay_us(400);
	SET_PIN_LO(A,7);
	// _delay_ms(1);
	
	//4
	//dammy(LEDsVal,GearVal);
	
	SPIWriteByte(LEDsVal); /*this value is used for the the LEDs*/
	SPIWriteByte(seg21); /*this value is used for the 3x7Segments from the left*/
	SPIWriteByte(GearVal); /*this value is used for the big 7Segment*/
	SPIWriteByte(seg11); /*this value is used for the 3x7Segments from the right*/
	
	store_clock();
	SET_PIN_HI(G,0);
	_delay_us(400);
	SET_PIN_LO(G,0);
	//_delay_ms(1);

	//2
	//dammy(LEDsVal,GearVal);
	
	//SET_PIN_HI(G,4);
	SPIWriteByte(LEDsVal); /*this value is used for the the LEDs*/
	SPIWriteByte(seg22); /*this value is used for the 3x7Segments from the left*/
	SPIWriteByte(GearVal); /*this value is used for the big 7Segment*/
	SPIWriteByte(seg12); /*this value is used for the 3x7Segments from the right*/

	store_clock();
	SET_PIN_HI(G,2);
	_delay_us(400);
	SET_PIN_LO(G,2);
	//_delay_ms(1);

	//5
	//dammy(LEDsVal,GearVal);
	
	SPIWriteByte(LEDsVal); /*this value is used for the the LEDs*/
	SPIWriteByte(seg22); /*this value is used for the 3x7Segments from the left*/
	SPIWriteByte(GearVal); /*this value is used for the big 7Segment*/
	SPIWriteByte(seg12); /*this value is used for the 3x7Segments from the right*/

	store_clock();
	SET_PIN_HI(G,4);
	_delay_us(400);
	SET_PIN_LO(G,4);
	//_delay_ms(1);
	
	//3
	//dammy(LEDsVal,GearVal);
	

	SPIWriteByte(LEDsVal); /*this value is used for the the LEDs*/
	SPIWriteByte(seg23); /*this value is used for the 3x7Segments from the left*/
	SPIWriteByte(GearVal); /*this value is used for the big 7Segment*/
	SPIWriteByte(seg13); /*this value is used for the 3x7Segments from the right*/
	
	store_clock();
	SET_PIN_HI(G,1);
	_delay_us(400);
	SET_PIN_LO(G,1);
	//_delay_ms(1);
	
	
	//6
	//dammy(LEDsVal,GearVal);
	
	SPIWriteByte(LEDsVal); /*this value is used for the the LEDs*/
	SPIWriteByte(seg23); /*this value is used for the 3x7Segments from the left*/
	SPIWriteByte(GearVal); /*this value is used for the big 7Segment*/
	SPIWriteByte(seg13); /*this value is used for the 3x7Segments from the right*/
	
	store_clock();
	SET_PIN_HI(G,3);
	_delay_us(400);
	SET_PIN_LO(G,3);
	//_delay_us(1);

}


void menu(unsigned char selection)//paginile pentru menu
{
	switch (selection)
	{
		case(1):
		LCDClear();
		LCDShowChar("EngSpeed",0,0);
		LCDShowInt(rpm,10,0);
		LCDShowChar("EngTemp",0,1);
		LCDShowInt(engine_temp,10,1);
		break;

		case (2):
		LCDClear();
		LCDShowChar("EngLoad",0,0);
		LCDShowInt(eng_load,10,0);
		LCDShowChar("AirTemp",0,1);
		LCDShowInt(air_temp,10,1);
		
		break;
		
		case (3):
		LCDClear();
		LCDShowChar("OilPress",0,0);
		LCDShowInt(oil_press,10,0);
		LCDShowChar("Throttle",0,1);
		LCDShowInt(throttle_pos,10,1);
		break;

		case (4):
		LCDClear();
		LCDShowChar("Autoshift",0,0);
		//LCDShowInt(autoshiftState,0,1);
		LCDShowChar("indisponibil",0,1);
		break;

		case (5):
		LCDClear();
		LCDShowChar("Fan Start",0,0);
		//LCDShowInt(fanStartValue,0,1);
		LCDShowChar("indisponibil",0,1);
		

		break;

		case (6):
		LCDClear();
		LCDShowChar("VBatt",0,0);
		LCDShowInt(battery_row,10,0);
		LCDShowChar("InjDuty",0,1);
		LCDShowInt(inj_duty,10,1);

		break;

		case (7):
		LCDClear();
		LCDShowChar("MapSens",0,0);
		LCDShowInt(map_sens,10,0);
		LCDShowChar("Lambda",0,1);
		LCDShowInt(lambda1,10,1);
		break;

		case (8):
		LCDClear();
		LCDShowChar("Speed",0,0);
		LCDShowInt(vehiclespeed,10,0);
		LCDShowChar("gear",0,1);
		LCDShowInt(gear,10,1);
		break;

		case (9):
		LCDClear();
		LCDShowChar("Suna Bety",0,0);
		LCDShowChar("Fugi !!!",0,1);
		break;

		case (10):
		LCDClear();
		LCDShowChar("Urla Barbosu",0,0);
		LCDShowChar("Acum Arde-o!",0,1);
		break;

		default: ;
	}
}

void test_afisaje()// testeaza toate afisajele transmitand diverse valori catre ele la anumite intervale de timp
{
	for (int i=0; i<500; i++)
	{
		display_value(0x00, 0x81, 0x82, 0x92, 0x99, 0xB0, 0xA4, 0xF9);
	}
	
	for (int i=0; i<500; i++)
	{
		display_value(0x01, 0xF3, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90);
	}
	
	for (int i=0; i<500; i++)
	{
		display_value(0x03, 0x49, 0x82, 0x92, 0x99, 0xB0, 0xA4, 0xF9);
	}
	
	for (int i=0; i<500; i++)
	{
		display_value(0x07, 0x61, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90);
	}
	
	for (int i=0; i<500; i++)
	{
		display_value(0x0F, 0x33, 0x82, 0x92, 0x99, 0xB0, 0xA4, 0xF9);
	}
	
	for (int i=0; i<500; i++)
	{
		display_value(0x1F, 0x25, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90);
	}
	
	for (int i=0; i<500; i++)
	{
		display_value(0x3F, 0x05, 0x82, 0x92, 0x99, 0xB0, 0xA4, 0xF9);
	}
	
	for (int i=0; i<500; i++)
	{
		display_value(0x7F, 0xF1, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90);
	}
	for (int i=0; i<500; i++)
	{
		display_value(0xFF, 0x7F, 0x82, 0x92, 0x99, 0xB0, 0xA4, 0xF9);
	}
}

void select_menu()
{
	// ca sa se faca refres  faci la schimbari ale turatiei
	changedbits=PINC<<4;


	//if (changedbits!=portchistory)

	//{
	if(changedbits==0xF0)//0
	{
		menu(1);
	}
	if(changedbits==0xD0)//1
	{
		menu(2);
	}
	if(changedbits==0x70)//2
	{
		menu(3);
	}
	if(changedbits==0x50)//3
	{
		menu(4);
	}
	if(changedbits==0xB0)//4
	{
		menu(5);
	}
	if(changedbits==0x90)//5
	{
		menu(6);
	}
	if(changedbits==0x30)//6
	{
		menu(7);
	}
	if(changedbits==0x10)//7
	{
		menu(8);
	}
	if(changedbits==0xE0)//8
	{
		menu(9);
	}
	if(changedbits==0xC0)//9
	{
		menu(10);
	}
	if(changedbits==0x60)//a
	{
		menu(3);
	}
	if(changedbits==0x40)//b
	{
		menu(4);
	}
	if(changedbits==0xA0)//c
	{
		menu(5);
	}
	if(changedbits==0x80)//d
	{
		menu(6);
	}
	if(changedbits==0x20)//e
	{
		menu(7);
	}
	if(changedbits==0x00)//f
	{
		menu(8);
	}
	//}
	//rpmMenuOld=rpmMenuNew;
	//portchistory=changedbits;

}


void select_menuLeft()
{//_delay_us(1);
	changedBitsLeft=PINC>>4;
	//_delay_us(1);
	if (changedBitsLeft!=portcHistoryLeft)
	{
		
		if ((getRotary(changedBitsLeft))>(getRotary(portcHistoryLeft)))
		{
			if(changedbits==0xB0)
			{
				fanStartValue++;
				menu(5);
			}
			if(changedbits==0x50)
			{
				autoshiftState=1;
				menu(4);
			}

		}
		if ((getRotary(changedBitsLeft))<(getRotary(portcHistoryLeft)))
		{
			if(changedbits==0xB0)
			{
				fanStartValue--;
				menu(5);
			}
			if(changedbits==0x50)
			{
				autoshiftState=0;
				menu(4);
			}
		}
		
		
	}
	
	//LCDShowInt(getRotary(changedBitsLeft),12,1);
	//LCDShowInt(getRotary(portcHistoryLeft),14,1);
	portcHistoryLeft=changedBitsLeft;
}





/*====================================================*/
/* upshift() */
/*====================================================*/
void upshift()
{
	//unsigned char canMobsreceved;
	// char buffer[8];
	unsigned char i;
	//unsigned char j=0;
	shifter_command=0x0F;


	//nr-=1;


	//gear_flag = buffer[nr];

	//while(0==j)
	//{
		CANPAGE = 0x48;
		i = 0;
		for (i=0; i<=7; i++) {
			CANPAGE = ( 0x78 | (i & 0x7) );
			if(0==i)
			{
				CANMSG = shifter_command;
			}
			if(1==i)
			{
				CANMSG = 0x00;
			}
			if(2==i)
			{
				CANMSG = 0x00;
			}
			if(3==i)
			{
				CANMSG = 0x00;
			}
			if(4==i)
			{
				CANMSG = 0x00;
			}
			if(5==i)
			{
				CANMSG = 0x00;
			}
			if(6==i)
			{
				CANMSG = 0x00;
			}
			if(7==i)
			{
				CANMSG = 0x00;
			}
		//};
/*
		CANIDT1 = 0x0A;
		CANIDT2 = 0x55;
		CANIDT3 = 0x00;
		CANIDT4 = 0x00;
		CANIDM1 = 0xFF;
		CANIDM2 = 0xFF;
		CANIDM3 = 0xFF;
		CANIDM4 = 0xFF;

		CANSTMOB = 0x00;
		CANCDMOB = 0x58;
		CANGIT = CANGIT;


		CANPAGE = 0x58;
		i = 0;
		for (i=0; i<=7; i++) {
			CANPAGE = ( 0x58 | (i & 0x7) );
			can_byte[i]=CANMSG;
		};

*/
		CANSTMOB = 0;
		CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
		CANGIT=CANGIT;

		if( can_byte[0]==shifter_command)
		{
			j=1;
		}
		_delay_ms(1);

		CANMSG = 0x00;


	}


}


/*====================================================*/
/* downshift() */
/*====================================================*/

void downshift()
{
	unsigned char i;
	unsigned char j=0;

	shifter_command=0xF0;

	//nr+=1;


	//gear_flag = buffer[nr];


	while(0==j)
	{
		CANPAGE = 0x48;
		i = 0;
		for (i=0; i<=7; i++) {
			CANPAGE = ( 0x78 | (i & 0x7) );


			if(0==i)
			{
				CANMSG = shifter_command;
			}
			if(1==i)
			{
				CANMSG = 0x00;
			}
			if(2==i)
			{
				CANMSG = 0x00;
			}
			if(3==i)
			{
				CANMSG = 0x00;
			}
			if(4==i)
			{
				CANMSG = 0x00;
			}
			if(5==i)
			{
				CANMSG = 0x00;
			}
			if(6==i)
			{
				CANMSG = 0x00;
			}
			if(7==i)
			{
				CANMSG = 0x00;
			}
		};

		CANIDT1 = 0x0A;
		CANIDT2 = 0x55;
		CANIDT3 = 0x00;
		CANIDT4 = 0x00;
		CANIDM1 = 0xFF;
		CANIDM2 = 0xFF;
		CANIDM3 = 0xFF;
		CANIDM4 = 0xFF;

		CANSTMOB = 0x00;
		CANCDMOB = 0x58;
		CANGIT = CANGIT;


		CANPAGE = 0x58;
		i = 0;
		for (i=0; i<=7; i++) {
			CANPAGE = ( 0x58 | (i & 0x7) );
			can_byte[i] = CANMSG;
		};

		CANSTMOB = 0;
		CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
		CANGIT=CANGIT;

		if( can_byte[0]==shifter_command)
		{
			j=1;
		}
		_delay_ms(1);

		CANMSG = 0x00;

	};



}


/*====================================================*/
/* neutral() */
/*====================================================*/

void neutral()
{
	unsigned char i;
	unsigned char j=0;
	shifter_command=0xFF;

	//nr=0;




	//gear_flag = buffer[nr];

	while(0==j)
	{
		CANPAGE = 0x48;
		i = 0;
		for (i=0; i<=7; i++) {
			CANPAGE = ( 0x78 | (i & 0x7) );
			// CANMSG =shifter_command ;

			if(0==i)
			{
				CANMSG = shifter_command;
			}
			if(1==i)
			{
				CANMSG = 0x00;
			}
			if(2==i)
			{
				CANMSG = 0x00;
			}
			if(3==i)
			{
				CANMSG = 0x00;
			}
			if(4==i)
			{
				CANMSG = 0x00;
			}
			if(5==i)
			{
				CANMSG = 0x00;
			}
			if(6==i)
			{
				CANMSG = 0x00;
			}
			if(7==i)
			{
				CANMSG = 0x00;
			}
		};

		CANIDT1 = 0x0A;
		CANIDT2 = 0x55;
		CANIDT3 = 0x00;
		CANIDT4 = 0x00;
		CANIDM1 = 0;
		CANIDM2 = 0;
		CANIDM3 = 0;
		CANIDM4 = 0;

		CANSTMOB = 0x00;
		CANCDMOB = 0x58;
		CANGIT = CANGIT;


		CANPAGE = 0x58;
		i = 0;
		for (i=0; i<=7; i++) {
			CANPAGE = ( 0x58 | (i & 0x7) );
			can_byte[i] = CANMSG;
		};

		CANSTMOB = 0;
		CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
		CANGIT=CANGIT;

		if( can_byte[0]==shifter_command)
		{
			j=1;
		}
		_delay_ms(1);

		CANMSG = 0x00;


	};

	//send_can_mobs2();

}


/*====================================================*/
/* radioOn() */
/*====================================================*/
void radioOn()
{
	unsigned char i;
	unsigned char j=0;
	shifter_command=0xAF;

	//nr=0;




	//gear_flag = buffer[nr];

	while(0==j)
	{
		CANPAGE = 0x48;
		i = 0;
		for (i=0; i<=7; i++) {
			CANPAGE = ( 0x78 | (i & 0x7) );
			// CANMSG =shifter_command ;

			if(0==i)
			{
				CANMSG = 0xAF;
			}
			if(1==i)
			{
				CANMSG = 0x00;
			}
			if(2==i)
			{
				CANMSG = 0x00;
			}
			if(3==i)
			{
				CANMSG = 0x00;
			}
			if(4==i)
			{
				CANMSG = 0x00;
			}
			if(5==i)
			{
				CANMSG = 0x00;
			}
			if(6==i)
			{
				CANMSG = 0x00;
			}
			if(7==i)
			{
				CANMSG = 0x00;
			}
		};

		CANIDT1 = 0x0A;
		CANIDT2 = 0x55;
		CANIDT3 = 0x00;
		CANIDT4 = 0x00;
		CANIDM1 = 0;
		CANIDM2 = 0;
		CANIDM3 = 0;
		CANIDM4 = 0;

		CANSTMOB = 0x00;
		CANCDMOB = 0x58;
		CANGIT = CANGIT;


		CANPAGE = 0x58;
		i = 0;
		for (i=0; i<=7; i++) {
			CANPAGE = ( 0x58 | (i & 0x7) );
			can_byte[i] = CANMSG;
		};

		CANSTMOB = 0;
		CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
		CANGIT=CANGIT;

		if( can_byte[0]==0xAF)
		{
			j=1;
		}
		_delay_ms(1);

		CANMSG = 0x00;


	};



}



/*====================================================*/
/* radioOff() */
/*====================================================*/

void radioOff()
{
	unsigned char i;
	unsigned char j=0;

	shifter_command=0x55;

	//nr+=1;


	//gear_flag = buffer[nr];


	while(0==j)
	{
		CANPAGE = 0x48;
		i = 0;
		for (i=0; i<=7; i++) {
			CANPAGE = ( 0x78 | (i & 0x7) );


			if(0==i)
			{
				CANMSG = shifter_command;
			}
			if(1==i)
			{
				CANMSG = 0x00;
			}
			if(2==i)
			{
				CANMSG = 0x00;
			}
			if(3==i)
			{
				CANMSG = 0x00;
			}
			if(4==i)
			{
				CANMSG = 0x00;
			}
			if(5==i)
			{
				CANMSG = 0x00;
			}
			if(6==i)
			{
				CANMSG = 0x00;
			}
			if(7==i)
			{
				CANMSG = 0x00;
			}
		};

		CANIDT1 = 0x0A;
		CANIDT2 = 0x55;
		CANIDT3 = 0x00;
		CANIDT4 = 0x00;
		CANIDM1 = 0xFF;
		CANIDM2 = 0xFF;
		CANIDM3 = 0xFF;
		CANIDM4 = 0xFF;

		CANSTMOB = 0x00;
		CANCDMOB = 0x58;
		CANGIT = CANGIT;


		CANPAGE = 0x58;
		i = 0;
		for (i=0; i<=7; i++) {
			CANPAGE = ( 0x58 | (i & 0x7) );
			can_byte[i] = CANMSG;
		};

		CANSTMOB = 0;
		CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
		CANGIT=CANGIT;

		if( can_byte[0]==shifter_command)
		{
			j=1;
		}
		_delay_ms(1);

		CANMSG = 0x00;

	};



}


/*====================================================*/
/* sendToKMS() */
/*====================================================*/
/*
void sendToKMS()
{
	unsigned char iKMS=0;
	unsigned char jKMS=0;

	while(0==jKMS)
	{
		CANPAGE = 0x48;
		iKMS = 0;
		for (iKMS=0; iKMS<=7; iKMS++) {
			CANPAGE = ( 0x78 | (iKMS & 0x7) );


			if(0==iKMS)
			{
				CANMSG = rpmMSB;
			}
			if(1==iKMS)
			{
				CANMSG = rpmLSB;
			}
			if(2==iKMS)
			{
				CANMSG = engine_temp;
			}
			if(3==iKMS)
			{
				CANMSG = air_temp;
			}
			if(4==iKMS)
			{
				CANMSG = 0x00;
			}
			if(5==iKMS)
			{
				CANMSG = 0x00;
			}
			if(6==iKMS)
			{
				CANMSG = 0x00;
			}
			if(7==iKMS)
			{
				CANMSG = 0x00;
			}
		};

		CANIDT1 = 0x14;
		CANIDT2 = 0x00;
		CANIDT3 = 0x00;
		CANIDT4 = 0x00;
		CANIDM1 = 0xFF;
		CANIDM2 = 0xFF;
		CANIDM3 = 0xFF;
		CANIDM4 = 0xFF;

		CANSTMOB = 0x00;
		CANCDMOB = 0x58;
		CANGIT = CANGIT;


		CANPAGE = 0x48;
		iKMS = 0;
		for (iKMS=0; iKMS<=7; iKMS++) {
			CANPAGE = ( 0x48 | (iKMS & 0x7) );
			can_byte[iKMS] = CANMSG;
		};

		CANSTMOB = 0;
		CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
		CANGIT=CANGIT;

		if( can_byte[0]==shifter_command)
		{
			jKMS=1;
		}
		_delay_ms(1);

		CANMSG = 0x00;

	};



}

*/

void button_inputs() {

	/*partea este pentru radio*/
	if(READ_PIN(D,2) == 0) {
		if (button4 < 20) {
			button4 ++;
		};
	}
	else {
		if(button4 > 0)  {
			button4 --;
		};
	};
	if (button4_activated == 0) {
		if (button4 > 10) {
			button4_activated = 1;
			radioOn();
			LCDShowChar("RA",14,1);
			/*------*/
			//button3 = 0;
		};
	};
	if (button4 == 0) {
		button4_activated = 0;
		shifter_command = 0x00;
	};


}

// void auto_shift_operation() {
//         if((rpm > 12000) && (vehiclespeed > 5) && (gear_to_displayint > 0) && (gear_to_displayint < 6)) {
//             upshift();
//         };
//         if((rpm < 6000) && (vehiclespeed > 5) && (gear_to_displayint > 1) && (gear_to_displayint < 7)) {
//             downshift();
//         };
// };


