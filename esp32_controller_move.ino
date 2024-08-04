#include <ps5Controller.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, 16,17);
  ps5.begin("10:18:49:45:44:b2"); //replace with MAC address of your controller
}

void loop() {
  while (ps5.isConnected() == false) { // commented out as ps5 controller seems to connect quicker when microcontroller is doing nothing
    Serial.println("PS5 controller not found");
    delay(300);
  }
  while (ps5.isConnected() == true) {
    Serial2.printf("X%d", (int)((uint8_t)(ps5.LStickX())/25.6));
    Serial2.printf("Y%d", (int)((uint8_t)(ps5.LStickY())/25.6));
    delay(10);
  }
}
