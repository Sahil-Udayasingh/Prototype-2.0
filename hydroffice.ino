// code for hydro-office

void setup() {
  pinMode(A4,INPUT);    // sets A4 pin as input pin
  pinMode(A5,INPUT);    // sets A5 pin as input pin
  pinMode(11,OUTPUT);   // sets 11 pin as output
  Serial.begin(9600);   // Sets the data rate in bits per second (baud) for serial data transmission

}

void loop() {
  
  // initializing variables with analog values sensed by the sensor
  int value1=analogRead(A4);  
  int value2=analogRead(A5);  
  
  Serial.println(value1);     // prints value1 on Serial monitor
  delay(1000);                // creates a delay of 1 second  

  if(value2>1000)           //max value
  digitalWrite(11,HIGH);    // pump connected to relay
  if(value1<800)            //min value
  digitalWrite(11,LOW);     // pump connected to relay
  
  
  
}
