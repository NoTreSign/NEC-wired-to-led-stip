//-----------------------------------------NEC LEDSTRIP CONTROL-------------------------------//
//                                                                                            //
//                                                                                            //
// created on 12-06-2016   uploaded on 12-06-2016                                             //
// created by: Fernand J. J. Hendriks                                                         //
//                                                                                            //
// This software can be used as open software as long as the source, see above, is mentioned  //
//--------------------------------------------------------------------------------------------//


#define pin_output 2
#include <time.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(1, 0); 

boolean on=false;
int values[24][32]={0};
int count=0;
int  one_output =1680;
int  zero_output= 560;
char sb=-1;
char message=' ';
char btb=-1;
char btbmessage= ' ';
//start message for user
String output_text = "user_input:: on(1) | off(0) | x1y3(a) |x2y3(s) \n x0y3(p) |x1y2(i) |x2y2(o)  |x0y2(u)  |x1y1(t) |x2y1(y) \n  |x0y1(r) |x1y0(w) |x2y0(e)  |x0y0(q)  |Smooth(A) \n  |Fade(D) |Strobe(S) |Flash(F) |White(W) |Blue(B) |Green(G) |Red(R) |-dim(-) |+dim(+)";
//protocol stuff
boolean dataReceived = false;         // a string to hold incoming data
boolean receiveComplete = false;  // whether the string is complete
boolean gotStart = false;
boolean receivedStart = false;
boolean receivedStartbtb = false;
boolean gotCommand = false;
boolean gotStartbtb  = false;
boolean gotCommandbtb = false;


//define functions.
void low_output(int );  //creates signal that equals a '0' in NEC protocol.
void high_output(int ); //creates signal that equals a '1' in NEC protocol.
void start_protocol();  //creates signal that initializes the NEC protocol.
void end_protocol();    //creates signal that gives an end signal as refresh signal for the NEC protocol.
void selection_protocol(String); //selects the right method for the required action.
void commands(char);  //sets input serial/bluetooth too commands.

void setup() {

	Serial.begin(9600);  
	BT.begin(9600);
	BT.write( "Serial BT to ledstrip opperational :");
	pinMode(pin_output, OUTPUT);   
	digitalWrite(pin_output, HIGH);
	Serial.print(output_text);
	delayMicroseconds(400);
}

//main 
void loop() {
	//declare local variables
	BT.listen();
	while (Serial.available()>0) 
	{
		char sb = Serial.read();
		if (sb =='#' ){
			count++;
			//gotStart=true;
			receivedStart = true;
			Serial.print("\ngot start \t");
		}
		if ( receivedStart==true && sb != '$' && sb != '#' )
		{
			message=sb;
			gotCommand=true;
			Serial.print("\ngot message: ");
			Serial.print(message);
			Serial.print("\t");
		}
		if(sb == '$' && receivedStart==true && sb != '#'){
			Serial.print("got end \t");
			receivedStart=false;
			// Serial.println(gotStart) ;
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
	while( BT.available()>0){
		char btb = BT.read();
		if (btb =='#'){
			count++;
			//gotStartbtb=true;
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
	}
} //end of loop()

void commands(char sb){
	BT.print(sb);
	Serial.print(sb);
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
		Serial.print(output_text);
		BT.print(output_text);
		break;
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
       /* //can be redisgned, this is a ugly way of programming but it works
        // string command_to_send[mode][commands][L/H];
        // if(user_input == "on"){
       //       mode=1;
       // }...other cases
       //i can be max 
         start_protocol();
       //for (i = 0; i < sizeof(command_to_send[mode x][][0]) - 1; i++){
          if (command_to_send[mode x][i]==H){
            high_output(command_to_send[mode x][i])
          }else
          {
            low_output(command_to_send[mode x][i])
          }
          
        }
        end_protocol();
        //done transmitting
        */
        
        
        
	if(user_input == "on"){
		Serial.print("on selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(5);
		low_output(8);
		high_output(6);
		end_protocol();
	}
	if(user_input == "off"){
		Serial.print("off selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(1);
		high_output(1);
		low_output(6);
		high_output(1);
		low_output(1);
		high_output(6);
		end_protocol();
	}
	if(user_input == "+dim"){
		Serial.print("increase brightness");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(8);
		high_output(8);
		end_protocol();

	}
	if(user_input == "-dim"){
		Serial.print("dim brightness");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(4);
		low_output(8);
		high_output(7);
		end_protocol();
	}
	if(user_input == "Red"){
		Serial.print("RED selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(2);
		high_output(1);
		low_output(5);
		high_output(2);
		low_output(1);
		high_output(5);
		end_protocol();
	}
	if(user_input == "Green"){
		Serial.print("Green selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(4);
		low_output(1);
		high_output(1);
		low_output(6);
		high_output(1);
		low_output(1);
		high_output(5);
		end_protocol();
	}
	if(user_input == "Blue"){
		Serial.print("Blue selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(1);
		high_output(2);
		low_output(5);
		high_output(1);
		low_output(2);
		high_output(5);
		end_protocol();
	}
	if(user_input == "White"){
		Serial.print("Green selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(6);
		low_output(8);
		high_output(5);
		end_protocol();
	}
	if(user_input == "Flash"){
		Serial.print("Flash selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(5);
		low_output(1);
		high_output(1);
		low_output(6);
		high_output(1);
		low_output(1);
		high_output(4);
		end_protocol();
	}
	if(user_input == "Strobe"){
		Serial.print("Strobe selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(7);
		low_output(8);
		high_output(4);
		end_protocol();
	}
	if(user_input == "Fade"){
		Serial.print("Fade selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(5);
		low_output(2);
		high_output(1);
		low_output(5);
		high_output(2);
		low_output(1);
		high_output(3);
		end_protocol();
	}
	if(user_input == "Smooth"){
		Serial.print("Smooth selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(6);
		low_output(1);
		high_output(1);
		low_output(6);
		high_output(1);
		low_output(1);
		high_output(3);
		end_protocol();
	}
	if(user_input == "x0y0"){
		Serial.print("x0y0 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(3);
		high_output(1);
		low_output(4);
		high_output(3);
		low_output(1);
		high_output(4);
		end_protocol();
	}
	if(user_input == "x1y0"){
		Serial.print("x1y0 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(4);
		low_output(2);
		high_output(1);
		low_output(5);
		high_output(2);
		low_output(1);
		high_output(4);
		end_protocol();
	}
	if(user_input == "x2y0"){
		Serial.print("x2y0 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(1);
		high_output(1);
		low_output(1);
		high_output(1);
		low_output(4);
		high_output(1);
		low_output(1);
		high_output(1);
		low_output(1);
		high_output(4);
		end_protocol();
	}
	if(user_input == "x0y1"){
		Serial.print("x0y1 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(2);
		high_output(2);
		low_output(4);
		high_output(2);
		low_output(2);
		high_output(4);
		end_protocol();
	}
	if(user_input == "x1y1"){
		Serial.print("x1y1 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(4);
		low_output(1);
		high_output(2);
		low_output(5);
		high_output(1);
		low_output(2);
		high_output(4);
		end_protocol();
	}
	if(user_input == "x2y1"){
		Serial.print("x2y1 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(1);
		high_output(3);
		low_output(4);
		high_output(1);
		low_output(3);
		high_output(4);
		end_protocol();
	}
	if(user_input == "x0y2"){
		Serial.print("x0y2 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(4);
		high_output(1);
		low_output(3);
		high_output(4);
		low_output(1);
		high_output(3);
		end_protocol();
	}
	if(user_input == "x1y2"){
		Serial.print("x1y2 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(4);
		low_output(3);
		high_output(1);
		low_output(4);
		high_output(3);
		low_output(1);
		high_output(3);
		end_protocol();
	}
	if(user_input == "x2y2"){
		Serial.print("x2y2 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(1);
		high_output(1);
		low_output(2);
		high_output(1);
		low_output(3);
		high_output(1);
		low_output(1);
		high_output(2);
		low_output(1);
		high_output(3);
		end_protocol();
	}
	if(user_input == "x0y3"){
		Serial.print("x0y3 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(2);
		high_output(1);
		low_output(1);
		high_output(1);
		low_output(3);
		high_output(2);
		low_output(1);
		high_output(1);
		low_output(1);
		high_output(3);
		end_protocol();
	}
	if(user_input == "x1y3"){
		Serial.print("x1y3 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(4);
		low_output(1);
		high_output(1);
		low_output(1);
		high_output(1);
		low_output(4);
		high_output(1);
		low_output(1);
		high_output(1);
		low_output(1);
		high_output(3);
		end_protocol();
	}
	if(user_input == "x2y3"){
		Serial.print("x2y3 selected");
		start_protocol();
		low_output(8);
		high_output(4);
		low_output(1);
		high_output(3);
		low_output(1);
		high_output(2);
		low_output(1);
		high_output(1);
		low_output(3);
		high_output(1);
		low_output(2);
		high_output(1);
		low_output(1);
		high_output(3);
		end_protocol();
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
	}
	return;
}



