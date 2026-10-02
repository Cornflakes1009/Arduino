// *** the course originally tells you to plug ledPin1 into pin 8, but pin 8 isn't a PWM (pulse-width modulation) pin. PWM pins are marked with a ~ on the board.***

const int buttonPin1 = 2;   // the number of the first button pin
const int buttonPin2 = 3;   // the number of the second button pin
const int buttonPin3 = 4;   // the number of the third button pin
const int ledPin1 = 11;      // the number of the first LED pin 
const int ledPin2 = 9;      // the number of the second LED pin
const int ledPin3 = 10;     // the number of the third LED pin
const int photoPin = A0;    // the pin where the photoresistor is connected
 
int buttonState1 = 0;       // variable for reading the first button status
int buttonState2 = 0;       // variable for reading the second button status
int buttonState3 = 0;       // variable for reading the third button status
int ledBrightness = 0;      // variable for LED brightness based on photoresistor
 
void setup() {
  pinMode(buttonPin1, INPUT);  // initialize the first button pin as an input
  pinMode(buttonPin2, INPUT);  // initialize the second button pin as an input
  pinMode(buttonPin3, INPUT);  // initialize the third button pin as an input
  pinMode(ledPin1, OUTPUT);    // initialize the first LED pin as an output
  pinMode(ledPin2, OUTPUT);    // initialize the second LED pin as an output
  pinMode(ledPin3, OUTPUT);    // initialize the third LED pin as an output
  Serial.begin(9600);          // begin serial communication for debugging
}
 
void loop() {
  // read the state of the pushbutton values:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
 
  // read the photoresistor value and map it to LED brightness:
  int sensorValue = analogRead(photoPin);
  ledBrightness = map(sensorValue, 0, 1023, 0, 255);
 
  // check if the pushbuttons are pressed. If they are, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    analogWrite(ledPin1, ledBrightness);  // adjust LED brightness based on light level
  } else {
    analogWrite(ledPin1, 0);   // turn LED off
  }
 
  if (buttonState2 == HIGH) {
    analogWrite(ledPin2, ledBrightness);  // adjust LED brightness based on light level
  } else {
    analogWrite(ledPin2, 0);   // turn LED off
  }
 
  if (buttonState3 == HIGH) {
    analogWrite(ledPin3, ledBrightness);  // adjust LED brightness based on light level
  } else {
    analogWrite(ledPin3, 0);   // turn LED off
  }
 
  // print the sensor values to the serial monitor for debugging
  Serial.print("Light level: ");
  Serial.println(sensorValue);
  Serial.print("LED brightness: ");
  Serial.println(ledBrightness);
 
  delay(100);  // wait for a short period before repeating the loop
}