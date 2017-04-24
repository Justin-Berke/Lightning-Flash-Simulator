/*  Lightning Flash Simulator
*/

int pinLED = 13;        // Set onboard LED pin address

int flashDelay = 1000;  // Set delay between flash events


void setup() {
  pinMode(pinLED, OUTPUT);  // Set pin as output
}

int stormRandomNumber(int lowBound, int highBound) {
  // Placeholder function to return flash paramaters
  return random(lowBound, highBound);
}

void flash() {
  // Grab a random number of flashes to blink
  int myValue = stormRandomNumber(0, 5);

  // Loop through a randomly generated number of flashes
  for (int x = 0; x < myValue; x++) {
    // Flash
    digitalWrite(pinLED, HIGH); // Illuminate
    delay(10);                  // Very short "on" state
    digitalWrite(pinLED, LOW);  // Turn off
    delay(200);                 // Pause before next blink iteration
  }
}

void loop() {
  // Call a flash request
  flash();

  // Pause between flashes
  delay(flashDelay);
}
