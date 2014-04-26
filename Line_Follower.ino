	
    double sensorLeft = A0; //TCRT5000 sensor connected to A0
    double sensorCenter = A1; //TCRT5000 sensor connected to A1
    double sensorRight = A2; //TCRT5000 sensor connected to A2
    double sensorStateLeft = 0;
    double sensorStateCenter = 0;
    double sensorStateRight = 0;

    int motor_left[] = {0, 1};
    int motor_right[] = {2, 3};
    
    void setup()
    {
    pinMode(sensorLeft,INPUT);
    pinMode(sensorCenter,INPUT);
    pinMode(sensorRight,INPUT);

    }
    void loop()
    {	
   sensorStateLeft = analogReadAverage(sensorLeft, 10);
   sensorStateCenter = analogReadAverage(sensorCenter, 10); 
   sensorStateRight = analogReadAverage(sensorRight, 10);
   /*
   * // >800 = Black line
   */
   
   if((sensorStateLeft < 800)&&(sensorStateCenter > 800)&& (sensorStateRight < 800))    // Black line in center              
   {
     drive_forward();
   }
   if((sensorStateLeft > 800)&&(sensorStateCenter < 800)&& (sensorStateRight < 800))   //Easy-medium left turn
   {
     turn_left();
   }
   if((sensorStateLeft < 800)&&(sensorStateCenter < 800)&& (sensorStateRight > 800))    //Easy-medium right turn               
   {
     turn_right();
   }
    }
    double analogReadAverage(double SensorPosition, int samples)
    {
    double value = 0;
    for (int i = 0; i < samples; i++)
    {
    value += analogRead(SensorPosition);
    }
    return value / samples;
    
    }
 /*   
void motor_stop()
{
digitalWrite(motor_left[0], LOW);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], LOW);
digitalWrite(motor_right[1], LOW);
delay(25);
}
*/
/*
void drive_backward()
{
digitalWrite(motor_left[0], LOW);
digitalWrite(motor_left[1], HIGH);

digitalWrite(motor_right[0], LOW);
digitalWrite(motor_right[1], HIGH); 
}
*/

void drive_forward()
{
digitalWrite(motor_left[0], HIGH);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], HIGH);
digitalWrite(motor_right[1], LOW); 
}

void turn_right()
{
digitalWrite(motor_left[0], LOW);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], HIGH);
digitalWrite(motor_right[1], LOW);
}

void turn_left()
{
digitalWrite(motor_left[0], HIGH);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], LOW);
digitalWrite(motor_right[1], LOW);
}


