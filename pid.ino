int lmPin = A0;
unsigned long time;
float temp;
float lasttemp;

void setup() {
  Serial.begin(115200);
  pinMode(lmPin, INPUT);
}
float tempC()
{
 
  float raw = analogRead(lmPin);
  float percent = raw/1023.0;
  float volts = percent*5.0;
  return 100.0*volts;
}


void loop() {
  temp = tempC();
  if(temp != lasttemp){
    time = millis()/1000;
    Serial.print(time);
    Serial.print(" : ");
    Serial.println(temp);
    lasttemp = temp;
  }
  delay(1000);
}

