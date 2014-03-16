double sensorPin1 = A0;  //3 TCRT5000 sensors connected to A0-A2
double sensorPin2 = A1;
double sensorPin3 = A2;
int ledPin1 = 3;         //IR diode (TCRT5000) connected to pin 3
int ledPin2 = 5;         //IR diode (TCRT5000) connected to pin 5
int ledPin3 = 6;         //IR diode (TCRT5000) connected to pin 6
double sensorState = 0;
double average = 0;

void setup()
{
 pinMode(sensorPin1,INPUT); 
 pinMode(sensorPin2,INPUT); 
 pinMode(sensorPin3,INPUT); 
 pinMode(ledPin1,OUTPUT);
 pinMode(ledPin2,OUTPUT);
 pinMode(ledPin3,OUTPUT);
 Serial.begin(9600);
}
void loop()
{
  average = 0;

digitalWrite(ledPin1,HIGH);  //Start IR LED
digitalWrite(ledPin2,HIGH);  //Start IR LED
digitalWrite(ledPin3,HIGH);  //Start IR LED
  for(int i = 0; i < 10; i++)    //Take 10 samples
  { 
   average += analogRead(sensorPin1);
  }
 
  sensorState = average / 10;    //Average of samples
  Serial.print(sensorState);
  Serial.print("\n");
  delay(100);

  if(sensorState > 800)  // > 800 = black line
  {

  }
  else					// < 800 = white line
  {

  }


}

