//-----------------------------------------NEC LEDSTRIP CONTROL-------------------------------//
//                                                                                            //
//                                                                                            //
// created on 12-06-2016   uploaded on 12-06-2016                                             //
// created by: Fernand J. J. Hendriks                                                         //
//                                                                                            //
// This software can be used as open software as long as the source, see above, is mentioned  //
//--------------------------------------------------------------------------------------------//

#define keymode 2
#define pin_output 2
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
int mode=-1;
char sb=-1;
char message=' ';
//start message for user

//protocol stuff
boolean dataReceived = false;         // a string to hold incoming data
boolean receiveComplete = false;  // whether the string is complete
boolean gotStart = false;
boolean receivedStart = false;
boolean gotCommand = false;

char command_to_send2[48][16]={
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
  Serial.begin(9600);  
  //BT.begin(baudrate);
  Serial.println( "type #<command>$ for commands use '?' :");
  pinMode(pin_output, OUTPUT);   
  delay(500);
  digitalWrite(pin_output, HIGH);
}

//main 
void loop() {
  while (Serial.available()>0) 
  {
    char sb = Serial.read();
    if (sb =='#' ){
      receivedStart = true;
    }
    if ( receivedStart==true && sb != '$' && sb != '#' )
    {
      message=sb;
      gotCommand=true;
      Serial.print(message);
    }
    if(sb == '$' && receivedStart==true && sb != '#'){
      receivedStart=false;
      if(gotCommand==true){
        commands(message);
        gotCommand=false;
        message=' ';  
      }
    }
    if(receivedStart==true && sb!=message && sb!='$' && message!=' ')
    {
      commands(message);
      receivedStart=false;
      gotCommand=false;
      message=' ';  
    }
    sb=-1;
  }
  
} //end of loop()

void commands(char sb){
//  BT.print(sb);
//  Serial.print(sb);
  if (keymode==1){
    
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
    delayMicroseconds(560);
  }
  return;
}

void high_output(int xtimes)
{
  for (int i =0 ; i<xtimes*2 ; i++){       
    if(on==false) {
      digitalWrite(pin_output, LOW);
      on=true;
      delayMicroseconds(560);
    }else {
      digitalWrite(pin_output, HIGH);
      on=false;
      delayMicroseconds(1680);
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
  delayMicroseconds(560);        
  digitalWrite(pin_output, HIGH); 
  delay(40);        
  digitalWrite(pin_output, LOW); 
  delayMicroseconds(9000);       
  digitalWrite(pin_output, HIGH); 
  delayMicroseconds(2100);       
  digitalWrite(pin_output, LOW);
  delayMicroseconds(560);
  digitalWrite(pin_output, HIGH);
  return;
}

void selection_protocol(String user_input){
Serial.println(user_input);
  if (keymode==1)
  {
    
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
    Serial.println(dataReceived);
    
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
   
  }else{
    for (int i = 0; i < sizeof((int)command_to_send2[modus]) - 1; i++){
      if (command_to_send_property[i]=='H'){
        high_output((int)command_to_send2[modus][i]);
      }else
      {
        low_output((int)command_to_send2[modus][i]);
      }   
    }

  }
  end_protocol();   
}
