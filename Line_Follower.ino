double sensorPin = A0;  //TCRT5000 sensor connected to A0
double sensorPin2 = A1;  //TCRT5000 sensor connected to A0
double sensorPin3 = A2;  //TCRT5000 sensor connected to A0
double sensorState = 0;
double sensorState2 = 0;
double sensorState3 = 0;
double average = 0;
double average2 = 0;
double average3 = 0;

void setup()
{
 pinMode(sensorPin,INPUT); 
  pinMode(sensorPin2,INPUT); 
   pinMode(sensorPin3,INPUT); 
 Serial.begin(9600);
}
void loop()
{
	average = 0;
	average2 = 0;
	average3 = 0;

  for(int i = 0; i < 10; i++)    //Take 10 samples
  { 
   average += analogRead(sensorPin);
 }

  for(int i = 0; i < 10; i++)    //Take 10 samples
  { 
   average2 += analogRead(sensorPin2);
 }

  for(int i = 0; i < 10; i++)    //Take 10 samples
  { 
   average3 += analogRead(sensorPin3);
 }
 
 sensorState = average  / 10;    //Average of samples
  sensorState2 = average2  / 10; 
   sensorState3 = average3  / 10; 
  Serial.print(sensorState);
  Serial.print("\t");
  Serial.print(sensorState2);
  Serial.print("\t");
  Serial.print(sensorState3);
  Serial.print("\t");
  Serial.print("\n");
  delay(250);
}
