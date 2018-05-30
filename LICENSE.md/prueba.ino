
////////////////////////////////////////////////////////////// VARIABLES
int Index;
float inc, pose, anguloTotal;
String b;


////////////////////////////////////////////////////////////// FUNCTIONS

void setup() 
{
  pinMode(11, OUTPUT); //Enable
  pinMode(9, OUTPUT); //Step
  pinMode(10, OUTPUT); //Direction

  digitalWrite(11,LOW);
  Serial.begin(9600);
}


void Derecha(int inc){
   
   inc = abs(inc);
   digitalWrite(10,HIGH);
   for(Index = 0; Index < 55.555556*inc; Index++)
  {
    digitalWrite(9,HIGH);
    delayMicroseconds(450);
    digitalWrite(9,LOW);
    delayMicroseconds(450);
  }
  
}
void Izquierda(int inc){
  inc = abs(inc);
  digitalWrite(10,LOW);
  for(Index = 0; Index < 55.555556*inc; Index++)
  {
    digitalWrite(9,HIGH);
    delayMicroseconds(450);
    digitalWrite(9,LOW);
    delayMicroseconds(450);
    
  }
  
}


//////////////////////////////////////////////////////////////// MAIN
void loop() 
{

   // check for incoming serial data:
  if (Serial.available() > 0) {
    // read incoming serial data:
    inc  =  Serial.parseInt();  // Convert string to int
    // rad value from serial port
    b =  String(inc); 
    pose = pose + inc;
    if(inc>0){
      Izquierda(inc);
    }else{
      Derecha(inc);
    }
    Serial.println(pose);
  }

}

