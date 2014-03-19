	double sensorLeft = A0; //TCRT5000 sensor connected to A0
    double sensorCenter = A1; //TCRT5000 sensor connected to A1
    double sensorRight = A2; //TCRT5000 sensor connected to A2
    double sensorStateLeft = 0;
    double sensorStateCenter = 0;
    double sensorStateRight = 0;
    double average = 0;
    String Tab = "\t";
    String NewLine = "\n";
    void setup()
    {
    pinMode(sensorLeft,INPUT);
    pinMode(sensorCenter,INPUT);
    pinMode(sensorRight,INPUT);
    Serial.begin(9600);
    }
    void loop()
    {
    sensorStateLeft = analogReadAverage(sensorLeft, 10);
    sensorStateCenter = analogReadAverage(sensorCenter, 10);
    sensorStateRight = analogReadAverage(sensorRight, 10);
    Serial.print(sensorStateLeft + Tab );
    Serial.print(sensorStateCenter + Tab );
    Serial.print(sensorStateRight + Tab + NewLine);
    delay(250);
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

