#define hwserial Serial
#define sensorPin A0

int sensorData;
int debugData1, debugData2, maxValue;

void setup() {
  hwserial.begin(115200);
  delay(100);
  hwserial.println("Boot Complete");
  pinMode(sensorPin, INPUT);
}

void loop() {
  debugSensor();
  delay(100);
}

void readSensor() {
  sensorData = analogRead(sensorPin);
  Serial.print("Sensor Data = ");
  Serial.println(sensorData);
}

void debugSensor(){
  debugData1 = analogRead(sensorPin);
  if (debugData1 > maxValue){
    maxValue = debugData1;
  }
  Serial.print("Wind Speed = ");
  Serial.println(debugData1);
  Serial.print("Max Speed  = ");
  Serial.println(maxValue);
  Serial.println();
}
