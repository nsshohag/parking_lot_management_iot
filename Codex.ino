// ---------------------------------------------------------------------------
// Example NewPing library sketch that pings 3 sensors 20 times a second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetoothSerial(7, 6); // define software serial pins

#define SONAR_NUM 1      // Number of sensors.
#define MAX_DISTANCE 1000 // Maximum distance (in cm) to ping.
const int buzzerPin = 9;
NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(2, 3, MAX_DISTANCE) // Each sensor's trigger pin, echo pin, and max distance to ping.
   
 
};

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
   bluetoothSerial.begin(9600); // initialize software serial

  pinMode(buzzerPin, OUTPUT);
}

void loop() {

 
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through each sensor and display results.
    delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    if (bluetoothSerial.available()) { // check if data is available on software serial
    char c = bluetoothSerial.read(); // read the incoming data from Bluetooth module
    Serial.println(c); // print the incoming data to the serial monitor
  }

    Serial.print(i);
    Serial.print("=");
    Serial.print(sonar[i].ping_cm());
    Serial.print("cm ");
    if(sonar[i].ping_cm()<=4){
      digitalWrite(buzzerPin,HIGH);
    }
    else{
      digitalWrite(buzzerPin,LOW);
    }
    bluetoothSerial.println(sonar[i].ping_cm());

  }
  Serial.println();
 
}