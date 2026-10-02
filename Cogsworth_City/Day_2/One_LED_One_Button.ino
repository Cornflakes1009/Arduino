// black - ground rail > GND
// resistor 1 - ground rail > a10
// red - a11 > pin 13
// orange - 5v > i28 (button pin)
// yellow - c26 > pin 3
// resistor 2 - ground rail > a26
// button top left next to yellow. bottom right next to orange
// LED anode is row 11, cathod is row 10
// _________
// pin 3 is data connection
// 


const int buttonPin = 3;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin
int buttonState = 0;      // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);    // initialize the LED pin as an output
  pinMode(buttonPin, INPUT);  // initialize the pushbutton pin as an input
}

void loop() {
  buttonState = digitalRead(buttonPin);  // read the state of the pushbutton value
  if (buttonState == HIGH) {             // check if the pushbutton is pressed
    digitalWrite(ledPin, HIGH);          // turn LED on
  } else {
    digitalWrite(ledPin, LOW);  // turn LED off
  }
}
