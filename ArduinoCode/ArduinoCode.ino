// Sharp IR GP2Y0A21YK Distance Test

#define sensor 0 // Sharp IR GP2Y0A21YK (10-80cm, analog)

//dot position
int read_on = 6;
int read_off = 5;

//minimal distance to flip
int maxdistance = 30;

boolean state = true;

void setup() {
  Serial.begin(9600); // start the serial port
}

void loop() {
  
  // 5v - Read Sensor
  float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 28*pow(volts, -1); // worked out from datasheet graph
  //delay(100); // slow down serial port 
  
 
  
  //flip dot position 1
  if (distance <= maxdistance && distance > 0 && state == true){
    digitalWrite(read_on, LOW);
    digitalWrite(read_off, HIGH);
    Serial.print("flop");
    state = false;  
  }
  
  //flipdot position 2
  if((distance > maxdistance || distance == 0) && state == false){
    digitalWrite(read_on, HIGH);
    digitalWrite(read_off, LOW);
    Serial.print("flip");
    state = true;
}

delay(10);
digitalWrite(read_off, LOW);
digitalWrite(read_off, LOW);
Serial.println(distance);
Serial.print(state);
delay(200);
}

