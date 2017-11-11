
String voice;
int
led1 = 2, //Connect LED 1 To Pin #2
led2 = 3, //Connect LED 2 To Pin #3
led3 = 4, //Connect LED 3 To Pin #4
led4 = 5, //Connect LED 4 To Pin #5
led5 = 6; //Connect LED 5 To Pin #6
//--------------------------Call A Function-------------------------------// 
void allon(){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, HIGH);
}
void alloff(){
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
     digitalWrite(led5, LOW);
}
//-----------------------------------------------------------------------// 
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}
//-----------------------------------------------------------------------// 
void loop() {
  while (Serial.available()){  
  delay(10); 
  char c = Serial.read(); 
  if (c == '#') {break;} 
  voice += c; 
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
  
       if(voice == "*all on") {allon();} 
  else if(voice == "*all of"){alloff();} 
 
  //----------Turn On One-By-One----------//
  else if(voice == "*TV on") {digitalWrite(led1, HIGH);}
  else if(voice == "*fan on") {digitalWrite(led2, HIGH);}
  else if(voice == "*computer on") {digitalWrite(led3, HIGH);}
  else if(voice == "*bedroom lights on") {digitalWrite(led4, HIGH);}
  else if(voice == "*bathroom lights on") {digitalWrite(led5, HIGH);}
  //----------Turn Off One-By-One----------//
  else if(voice == "*TV off") {digitalWrite(led1, LOW);}
  else if(voice == "*fan of") {digitalWrite(led2, LOW);}
  else if(voice == "*computer off") {digitalWrite(led3, LOW);}
  else if(voice == "*bedroom lights off") {digitalWrite(led4, LOW);}
  else if(voice == "*bathroom lights off") {digitalWrite(led5, LOW);}
//-----------------------------------------------------------------------// 
voice="";
}
} 
