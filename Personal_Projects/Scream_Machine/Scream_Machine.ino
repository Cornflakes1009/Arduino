#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial dfPlayerSerial(10, 11);
DFRobotDFPlayerMini dfPlayer;

void setup() {
  Serial.begin(115200);
  dfPlayerSerial.begin(9600);
  delay(1000);

  if (dfPlayer.begin(dfPlayerSerial)) {
    Serial.println("DFPlayer connected");
    dfPlayer.volume(30);
    dfPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  }
}

void loop() {
  int lightLevel = analogRead(A0);
  Serial.println(lightLevel);

  if (lightLevel > 500) { // Find the base light level of your room by checking the Serial Monitor. Set this number a little higher than than the base room light level
    dfPlayer.play(1);
    delay(5000);
  }

  delay(250);
}