const int photoPin1 = A0;     // Pin for the first photoresistor
const int photoPin2 = A1;     // Pin for the second photoresistor
const int ledPin1 = 8;        // Pin for the first LED
const int ledPin2 = 9;        // Pin for the second LED
const int buttonPin1 = 2;     // Pin for the first button
const int buttonPin2 = 3;     // Pin for the second button
const int lightThreshold = 500;  // Light threshold for LED activation

int lightLevel1 = 0;          // Variable for the first photoresistor reading
int lightLevel2 = 0;          // Variable for the second photoresistor reading
int buttonState1 = 0;         // Variable for the first button state
int buttonState2 = 0;         // Variable for the second button state

void setup() {
  pinMode(ledPin1, OUTPUT);     // Initialize the first LED pin as an output
  pinMode(ledPin2, OUTPUT);     // Initialize the second LED pin as an output
  pinMode(buttonPin1, INPUT);   // Initialize the first button pin as an input
  pinMode(buttonPin2, INPUT);   // Initialize the second button pin as an input
  Serial.begin(9600);           // Start serial communication for debugging
}

void loop() {
  // Read the light levels from the photoresistors
  lightLevel1 = analogRead(photoPin1);
  lightLevel2 = analogRead(photoPin2);

  // Read the states of the buttons
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // Print the light levels for debugging
  Serial.print("Light level 1: ");
  Serial.println(lightLevel1);
  Serial.print("Light level 2: ");
  Serial.println(lightLevel2);

  // Control the first LED based on the photoresistor and button
  if (lightLevel1 < lightThreshold || buttonState1 == HIGH) {
    digitalWrite(ledPin1, HIGH);  // Turn on the first LED if light is below threshold or button is pressed
  } else {
    digitalWrite(ledPin1, LOW);   // Turn off the LED if light is above threshold and button isn't pressed
  }

  // Control the second LED based on the second photoresistor and button
  if (lightLevel2 < lightThreshold || buttonState2 == HIGH) {
    digitalWrite(ledPin2, HIGH);  // Turn on the second LED if light is below threshold or button is pressed
  } else {
    digitalWrite(ledPin2, LOW);   // Turn off the LED if light is above threshold and button isn't pressed
  }

  delay(100);  // Short delay to stabilize readings
}