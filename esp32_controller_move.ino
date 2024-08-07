#include <ps5Controller.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, 16,17);
  ps5.begin("10:18:49:fc:f0:ee"); //replace with MAC address of your controller
}

void loop() {
  while (ps5.isConnected() == false) { // commented out as ps5 controller seems to connect quicker when microcontroller is doing nothing
    Serial.println("PS5 controller not found");
    delay(300);
  }
  while (ps5.isConnected() == true) {
    uint8_t data[9];
    data[0] = (uint8_t)(ps5.LStickX());//気を付けよう！
    data[1] = (uint8_t)(ps5.LStickY());
    data[2] = (uint8_t)(ps5.RStickX());
    data[3] = (uint8_t)(ps5.RStickY());
    data[4] = (uint8_t)(ps5.R2Value());
    data[5] = (uint8_t)(ps5.L2Value());
    data[6] = 
    (int)(ps5.Right()) << 6|
    (int)(ps5.Left()) << 5|
    (int)(ps5.Up()) << 4|
    (int)(ps5.Down()) << 3|
    (int)(ps5.Circle()) << 2|
    (int)(ps5.Square()) << 1|
    (int)(ps5.Triangle());
    data[7] = 
    (int)(ps5.Cross()) << 6|
    (int)(ps5.UpRight()) << 5|
    (int)(ps5.DownRight()) << 4|
    (int)(ps5.UpLeft()) << 3|
    (int)(ps5.DownLeft()) << 2|
    (int)(ps5.R1()) << 1|
    (int)(ps5.L1());
    data[8] = 
    (int)(ps5.Share()) <<6|
    (int)(ps5.Options()) << 5|
    (int)(ps5.R3()) << 4|
    (int)(ps5.L3()) << 3|
    (int)(ps5.PSButton()) << 2|
    (int)(ps5.Touchpad()) << 1;
    for (int i = 0; i <= 8; i++){
      if (data[i] == 0xff){
        data[i]--;
      }
    }
    Serial2.printf("%c", 0xff);
    for (int i = 0; i <= 8; i++){
      Serial2.printf("%c", data[i]);
    }
    delay(10);
  }
}
