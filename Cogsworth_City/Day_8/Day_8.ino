const int buttonPin1 = 2;  // the pin where the first button is connected
const int buttonPin2 = 3;  // the pin where the second button is connected
const int ledPin1 = 9;     // the pin where the first LED is connected
const int ledPin2 = 10;    // the pin where the second LED is connected
const int forkPin = 7;     // the pin where the fork is connected
const int photoPin = A0;   // the pin where the photoresistor is connected

int buttonState1 = 0;  // variable for reading the first button status
int buttonState2 = 0;  // variable for reading the second button status
int forkState = 0;     // variable for reading the fork status
int photoValue = 0;    // variable for reading the photoresistor value

void setup() {
  pinMode(buttonPin1, INPUT);  // initialize the first button pin as an input
  pinMode(buttonPin2, INPUT);  // initialize the second button pin as an input
  pinMode(ledPin1, OUTPUT);    // initialize the first LED pin as an output
  pinMode(ledPin2, OUTPUT);    // initialize the second LED pin as an output
  pinMode(forkPin, INPUT);     // initialize the fork pin as an input
  pinMode(photoPin, INPUT);    // initialize the photoresistor pin as an input
  Serial.begin(9600);          // begin serial communication for debugging
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);  // read the state of the first button
  buttonState2 = digitalRead(buttonPin2);  // read the state of the second button
  forkState = digitalRead(forkPin);        // read the state of the fork
  photoValue = analogRead(photoPin);       // read the value from the photoresistor

  if (buttonState1 == HIGH && forkState == HIGH) {
    int brightness = map(photoValue, 400, 600, 0, 255);  // map the photoresistor value to a brightness level
    analogWrite(ledPin1, brightness);                    // adjust first LED brightness based on light level
    Serial.println("First button pressed and fork touched! LED 1 on with brightness adjusted.");
  } else {
    digitalWrite(ledPin1, LOW);  // turn first LED off
  }

  if (buttonState2 == HIGH && forkState == HIGH) {
    int brightness = map(photoValue, 400, 600, 0, 255);  // map the photoresistor value to a brightness level
    analogWrite(ledPin2, brightness);                    // adjust second LED brightness based on light level
    Serial.println("Second button pressed and fork touched! LED 2 on with brightness adjusted.");
  } else {
    digitalWrite(ledPin2, LOW);  // turn second LED off
  }

  delay(100);  // wait for a short period before repeating the loop
}