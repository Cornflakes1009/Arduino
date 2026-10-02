const int buttonPin = 2;  // the pin where the button is connected
const int ledPin1 = 9;    // the pin where the first LED is connected
const int ledPin2 = 10;    // the pin where the second LED is connected
const int ledPin3 = 11;   // the pin where the third LED is connected
const int onboardLed = 13; // the onboard LED
 
int buttonState = 0;      // variable for reading the button status
int lastButtonState = 0;  // variable to store the last button state
int mode = 0;             // variable to store the current mode
unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 100;         // interval at which to blink (milliseconds)
 
void setup() {
  pinMode(buttonPin, INPUT);  // initialize the button pin as an input
  pinMode(ledPin1, OUTPUT);   // initialize the first LED pin as an output
  pinMode(ledPin2, OUTPUT);   // initialize the second LED pin as an output
  pinMode(ledPin3, OUTPUT);   // initialize the third LED pin as an output
  pinMode(onboardLed, OUTPUT); // initialize the onboard LED as an output
  Serial.begin(9600);         // begin serial communication for debugging
}
 
void loop() {
  unsigned long currentMillis = millis();
  buttonState = digitalRead(buttonPin);
 
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      mode = (mode + 1) % 3;  // change mode
      digitalWrite(onboardLed, HIGH); // blink onboard LED when button is pressed
      delay(200); // debounce delay
      digitalWrite(onboardLed, LOW);
    }
    delay(50);  // debounce delay
  }
  lastButtonState = buttonState;
 
  switch (mode) {
    case 0:
      fireMode(currentMillis);
      break;
    case 1:
      fairyMode(currentMillis);
      break;
    case 2:
      steadyMode();
      break;
  }
}
 
void fireMode(unsigned long currentMillis) {
  static unsigned long previousMillis = 0;
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    int brightness1 = random(150, 255);
    int brightness2 = random(100, 200);
    int brightness3 = random(50, 150);
    analogWrite(ledPin1, brightness1);
    analogWrite(ledPin2, brightness2);
    analogWrite(ledPin3, brightness3);
  }
}
 
void fairyMode(unsigned long currentMillis) {
  int brightness1 = (sin(currentMillis / 200.0) * 127) + 128;
  int brightness2 = (cos(currentMillis / 200.0) * 127) + 128;
  int brightness3 = (sin((currentMillis + 1000) / 200.0) * 127) + 128;
  analogWrite(ledPin1, brightness1);
  analogWrite(ledPin2, brightness2);
  analogWrite(ledPin3, brightness3);
}
 
void steadyMode() {
  analogWrite(ledPin1, 255);
  analogWrite(ledPin2, 255);
  analogWrite(ledPin3, 255);
}