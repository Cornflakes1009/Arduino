const int ledPin = 8;       // Pin for the LED
const int ledPinDash = 9;       // Pin for the LED
const int buttonPin = 2;    // Pin for the button
int buttonState = 0;        // Variable to store the current button state
int lastButtonState = 0;    // Variable to store the last button state
unsigned long pressStartTime = 0; // Time when the button is pressed
unsigned long pressEndTime = 0;   // Time when the button is released
const int shortPressTime = 200;  // Threshold for a short press (dot)
const int longPressTime = 550;   // Threshold for a long press (dash)
 
void setup() {
  pinMode(ledPin, OUTPUT);   // Initialize the LED as output
  pinMode(ledPinDash, OUTPUT);   // Initialize the LED as output
  pinMode(buttonPin, INPUT); // Initialize the button as input
  Serial.begin(9600);        // Start serial communication for debugging
}
 
void loop() {
  // Read the button state
  buttonState = digitalRead(buttonPin);
 
  // If button is pressed
  if (buttonState == HIGH && lastButtonState == LOW) {
    pressStartTime = millis();  // Record the time when the button was pressed
  }
 
  // If button is released
  if (buttonState == LOW && lastButtonState == HIGH) {
    pressEndTime = millis();  // Record the time when the button was released
    long pressDuration = pressEndTime - pressStartTime;
    Serial.print(pressDuration);
 
    // If it's a short press (dot)
    if (pressDuration < shortPressTime) {
      sendDot();
    }
    // If it's a long press (dash)
    else if (pressDuration >= shortPressTime && pressDuration < longPressTime) {
      sendDash();
    }
  }
  lastButtonState = buttonState;  // Update the last button state
  delay(50);
 
}
 
// Function to send a dot (short flash)
void sendDot() {
  digitalWrite(ledPin, HIGH);  // Turn on LED
  delay(200);                  // LED on for 200ms
  digitalWrite(ledPin, LOW);   // Turn off LED
  delay(200);                  // Small delay between signals
  Serial.println(" - Dot");       // Print "Dot" to the serial monitor
}
 
// Function to send a dash (long flash)
void sendDash() {
  digitalWrite(ledPinDash, HIGH);  // Turn on LED
  delay(200);                  // LED on for 500ms
  digitalWrite(ledPinDash, LOW);   // Turn off LED
  delay(200);                  // Small delay between signals
  Serial.println(" - Dash");      // Print "Dash" to the serial monitor
}