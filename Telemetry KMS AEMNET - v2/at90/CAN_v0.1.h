//TRIMITERE
#define CAN_RESET_CONTROLLER B1(CANGCON,SWRES) //reset CAN Controller (CANGCON=0x01)


void read_can_mobs0() {
	CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
	unsigned char i;
	unsigned char can_byte[8];

	CANPAGE = 0x08;
	i = 0;
	
	for (i=0; i<=7; i++) {
		CANPAGE = ( 0x08 | (i & 0x7) );
		can_byte[i] = CANMSG;
		//CANMSG = 0;
	};
	
	
	
	rpmMSB = can_byte[0];
	rpmLSB = can_byte[1];
	eng_loadMSB=can_byte[2];
	eng_loadLSB=can_byte[3];
	throttle_posMSB=can_byte[4];
	throttle_posLSB=can_byte[5];
	air_temp=can_byte[6];
	engine_temp = can_byte[7];
	
	
	rpm=((rpmMSB<<8)+rpmLSB)*0.390625;
	rpm_KMS=rpm/10;
	rpm_KMSLSB=rpm_KMS & 0xFF;
	rpm_KMSMSB=rpm_KMS >> 8;
	//rpmChar=((rpmMSB<<8)+rpmLSB)/0.390625;
	eng_load=((eng_loadMSB<<8)+eng_loadLSB)*0.00526428247660249;
	throttle_pos=((throttle_posMSB<<8)+throttle_posLSB)*0.00152587890625;
	
	CANSTMOB = 0;
	CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
	CANGIT=CANGIT;


	CANPAGE = 0x18;
	i = 0;
	for (i=0; i<=7; i++) {
		CANPAGE = ( 0x18 | (i & 0x7) );
		can_byte[i] = CANMSG;
	};

	inj_dutyMSB = can_byte[2];
	inj_dutyLSB = can_byte[3];
	map_sensMSB = can_byte[4];
	map_sensLSB = can_byte[5];
	
	inj_duty = ((inj_dutyMSB<<8)+inj_dutyLSB)*0.00381470005959272;
	map_sens = ((map_sensMSB<<8)+map_sensLSB)*0.00526428247660249;

	CANSTMOB = 0;
	CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
	CANGIT=CANGIT;

	CANPAGE = 0x28;
	i = 0;
	for (i=0; i<=7; i++) {
		CANPAGE = ( 0x28 | (i & 0x7) );
		can_byte[i] = CANMSG;
	};
	
	oil_pressMSB = can_byte[2];
	oil_pressLSB = can_byte[3];

	
	oil_press = ((oil_pressMSB<<8)+oil_pressLSB)*0.0000778198227635585;

	CANSTMOB = 0;
	CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
	CANGIT=CANGIT;

	CANPAGE = 0x38;
	i = 0;
	for (i=0; i<=7; i++) {
		CANPAGE = ( 0x38 | (i & 0x7) );
		can_byte[i] = CANMSG;
	};

	lambda1 = (147*((can_byte[0]*0.00390625018553692)+0.5));
	speedMSB = can_byte[2];
	speedLSB = can_byte[3];
	gear = can_byte[4];
	battery_rowMSB = can_byte[6];
	battery_rowLSB = can_byte[7];
	
	vehiclespeed = ((speedMSB<<8)+speedLSB)*0.00390625;
	battery_row = ((battery_rowMSB<<8)+battery_rowLSB)*0.000245500006712973;

	
	CANSTMOB = 0;
	CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
	CANGIT=CANGIT;


};



/*
void read_can_mobs5() {

	unsigned char i;
	unsigned char can_byte1[8];

	CANPAGE = 0x58;
	i = 0;
	
	for (i=0; i<=7; i++) {
		CANPAGE = ( 0x58 | (i & 0x7) );
		can_byte1[i] = CANMSG;
		
		CANMSG = 0;
	};
	
oil_press = can_byte1[5];
	
	//LCDShowInt(oil_press,6,1);
	CANSTMOB = 0;
	CANCDMOB = 0x98;  // Reconfigure mOb as CAN RX mOb
	CANGIT=CANGIT;

};
*/

/*====================================================*/
/* init_rx_can_mobs () */
/*====================================================*/

void init_rx_can_mobs () {
// First RX message from AEMNet

	CANPAGE = 0x08;

	CANIDT1 = 0x0F;
	CANIDT2 = 0x85;
	CANIDT3 = 0x00;
	CANIDT4 = 0x00;
	CANIDM1 = 0xFF;
	CANIDM2 = 0xFF;
	CANIDM3 = 0xFF;
	CANIDM4 = 0xFF;

	CANCDMOB = 0x98;
	
// Second RX message from AEMNet

    CANPAGE = 0x18;
    CANSTMOB = 0;

    CANIDT1 = 0x0F;
    CANIDT2 = 0x85;
    CANIDT3 = 0x00;
    CANIDT4 = 0x08;
    CANIDM1 = 0xFF;
    CANIDM2 = 0xFF;
    CANIDM3 = 0xFF;
    CANIDM4 = 0xFF;

    CANCDMOB = 0x98;

// Third RX message from AEMNet

    CANPAGE = 0x28;
    CANSTMOB = 0;

    CANIDT1 = 0x0F;
    CANIDT2 = 0x85;
    CANIDT3 = 0x00;
    CANIDT4 = 0x10;
    CANIDM1 = 0xFF;
    CANIDM2 = 0xFF;
    CANIDM3 = 0xFF;
    CANIDM4 = 0xFF;

    CANCDMOB = 0x98;

// Fourth RX message from AEMNet


    CANPAGE = 0x38;
    CANSTMOB = 0;

    CANIDT1 = 0x0F;
    CANIDT2 = 0x85;
    CANIDT3 = 0x00;
    CANIDT4 = 0x18;
    CANIDM1 = 0xFF;
    CANIDM2 = 0xFF;
    CANIDM3 = 0xFF;
    CANIDM4 = 0xFF;

    CANCDMOB = 0x98;
	
	//tx message KMS
	
	CANPAGE = 0x48;
	CANSTMOB = 0;

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
		
/*
	// First Can message aaaaa
	CANPAGE = 0x48;
	CANSTMOB = 0;

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

	// Second Can message aaaaa

	CANPAGE = 0x58;
	CANSTMOB = 0;

	CANIDT1 = 0x0A;
	CANIDT2 = 0x5A;
	CANIDT3 = 0x00;
	CANIDT4 = 0x00;
	CANIDM1 = 0xFF;
	CANIDM2 = 0xFF;
	CANIDM3 = 0xFF;
	CANIDM4 = 0xFF;

	CANCDMOB = 0x98;


	// First Can message aaaaa
	CANPAGE = 0x68;
	CANSTMOB = 0;

	CANIDT1 = 0x0A;
	CANIDT2 = 0xFA;
	CANIDT3 = 0x00;
	CANIDT4 = 0x00;
	CANIDM1 = 0xFF;
	CANIDM2 = 0xFF;
	CANIDM3 = 0xFF;
	CANIDM4 = 0xFF;

	CANSTMOB = 0x00;
	CANCDMOB = 0x58;
	CANGIT = CANGIT;

	// Second Can message aaaaa

	CANPAGE = 0x78;
	CANSTMOB = 0;

	CANIDT1 = 0x0A;
	CANIDT2 = 0xFF;
	CANIDT3 = 0x00;
	CANIDT4 = 0x00;
	CANIDM1 = 0xFF;
	CANIDM2 = 0xFF;
	CANIDM3 = 0xFF;
	CANIDM4 = 0xFF;

	CANCDMOB = 0x98;
*/
};

void CAN_Init(){
// Reset all the MObs
for (int ch=0; ch<15; ch++)
{
	CANPAGE=ch<<4;// se muta pe fiecare Message OBject
	CANSTMOB=0;//Status register-
	//ID Tag Registers
	CANIDT1=0;
	CANIDT2=0;
	CANIDT3=0;
	CANIDT4=0;
	//ID Mask registers
	CANIDM1=0;
	CANIDM2=0;
	CANIDM3=0;
	CANIDM4=0;
	for (int data=0; data<8; data++) CANMSG=0;
}
// Enable the CAN controller
CANGCON=0x02;
//enable mob0,mob1
CANEN2=0x03;
// MOb0..7 Interrupts: oFF
CANIE2=0x00;
// MOb8..14 Interrupts: Off
CANIE1=0x00;
// CAN Interrupts:
// Timer Overrun: Off
// General Errors: Off
// Frame Buffer: Off
// MOb Errors: Off
// Transmit: Off
// Receive: On
// Bus Off: Off
// All, except Timer Overrun: On
CANGIE=0x00;
// CAN System Clock: 4000.0 kHz
CANBT1=0x06;
// Propagation Time Segement: 0.750 us
// Re-Sync Jump Width: 0.250 us
CANBT2=0x04;
// Sample Point(s): 1
// Phase Segment 1: 0.500 us
// Phase Segment 2: 0.500 us
CANBT3=0x12;
// CAN Timer Clock Period: 0.500 us
CANTCON=0x00;

init_rx_can_mobs();
}





/*====================================================*/
/* sendToKMS() */
/*====================================================*/

void sendToKMS1()
{
	
	
	unsigned char iKMS=0;
	//unsigned char jKMS=0;
unsigned char uKMS=0;
	
	//while(0==jKMS)
	//{
		CANPAGE = 0x48;
		iKMS = 0;
		for (iKMS=0; iKMS<=7; iKMS++) {
			CANPAGE = ( 0x78 | (iKMS & 0x7) );


			if(0==iKMS)
			{
				CANMSG = rpm_KMSMSB;
			}
			if(1==iKMS)
			{
				CANMSG = rpm_KMSLSB;
			}
			if(2==iKMS)
			{
				CANMSG = engine_temp+20;
			}
			if(3==iKMS)
			{
				CANMSG = air_temp+20;
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

		CANIDT1 = 0x05;//o5 e bun pentru 28
		CANIDT2 = 0x00;
		CANIDT3 = 0x00;
		CANIDT4 = 0x00;
		CANIDM1 = 0xFF;
		CANIDM2 = 0xFF;
		CANIDM3 = 0xFF;
		CANIDM4 = 0xFF;

		CANSTMOB = 0x00;
		CANCDMOB = 0x48;
		CANGIT = CANGIT;


		CANPAGE = 0x48;
		uKMS = 0;
		for (uKMS=0; uKMS<=7; uKMS++) {
			CANPAGE = ( 0x48 | (uKMS & 0x7) );
			can_byte[uKMS] = CANMSG;
	//	};

		CANSTMOB = 0;
		CANCDMOB = 0x88;  // Reconfigure mOb as CAN RX mOb
		CANGIT=CANGIT;

		if( can_byte[7]==0x11)
		{
		//	jKMS=1;
		}
		
		_delay_ms(1);

		CANMSG = 0x00;

	};




}







/*====================================================*/
/* sendToKMS() */
/*====================================================*/

void sendToKMS2()
{
	unsigned char iKMS=0;
	//unsigned char jKMS=0;
	unsigned char uKMS=0;
	//while(0==jKMS)
	//{
	CANPAGE = 0x48;
	iKMS = 0;
	for (iKMS=0; iKMS<=7; iKMS++) {
		CANPAGE = ( 0x78 | (iKMS & 0x7) );


		if(0==iKMS)
		{
			CANMSG = 0x00;
		}
		if(1==iKMS)
		{
			CANMSG = 0x00;
		}
		if(2==iKMS)
		{
			CANMSG = 0x00;
		}
		if(3==iKMS)
		{
			CANMSG = 0x00;
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
			CANMSG = gear+2;
		}
		if(7==iKMS)
		{
			CANMSG = 0x00;
		}
	};

	CANIDT1 = 0x05;//o5 e bun pentru 28
	CANIDT2 = 0x20;
	CANIDT3 = 0x00;
	CANIDT4 = 0x00;
	CANIDM1 = 0xFF;
	CANIDM2 = 0xFF;
	CANIDM3 = 0xFF;
	CANIDM4 = 0xFF;

	CANSTMOB = 0x00;
	CANCDMOB = 0x48;
	CANGIT = CANGIT;


	CANPAGE = 0x48;
	uKMS = 0;
	for (uKMS=0; uKMS<=7; uKMS++) {
		CANPAGE = ( 0x48 | (uKMS & 0x7) );
		can_byte[uKMS] = CANMSG;
		//	};

		CANSTMOB = 0;
		CANCDMOB = 0x88;  // Reconfigure mOb as CAN RX mOb
		CANGIT=CANGIT;

		if( can_byte[7]==0x11)
		{
			//	jKMS=1;
		}
		
		_delay_ms(1);

		CANMSG = 0x00;

	};




}

