int blueLEDPin = 9;
int blueLEDPinOnTime = 250;
int blueLEDPinOffTime = 250;
int blueLEDBlinks = 5;
String blueMsg = "Blue LED is Blinking";

int redLEDPin = 10;
int redLEDPinOnTime = 250;
int redLEDPinOffTime = 250;
int redLEDBlinks = 5;
String redMsg = "Red LED is Blinking";

void setup() {
  Serial.begin(115200);
  String hello = "Hello ";
  String world = "World!";
  Serial.println(hello + world);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop() {
  Serial.println(redMsg);
  for (int j = 0; j < blueLEDBlinks; j++) {
    // turn led on, wait, turn led off
    Serial.print("   You are on blink #");
    Serial.println(j); // prints on new line
    digitalWrite(blueLEDPin, HIGH);
    delay(blueLEDPinOnTime);
    digitalWrite(blueLEDPin, LOW);
    delay(blueLEDPinOffTime);
  }

  Serial.println();

  Serial.println(blueMsg);
  for (int i = 0; i < redLEDBlinks; i++) {
    Serial.print("   You are on blink #");
    Serial.println(i);
    digitalWrite(redLEDPin, HIGH);
    delay(redLEDPinOnTime);
    digitalWrite(redLEDPin, LOW);
    delay(redLEDPinOffTime);
  }

  blinkAndHold();
}

void blinkAndHold() {
  digitalWrite(blueLEDPin, HIGH);
  digitalWrite(redLEDPin, HIGH);
  delay(500);
  digitalWrite(blueLEDPin, LOW);
  digitalWrite(redLEDPin, LOW);
  delay(500);
  Serial.println();
}