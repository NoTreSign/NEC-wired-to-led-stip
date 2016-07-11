//-----------------------------------------NEC LEDSTRIP CONTROL-------------------------------//
//                                                                                            //
//                                                                                            //
// created on 12-06-2016   uploaded on 12-06-2016                                             //
// created by: Fernand J. J. Hendriks                                                         //
//                                                                                            //
// This software can be used as open software as long as the source, see above, is mentioned  //
//--------------------------------------------------------------------------------------------//

#define keymode 1
#define baudrate 9600
#define pin_output 2
#include <time.h>
#include <SoftwareSerial.h>
//SoftwareSerial BT(1, 0); 


//define functions.
void low_output(int );  //creates signal that equals a '0' in NEC protocol.
void high_output(int ); //creates signal that equals a '1' in NEC protocol.
void start_protocol();  //creates signal that initializes the NEC protocol.
void end_protocol();    //creates signal that gives an end signal as refresh signal for the NEC protocol.
void selection_protocol(String); //selects the right method for the required action.
void commands(char);  //sets input serial/bluetooth too commands.
void send_Message(int);



boolean on=false;
int values[24][32]={0};
int count=0;
int  one_output =1680;
int  zero_output= 560;
int mode=-1;
char sb=-1;
char message=' ';
char btb=-1;
char btbmessage= ' ';
//start message for user
/*String output_text[245] = "user_input:: on(1) | off(0) | x1y3(a) |x2y3(s) \n x0y3(p) |x1y2(i) |x2y2(o)  |x0y2(u)  |x1y1(t) |x2y1(y) \n  |x0y1(r) |x1y0(w) |x2y0(e)  |x0y0(q)  |Smooth(A) \n  |Fade(D) |Strobe(S) |Flash(F) |White(W) |Blue(B) |Green(G) |Red(R) |-dim(-) |+dim(+)";
String output_text_A[245] = "user_input:: TOGGLE ON(0)|START/PAUZE(1) \n|BRIGHT(+)|FADE(-)|RED(R) |GREEN(G) \n|BLUE(B)  |WHITE(W) \n|x1y0(q)|x2y0(w)|x3y0(e)|x4y0(r)\nx1y1(X)|x2y1(t)|x3y1(y)|x4y1(u)\n|x1y2(i)|x2y2(o)|x3y2(p)|x4y2(a)\n|x1y3(s)|x2y3(d)|x3y3(f)|x4y3(g)\n|SB1(h)";
String output_text_B[255] =  "|SB2(j) |SB3(k) |SB4(l) \n|SB5(z)\n|SB6(x) |SB7(c) |SB8(v) \n|SB9(b) |SB10(n)|SB11(m)|SB12(M)\n|ab1(Q) |ab2(S) |ab3(A) |ab4(F) \n|ab5(I) |ab6(O) |ab7(J) |ab8(K) ";*/
//protocol stuff
boolean dataReceived = false;         // a string to hold incoming data
boolean receiveComplete = false;  // whether the string is complete
boolean gotStart = false;
boolean receivedStart = false;
boolean receivedStartbtb = false;
boolean gotCommand = false;
boolean gotStartbtb  = false;
boolean gotCommandbtb = false;
int command_to_send[24][14]={
	{8,4,1,5,8,6},
	{8,4,1,3,1,1,6,1,1,6},
	{8,4,1,3,8,8},
	{8,4,1,4,8,7},
	{8,4,1,3,2,1,5,2,1,5},
	{8,4,1,4,1,1,6,1,1,5},
	{8,4,1,3,1,2,5,1,2,5},
	{8,4,1,6,8,5},
	{8,4,1,5,1,1,6,1,1,4},
	{8,4,1,7,8,4},
	{8,4,1,5,2,1,5,2,1,3},
	{8,4,1,6,1,1,6,1,1,3},
	{8,4,1,3,3,1,4,3,1,4},
	{8,4,1,4,2,1,5,2,1,4},
	{8,4,1,3,1,1,1,1,4,1,1,1,1,4},
	{8,4,1,3,2,2,4,2,2,4},
	{8,4,1,4,1,2,5,1,2,4},
	{8,4,1,3,1,3,4,1,3,4},
	{8,4,1,3,4,1,3,4,1,3},
	{8,4,1,4,3,1,4,3,1,3},
	{8,4,1,3,1,1,2,1,3,1,1,2,1,3},
	{8,4,1,3,2,1,1,1,3,2,1,1,1,3},
	{8,4,1,4,1,1,1,1,4,1,1,1,1,3},
	{8,4,1,3,1,2,1,1,3,1,2,1,1,3}
};

int command_to_send2[48][16]={
	{8,8,6,1,1,6,1,1},
	{8,9,5,1,2,5,1,1},
	{8,8,2,3,1,1,1,2,3,1,1,1},
	{8,9,1,3,1,1,2,1,3,1,1,1},
	{8,8,3,2,1,1,1,3,2,1,1,1},
	{8,9,1,1,3,1,2,1,1,3,1,1},
	{8,9,1,1,3,1,2,1,1,3,1,1},
	{8,8,2,1,3,1,1,2,1,3,1,1},
	{8,8,2,1,1,1,1,1,1,2,1,1,1,1,1,1},
	{8,9,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
	{8,9,2,1,2,1,2,2,1,2,1,1},
	{8,8,3,1,2,1,1,3,1,2,1,1},
	{8,8,4,1,1,1,1,4,1,1,1,1},
	{8,9,3,1,1,1,2,3,1,1,1,1},
	{8,9,1,2,2,1,2,1,2,2,1,1},
	{8,8,2,2,2,1,1,2,2,2,1,1},
	{8,8,2,3,3,2,3,3},
	{8,9,1,3,4,1,3,3},
	{8,8,1,4,3,1,4,3},
	{8,13,8,3},
	{8,8,3,2,3,3,2,3},
	{8,9,2,2,4,2,2,3},
	{8,8,1,1,1,2,3,1,1,1,2,3},
	{8,10,1,2,5,1,2,3},
	{8,8,2,1,1,1,3,2,1,1,1,3},
	{8,9,1,1,1,1,4,1,1,1,1,3},
	{8,8,1,2,1,1,3,1,2,1,1,3},
	{8,8,4,1,3,4,1,3},
	{8,9,3,1,4,3,1,3},
	{8,8,1,1,2,1,3,1,1,2,1,3},
	{8,8,2,2,4,2,2,4},
	{8,9,1,2,5,1,2,4},
	{8,8,1,3,4,1,3,4},
	{8,8,3,1,4,3,1,4},
	{8,9,2,1,5,2,1,4},
	{8,8,1,1,1,1,4,1,1,1,1,4},
	{8,11,1,1,6,1,1,3},
	{8,10,2,1,5,2,1,3},
	{8,12,8,4},
	{8,10,1,1,6,1,1,4},
	{8,11,8,5},
	{8,8,1,2,5,1,2,5},
	{8,9,1,1,6,1,1,5},
	{8,8,2,1,5,2,1,5}
};
char command_to_send_property[16]={'H','L','H','L','H','L','H','L','H','L','H','L','H','L','H','L'};



void setup() {
	Serial.begin(baudrate);  
	//BT.begin(baudrate);
        delay(2000);
	Serial.println( "type #<command>$ for commands use '?' :");
	pinMode(pin_output, OUTPUT);   
	Serial.println("configuration:---------------------------");
        //Serial.println("mode is :" + keymode );	
        /*Serial.println((output_text));
        Serial.println(F(output_text_A));
        Serial.println(F(output_text_B));*/
        Serial.println("-----------------------------------------");
	//Serial.println( "***************************************************************************");
        delay(500);
        digitalWrite(pin_output, HIGH);
	delay(4000);
}

//main 
void loop() {
	//declare local variables
	//BT.listen();
	while (Serial.available()>0) 
	{
		char sb = Serial.read();
		if (sb =='#' ){
			count++;
			receivedStart = true;
//			Serial.println("\ngot start \t");
		}
		if ( receivedStart==true && sb != '$' && sb != '#' )
		{
			message=sb;
			gotCommand=true;
//			Serial.print("\ngot message: ");
//			Serial.print(message);
//			Serial.print("\t");
		}
		if(sb == '$' && receivedStart==true && sb != '#'){
//			Serial.print("got end \t");
			receivedStart=false;
			if(gotCommand==true){
				Serial.print("send command \n");
				commands(message);
				gotCommand=false;
				message=' ';  
			}
		}
		if(receivedStart==true && sb!=message && sb!='$' && message!=' ')
		{
			Serial.print("wrong message received \n");
			commands(message);
			receivedStart=false;
			gotCommand=false;
			message=' ';  
		}
		sb=-1;
	}
	/*while( BT.available()>0){
		char btb = BT.read();
		if (btb =='#'){
			count++;
			receivedStartbtb=true;
			Serial.print("\ngot start \t");
		}
		if ( receivedStartbtb==true && btb != '$' && btb != '#' )
		{
			btbmessage=btb;
			gotCommandbtb=true;
			Serial.print("\ngot btmessage: ");
			Serial.print(btbmessage);
			Serial.print("\t");
		}
		if(btb == '$' && receivedStartbtb==true && sb != '#'){
			Serial.print("got end \t");
			receivedStartbtb=false;
			if(gotCommandbtb==true){
				Serial.print("send command \n");
				commands(btbmessage);
				gotCommandbtb=false;
				btbmessage=' ';
			}
		}
		if(gotCommandbtb==true && btb!=btbmessage && btb!='$' && btbmessage!=' ' )
		{
			Serial.print("wrong command \n");
			commands(btbmessage);
			receivedStartbtb=false;
			gotCommandbtb=false;
			btbmessage=' ';
		}
		btb=-1;
	}*/
} //end of loop()

void commands(char sb){
//	BT.print(sb);
//	Serial.print(sb);
	if (keymode==1){
		switch (sb){
		case '0':
			selection_protocol("off");
			break;
		case '1':
			selection_protocol("on");
			break; 
		case 'q':
			selection_protocol("x1y3");
			break;
		case 'w':
			selection_protocol("x2y3");
			break;
		case 'e':
			selection_protocol("x0y3");
			break;
		case 'r':
			selection_protocol("x1y2");
			break;
		case 't':
			selection_protocol("x2y2");
			break;
		case 'y':
			selection_protocol("x0y2");
			break;
		case 'u':
			selection_protocol("x1y1");
			break;
		case 'i':
			selection_protocol("x2y1");
			break;
		case 'o':
			selection_protocol("x0y1");
			break;
		case 'p':
			selection_protocol("x1y0");
			break;
		case 'a':
			selection_protocol("x2y0");
			break;
		case 's':
			selection_protocol("x0y0");
			break;
		case 'A':
			selection_protocol("Smooth");
			break;
		case 'D':
			selection_protocol("Fade");
			break;
		case 'S':
			selection_protocol("Strobe");
			break;
		case 'F':
			selection_protocol("Flash");
			break;
		case 'W':
			selection_protocol("White");
			break;
		case 'B':
			selection_protocol("Blue");
			break;
		case 'G':
			selection_protocol("Green");
			break;
		case 'R':
			selection_protocol("Red");
			break;
		case '-':
			selection_protocol("-dim");
			break;
		case '+':
			selection_protocol("+dim");
			break;
		case '.':
			selection_protocol("status");
		case '?':
		default :
			if (keymode==1){
				//Serial.print(output_text);
///				BT.print(output_text);
			}else{
				//Serial.print(output_text_B);
//				BT.print(output_text_B);
			}
			break;
		}
	}else{
		switch (sb){
		case '0':
			selection_protocol("toggle");
			break;
		case '1':
			selection_protocol("pauze");
			break; 
		case 'q':
			selection_protocol("x1y0");
			break;
		case 'w':
			selection_protocol("x2y0");
			break;
		case 'e':
			selection_protocol("x3y0");
			break;
		case 'r':
			selection_protocol("x4y0");
			break;
		case 'X':
			selection_protocol("x1y1");
			break;
		case 't':
			selection_protocol("x2y1");
			break;
		case 'y':
			selection_protocol("x3y1");
			break;
		case 'u':
			selection_protocol("x4y1");
			break;
		case 'i':
			selection_protocol("x1y2");
			break;
		case 'o':
			selection_protocol("x2y2");
			break;
		case 'p':
			selection_protocol("x3y2");
			break;
		case 'a':
			selection_protocol("x4y2");
			break;
		case 's':
			selection_protocol("x1y3");
			break;
		case 'd':
			selection_protocol("x2y3");
			break;
		case 'f':
			selection_protocol("x3y3");
			break;
		case 'g':
			selection_protocol("x4y3");
			break;
		case 'h':
			selection_protocol("SB1");
			break;
		case 'j':
			selection_protocol("SB2");
			break;
		case 'k':
			selection_protocol("SB3");
			break;
		case 'l':
			selection_protocol("SB4");
			break;
		case 'z':
			selection_protocol("SB5");
			break;
		case 'x':
			selection_protocol("SB6");
			break;
		case 'c':
			selection_protocol("SB7");
			break;
		case 'v':
			selection_protocol("SB8");
			break;
		case 'b':
			selection_protocol("SB9");
			break;
		case 'n':
			selection_protocol("SB10");
			break;
		case 'm':
			selection_protocol("SB11");
			break;
		case 'M':
			selection_protocol("SB12");
			break;
		case 'Q':
			selection_protocol("ab1");
			break;
		case 'S':
			selection_protocol("ab2");
			break;
		case 'A':
			selection_protocol("ab3");
			break;
		case 'F':
			selection_protocol("ab4");
			break;
		case 'I':
			selection_protocol("ab5");
			break;
		case 'O':
			selection_protocol("ab6");
			break;
		case 'J':
			selection_protocol("ab7");
			break;
		case 'K':
			selection_protocol("ab8");
			break;
		case 'W':
			selection_protocol("White");
			break;
		case 'B':
			selection_protocol("Blue");
			break;
		case 'G':
			selection_protocol("Green");
			break;
		case 'R':
			selection_protocol("Red");
			break;
		case '-':
			selection_protocol("FADE");
			break;
		case '+':
			selection_protocol("BRIGHT");
			break;
		case '.':
			selection_protocol("status");
		case '?':
		default :
			if (keymode==1){
				//Serial.println(output_text);
				//BT.println(output_text);
			}else{
				//Serial.println(output_text_B);
				//BT.println(output_text_B);
			}
			break;
		}
	}
}

void low_output(int xtimes){
	for (int i =0 ; i<xtimes*2 ; i++){          
		if(on==false) {
			digitalWrite(pin_output, LOW);
			on=true;
		}else {
			digitalWrite(pin_output, HIGH);
			on=false;
		}
		delayMicroseconds(zero_output);
	}
	return;
}

void high_output(int xtimes)
{
	for (int i =0 ; i<xtimes*2 ; i++){       
		if(on==false) {
			digitalWrite(pin_output, LOW);
			on=true;
			delayMicroseconds(zero_output);
		}else {
			digitalWrite(pin_output, HIGH);
			on=false;
			delayMicroseconds(one_output);
		}
	}
	return;
}

void start_protocol(){
	digitalWrite(pin_output, LOW);    
	delayMicroseconds(9000);
	digitalWrite(pin_output, HIGH);
	delayMicroseconds(4400);
	return;
}

void end_protocol(){

	digitalWrite(pin_output, LOW);
	delayMicroseconds(zero_output);        
	digitalWrite(pin_output, HIGH); 
	delay(40);        
	digitalWrite(pin_output, LOW); 
	delayMicroseconds(9000);       
	digitalWrite(pin_output, HIGH); 
	delayMicroseconds(2100);       
	digitalWrite(pin_output, LOW);
	delayMicroseconds(zero_output);
	digitalWrite(pin_output, HIGH);
	return;
}

void selection_protocol(String user_input){
Serial.println(user_input);
	if (keymode==1)
	{
		if(user_input == "on"){
			Serial.print("on selected");
			mode=0;
		}
		if(user_input == "off"){
			Serial.print("off selected");
			mode=1;
		}
		if(user_input == "+dim"){
			Serial.print("increase brightness");
			mode=2;

		}
		if(user_input == "-dim"){
			Serial.print("dim brightness");
			mode=3;
		}
		if(user_input == "Red"){
			Serial.print("RED selected");
			mode=4;
		}
		if(user_input == "Green"){
			Serial.print("Green selected");
			mode=5;
		}
		if(user_input == "Blue"){
			Serial.print("Blue selected");
			mode=6;
		}
		if(user_input == "White"){
			Serial.print("Green selected");
			mode=7;
		}
		if(user_input == "Flash"){
			Serial.print("Flash selected");
			mode=8;
		}
		if(user_input == "Strobe"){
			Serial.print("Strobe selected");
			mode=9;
		}
		if(user_input == "Fade"){
			Serial.print("Fade selected");
			mode=10;
		}
		if(user_input == "Smooth"){
			Serial.print("Smooth selected");
			mode=11;
		}
		if(user_input == "x0y0"){
			Serial.print("x0y0 selected");
			mode=12;
		}
		if(user_input == "x1y0"){
			Serial.print("x1y0 selected");
			mode=13;
		}
		if(user_input == "x2y0"){
			Serial.print("x2y0 selected");
			mode=14;
		}
		if(user_input == "x0y1"){
			Serial.print("x0y1 selected");
			mode=15;
		}
		if(user_input == "x1y1"){
			Serial.print("x1y1 selected");
			mode=16;
		}
		if(user_input == "x2y1"){
			Serial.print("x2y1 selected");
			mode=17;
		}
		if(user_input == "x0y2"){
			Serial.print("x0y2 selected");
			mode=18;
		}
		if(user_input == "x1y2"){
			Serial.print("x1y2 selected");
			mode=19;
		}
		if(user_input == "x2y2"){
			Serial.print("x2y2 selected");
			mode=20;
		}
		if(user_input == "x0y3"){
			Serial.print("x0y3 selected");
			mode=21;
		}
		if(user_input == "x1y3"){
			Serial.print("x1y3 selected");
			mode=22;
		}
		if(user_input == "x2y3"){
			Serial.print("x2y3 selected");
			mode=23;
		}
	}else{
		if(user_input == "toggle"){
			Serial.print("toggle on/off selected");
			mode=0;
		}
		if(user_input == "pauze"){
			Serial.print("pauze selected");
			mode=1;
		}
		if(user_input == "BRIGHT"){
			Serial.print("increase brightness");
			mode=2;

		}
		if(user_input == "FADE"){
			Serial.print("dim brightness");
			mode=3;
		}
		if(user_input == "Red"){
			Serial.print("RED selected");
			mode=4;
		}
		if(user_input == "Green"){
			Serial.print("Green selected");
			mode=5;
		}
		if(user_input == "Blue"){
			Serial.print("Blue selected");
			mode=6;
		}
		if(user_input == "White"){
			Serial.print("Green selected");
			mode=7;
		}
		if(user_input == "x1y0"){
			Serial.print("x1y0 selected");
			mode=8;
		}
		if(user_input == "x2y0"){
			Serial.print("x2y0 selected");
			mode=9;
		}
		if(user_input == "x3y0"){
			Serial.print("x3y0 selected");
			mode=10;
		}
		if(user_input == "x4y0"){
			Serial.print("x4y0 selected");
			mode=11;
		}
		if(user_input == "x1y1"){
			Serial.print("x1y1 selected");
			mode=12;
		}
		if(user_input == "x2y1"){
			Serial.print("x2y1 selected");
			mode=13;
		}
		if(user_input == "x3y1"){
			Serial.print("x3y1 selected");
			mode=14;
		}
		if(user_input == "x4y1"){
			Serial.print("x4y1 selected");
			mode=15;
		}
		if(user_input == "x1y2"){
			Serial.print("x1y1 selected");
			mode=16;
		}
		if(user_input == "x2y2"){
			Serial.print("x2y1 selected");
			mode=17;
		}
		if(user_input == "x3y2"){
			Serial.print("x3y2 selected");
			mode=18;
		}
		if(user_input == "x4y2"){
			Serial.print("x4y2 selected");
			mode=19;
		}
		if(user_input == "x1y3"){
			Serial.print("x1y3 selected");
			mode=20;
		}
		if(user_input == "x2y3"){
			Serial.print("x2y3 selected");
			mode=21;
		}
		if(user_input == "x3y3"){
			Serial.print("x3y3 selected");
			mode=22;
		}
		if(user_input == "x4y3"){
			Serial.print("x4y3 selected");
			mode=23;
		}

		if(user_input == "SB1"){
			Serial.print("RED UP selected");
			mode=24;
		}
		if(user_input == "SB2"){
			Serial.print("GREEN UP selected");
			mode=25;
		}
		if(user_input == "SB3"){
			Serial.print("BLUE UP selected");
			mode=26;
		}
		if(user_input == "SB4"){
			Serial.print("RED DOWN selected");
			mode=27;
		}
		if(user_input == "SB5"){
			Serial.print("GREEN DOWN selected");
			mode=28;
		}
		if(user_input == "SB6"){
			Serial.print("BLUE DOWN selected");
			mode=29;
		}
		if(user_input == "SB7"){
			Serial.print("DIY1 selected");
			mode=30;
		}
		if(user_input == "SB8"){
			Serial.print("DIY2 selected");
			mode=31;
		}
		if(user_input == "SB9"){
			Serial.print("DIY3 selected");
			mode=32;
		}
		if(user_input == "SB10"){
			Serial.print("DIY4 selected");
			mode=33;
		}
		if(user_input == "SB11"){
			Serial.print("DIY5 selected");
			mode=34;
		}
		if(user_input == "SB12"){
			Serial.print("DIY6 selected");
			mode=35;
		}
		if(user_input == "ab1"){
			Serial.print("quick selected");
			mode=36;
		}
		if(user_input == "ab2"){
			Serial.print("slow selected");
			mode=37;
		}
		if(user_input == "ab3"){
			Serial.print("auto selected");
			mode=38;
		}
		if(user_input == "ab4"){
			Serial.print("flash selected");
			mode=39;
		}
		if(user_input == "ab5"){
			Serial.print("fade7 selected");
			mode=40;
		}
		if(user_input == "ab6"){
			Serial.print("fade 3 selected");
			mode=41;
		}
		if(user_input == "ab7"){
			Serial.print("jump 7 selected");
			mode=42;
		}
		if(user_input == "ab8"){
			Serial.print("jump 3 selected");
			mode=43;
		}








	}
	if(user_input == "status"){

		Serial.println("status ::");
		Serial.println(dataReceived);
		Serial.println(receiveComplete); 
		Serial.println(receivedStart) ;
		Serial.println(gotCommand) ;
		Serial.println(gotStartbtb) ;
		Serial.println(gotCommandbtb) ;
		Serial.println(dataReceived);
		Serial.println(count);
		mode=-1;
	}
	if (mode!=-1)
	{
		send_Message(mode);
		mode!=-1;
	}
	return;
}

void send_Message(int modus){
	start_protocol();
	if (keymode==1)
	{
		for (int i = 0; i < sizeof(command_to_send[modus]) - 1; i++){
			if (command_to_send_property[i]=='H'){
				high_output(command_to_send[modus][i]);
			}else
			{
				low_output(command_to_send[modus][i]);
			}   
		}
	}else{
		for (int i = 0; i < sizeof(command_to_send2[modus]) - 1; i++){
			if (command_to_send_property[i]=='H'){
				high_output(command_to_send2[modus][i]);
			}else
			{
				low_output(command_to_send2[modus][i]);
			}   
		}


	}
	end_protocol();   
}

