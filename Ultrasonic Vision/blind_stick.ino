const int trigPin = 9;
const int echoPin = 10;
int buzzer = 11;
// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance <= 100){
  tone(buzzer , 2000 , 500);
}
else if(distance <= 200){
  tone(buzzer , 2000 , 500);
  delay(500);
}
else if(distance <= 300){
  tone(buzzer , 2000 , 500);
  delay(1000);
}
else if(distance <= 400){
  tone(buzzer , 2000 , 500);
  delay(1500);
}
//else{
//  digitalWrite(buzzer, LOW);
//  delay(100);
//}
  
}
