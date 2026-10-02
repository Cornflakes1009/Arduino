const int buttonPin1 = 2;  // Button 1 is connected to pin 2
const int buttonPin2 = 3;  // Button 2 is connected to pin 3
const int ledPin1 = 8;     // LED 1 is connected to pin 8
const int ledPin2 = 9;     // LED 2 is connected to pin 9

int buttonState1 = 0;      // Variable to hold the state of button 1
int lastButtonState1 = 0;  // Previous state of button 1
int buttonState2 = 0;      // Variable to hold the state of button 2
int lastButtonState2 = 0;  // Previous state of button 2
int ledState1 = LOW;       // Current state of LED 1 (initially off)
int ledState2 = LOW;       // Current state of LED 2 (initially off)

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // ----- Button 1 -----
  // Read the state of button 1
  buttonState1 = digitalRead(buttonPin1);

  // Toggle LED 1 on/off when button 1 is pressed
  if (buttonState1 != lastButtonState1) {
    if (buttonState1 == HIGH) {
      ledState1 = !ledState1;            // Toggle LED state
      digitalWrite(ledPin1, ledState1);  // Set LED state
    }
    delay(50);  // Debounce delay
  }
  lastButtonState1 = buttonState1;  // Save the current state for next iteration


  // ----- Button 2 -----
  // Read the state of button 2
  buttonState2 = digitalRead(buttonPin2);

  // Toggle LED 2 on/off when button 2 is pressed
  if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
      ledState2 = !ledState2;            // Toggle LED state
      digitalWrite(ledPin2, ledState2);  // Set LED state
    }
    delay(50);  // Debounce delay
  }
  lastButtonState2 = buttonState2;  // Save the current state for next iteration
}