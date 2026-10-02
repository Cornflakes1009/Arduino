// 3 simple circuits
// black on ground rail
// 3 resistors from ground rail to cathod on LEDs
// 3 jumpers from another on LED to pins 8, 9, 10

const int ledPin1 = 8;   // the number of the first LED pin
const int ledPin2 = 9;   // the number of the second LED pin
const int ledPin3 = 10;  // the number of the third LED pin

void setup() {
  pinMode(ledPin1, OUTPUT);  // initialize the first LED pin as an output
  pinMode(ledPin2, OUTPUT);  // initialize the second LED pin as an output
  pinMode(ledPin3, OUTPUT);  // initialize the third LED pin as an output
}

void loop() {
  digitalWrite(ledPin1, HIGH);  // turn the first LED on
  delay(75);                   // wait for half a second
  digitalWrite(ledPin1, LOW);   // turn the first LED off

  digitalWrite(ledPin2, HIGH);  // turn the second LED on
  delay(75);                   // wait for half a second
  digitalWrite(ledPin2, LOW);   // turn the second LED off

  digitalWrite(ledPin3, HIGH);  // turn the third LED on
  delay(75);                   // wait for half a second
  digitalWrite(ledPin3, LOW);   // turn the third LED off
}
